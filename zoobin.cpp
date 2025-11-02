#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read number of edges
    int totalEdges;
    cin >> totalEdges;
    
    // Store current and expected layouts
    vector<pair<int,int>> currentLayout(totalEdges);
    vector<pair<int,int>> expectedLayout(totalEdges);
    set<int> uniqueNodes;
    
    // Read current layout edges
    int edgeIndex = 0;
    while (edgeIndex < totalEdges) {
        cin >> currentLayout[edgeIndex].first >> currentLayout[edgeIndex].second;
        uniqueNodes.insert(currentLayout[edgeIndex].first);
        uniqueNodes.insert(currentLayout[edgeIndex].second);
        ++edgeIndex;
    }
    
    // Read expected layout edges
    edgeIndex = 0;
    while (edgeIndex < totalEdges) {
        cin >> expectedLayout[edgeIndex].first >> expectedLayout[edgeIndex].second;
        ++edgeIndex;
    }
    
    // Convert set of nodes to vector
    vector<int> nodeList(uniqueNodes.begin(), uniqueNodes.end());
    
    // Lambda function to normalize edge pairs (smaller node first) and sort
    auto normalizeAndSortEdges = [](vector<pair<int,int>> edgeList) {
        for (auto& [node1, node2] : edgeList) {
            if (node1 > node2) {
                swap(node1, node2);
            }
        }
        sort(edgeList.begin(), edgeList.end());
        return edgeList;
    };
    
    // Lambda function to convert edge list to string representation
    auto convertEdgesToString = [](const vector<pair<int,int>>& edgeList) {
        string representation;
        for (auto [firstNode, secondNode] : edgeList) {
            representation += to_string(firstNode) + "-" + to_string(secondNode) + ",";
        }
        return representation;
    };
    
    // Normalize both layouts
    vector<pair<int,int>> normalizedExpected = normalizeAndSortEdges(expectedLayout);
    string expectedString = convertEdgesToString(normalizedExpected);
    
    vector<pair<int,int>> normalizedCurrent = normalizeAndSortEdges(currentLayout);
    string currentString = convertEdgesToString(normalizedCurrent);
    
    // Check if already matching
    if (currentString == expectedString) {
        cout << 0;
        return 0;
    }
    
    // BFS to find minimum rotations
    map<string,int> visitedStates;
    queue<pair<vector<pair<int,int>>,int>> stateQueue;
    stateQueue.push({normalizedCurrent, 0});
    visitedStates[currentString] = 0;
    
    while (!stateQueue.empty()) {
        auto [currentEdges, rotationCount] = stateQueue.front();
        stateQueue.pop();
        
        // Build adjacency list for current state
        map<int,vector<int>> adjacencyList;
        for (auto [nodeA, nodeB] : currentEdges) {
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
        }
        
        // Find all cycles in the graph
        set<vector<int>> discoveredCycles;
        
        for (int startNode : nodeList) {
            // Recursive DFS function to find cycles
            function<void(int,int,vector<int>&,set<int>&)> findCyclesDFS = [&](int currentNode, int parentNode, vector<int>& pathNodes, set<int>& visitedInPath) {
                pathNodes.push_back(currentNode);
                visitedInPath.insert(currentNode);
                
                for (int neighborNode : adjacencyList[currentNode]) {
                    if (neighborNode == parentNode) {
                        continue;
                    }
                    
                    if (visitedInPath.count(neighborNode)) {
                        // Found a cycle
                        auto cycleStart = find(pathNodes.begin(), pathNodes.end(), neighborNode);
                        if (cycleStart != pathNodes.end()) {
                            vector<int> cycleNodes(cycleStart, pathNodes.end());
                            if (cycleNodes.size() >= 3) {
                                // Normalize cycle by rotating to start with minimum node
                                int minNodeIndex = min_element(cycleNodes.begin(), cycleNodes.end()) - cycleNodes.begin();
                                rotate(cycleNodes.begin(), cycleNodes.begin() + minNodeIndex, cycleNodes.end());
                                discoveredCycles.insert(cycleNodes);
                            }
                        }
                    } else if (pathNodes.size() < nodeList.size()) {
                        findCyclesDFS(neighborNode, currentNode, pathNodes, visitedInPath);
                    }
                }
                
                pathNodes.pop_back();
                visitedInPath.erase(currentNode);
            };
            
            vector<int> currentPath;
            set<int> currentVisited;
            findCyclesDFS(startNode, -1, currentPath, currentVisited);
        }
        
        // Try rotating each discovered cycle
        for (const auto& cycleNodes : discoveredCycles) {
            // Create node mapping for rotation
            map<int,int> nodeMapping;
            for (int node : nodeList) {
                nodeMapping[node] = node;
            }
            
            // Apply rotation to cycle nodes
            int cycleSize = cycleNodes.size();
            int cycleIndex = 0;
            while (cycleIndex < cycleSize) {
                nodeMapping[cycleNodes[cycleIndex]] = cycleNodes[(cycleIndex + 1) % cycleSize];
                ++cycleIndex;
            }
            
            // Create new edge list with rotated nodes
            vector<pair<int,int>> rotatedEdges;
            for (auto [edgeNode1, edgeNode2] : currentEdges) {
                rotatedEdges.push_back({nodeMapping[edgeNode1], nodeMapping[edgeNode2]});
            }
            
            // Normalize rotated edges
            rotatedEdges = normalizeAndSortEdges(rotatedEdges);
            string rotatedString = convertEdgesToString(rotatedEdges);
            
            // Check if we reached the expected layout
            if (rotatedString == expectedString) {
                cout << rotationCount + 1;
                return 0;
            }
            
            // Add new state to queue if not visited
            if (!visitedStates.count(rotatedString)) {
                visitedStates[rotatedString] = rotationCount + 1;
                stateQueue.push({rotatedEdges, rotationCount + 1});
            }
        }
    }
    
    cout << -1;
    return 0;
}