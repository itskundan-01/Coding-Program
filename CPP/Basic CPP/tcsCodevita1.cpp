#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
 
int main() { 
    // Fast I/O for better performance
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
 
    // Read grid dimensions
    int N, M; 
    cin >> N >> M; 
 
    // Initialize and read the grid
    vector<string> grid(N); 
    int row = 0;
    while (row < N) { 
        grid[row].resize(M); 
        int col = 0;
        while (col < M) { 
            cin >> grid[row][col]; 
            ++col;
        } 
        ++row;
    } 
 
    // Identify horizontal and vertical rod positions
    vector<int> h_rods, v_rods; 
    int i = 0;
    while (i < N) { 
        bool hasGap = false;
        int j = 0;
        while (j < M) {
            if (grid[i][j] == '.') {
                hasGap = true;
                break;
            }
            ++j;
        }
        if (!hasGap) h_rods.push_back(i); 
        ++i;
    } 
    int col = 0;
    while (col < M) { 
        bool isFull = true; 
        int row = 0;
        while (row < N) {
            if (grid[row][col] == '.') {
                isFull = false;
                break;
            }
            row++;
        }
        if (isFull) v_rods.push_back(col); 
        col++;
    } 
 
    vector<vector<bool>> crossPoint(N, vector<bool>(M, false)); 
    for (int c : v_rods) { 
        int r = 0;
        while (r < N) { 
            int leftCol = c - 1, rightCol = c + 1; 
            bool hasLeftCable = (leftCol >= 0) && (grid[r][leftCol] == 'C');
            bool hasRightCable = (rightCol < M) && (grid[r][rightCol] == 'C');
            if (hasLeftCable && hasRightCable) 
                crossPoint[r][c] = true; 
            r++;
        } 
    } 
    for (int r : h_rods) { 
        int c = 0;
        while (c < M) { 
            int upRow = r - 1, downRow = r + 1; 
            bool hasUpCable = (upRow >= 0) && (grid[upRow][c] == 'C');
            bool hasDownCable = (downRow < N) && (grid[downRow][c] == 'C');
            if (hasUpCable && hasDownCable) 
                crossPoint[r][c] = true; 
            c++;
        } 
    } 
 
    vector<vector<bool>> cablePath(N, vector<bool>(M, false)); 
    i = 0;
    while (i < N) {
        int j = 0;
        while (j < M) {
            if (grid[i][j] == 'C') {
                cablePath[i][j] = true;
            } else if (crossPoint[i][j]) {
                cablePath[i][j] = true;
            }
            j++;
        }
        i++;
    } 
 
    vector<vector<int>> adjacency(N * M); 
    int deltaRow[4] = {-1, 0, 1, 0}; 
    int deltaCol[4] = {0, 1, 0, -1}; 
 
    i = 0;
    while (i < N) { 
        int j = 0;
        while (j < M) { 
            if (cablePath[i][j]) {
                int cellId = i * M + j; 
                int dir = 0;
                while (dir < 4) { 
                    int newR = i + deltaRow[dir], newC = j + deltaCol[dir]; 
                    bool validR = (newR >= 0) && (newR < N);
                    bool validC = (newC >= 0) && (newC < M);
                    if (validR && validC && cablePath[newR][newC]) 
                        adjacency[cellId].push_back(newR * M + newC); 
                    dir++;
                } 
            }
            j++;
        } 
        i++;
    } 
 
    int startPos = -1; 
    i = 0;
    while (i < N && startPos == -1) {
        int j = 0;
        while (j < M) {
            bool isCable = cablePath[i][j];
            bool isEndpoint = (adjacency[i * M + j].size() == 1);
            if (isCable && isEndpoint) { 
                startPos = i * M + j; 
                break; 
            }
            j++;
        }
        i++;
    } 
 
    vector<bool> isVisited(N * M, false); 
    vector<int> horizontalSum(N, 0), verticalSum(M, 0); 
 
    int currentPos = startPos, previousPos = -1; 
    isVisited[currentPos] = true; 
 
    while (true) { 
        int currentRow = currentPos / M, currentCol = currentPos % M; 
        int nextPos = -1; 
        for (int neighbor : adjacency[currentPos]) {
            bool notPrevious = (neighbor != previousPos);
            bool notVisited = !isVisited[neighbor];
            if (notPrevious && notVisited) { 
                nextPos = neighbor; 
                break; 
            }
        }
 
        bool isCrossing = crossPoint[currentRow][currentCol];
        bool hasPrevious = (previousPos != -1);
        if (isCrossing && hasPrevious) { 
            int prevRow = previousPos / M, prevCol = previousPos % M; 
            int signValue; 
            if (grid[currentRow][currentCol] == 'C') {
                signValue = 1;
            } else {
                signValue = -1;
            }
 
            bool sameRow = (prevRow == currentRow);
            if (sameRow) {
                int direction = (prevCol < currentCol) ? 1 : -1;
                verticalSum[currentCol] += direction * signValue; 
            } else {
                int direction = (prevRow < currentRow) ? 1 : -1;
                horizontalSum[currentRow] += direction * signValue; 
            }
        } 
 
        if (nextPos == -1) break; 
        previousPos = currentPos; 
        currentPos = nextPos; 
        isVisited[currentPos] = true; 
    } 
 
    long long result = 0; 
    for (int r : h_rods) {
        int contribution = abs(horizontalSum[r]) / 2;
        result += contribution;
    }
    for (int c : v_rods) {
        int contribution = abs(verticalSum[c]) / 2;
        result += contribution;
    }
 
    cout << result; 
    return 0; 
}