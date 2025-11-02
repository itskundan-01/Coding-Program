#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
#include <utility>
using namespace std;

// Structure to represent a coordinate point on the grid
struct Point {
    int xCoord, yCoord;
    bool operator==(const Point &other) const { 
        return (xCoord == other.xCoord) && (yCoord == other.yCoord); 
    }
};

// Hash function for Point structure
struct PointHasher {
    size_t operator()(Point const &point) const {
        return (uint64_t(uint32_t(point.xCoord)) << 32) ^ uint32_t(point.yCoord);
    }
};

// Structure to represent a point with slider index
struct SlidePosition {
    int xCoord, yCoord, sliderIdx;
    bool operator==(const SlidePosition &other) const { 
        return (xCoord == other.xCoord) && (yCoord == other.yCoord) && (sliderIdx == other.sliderIdx); 
    }
};

// Hash function for SlidePosition structure
struct SlidePositionHasher {
    size_t operator()(SlidePosition const &slidePos) const {
        uint64_t hashValue = slidePos.xCoord;
        hashValue = (hashValue << 21) ^ slidePos.yCoord;
        hashValue = (hashValue << 21) ^ slidePos.sliderIdx;
        return size_t(hashValue);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read all input values into a vector
    vector<long long> inputData;
    long long inputValue;
    while (cin >> inputValue) {
        inputData.push_back(inputValue);
    }
    
    // Parse input data
    int dataIndex = 0;
    int numSliders = static_cast<int>(inputData[dataIndex]);
    ++dataIndex;
    
    // Store slider coordinates
    vector<array<int,4>> sliderCoords(numSliders);
    int sliderCount = 0;
    while (sliderCount < numSliders) {
        sliderCoords[sliderCount][0] = static_cast<int>(inputData[dataIndex]);
        ++dataIndex;
        sliderCoords[sliderCount][1] = static_cast<int>(inputData[dataIndex]);
        ++dataIndex;
        sliderCoords[sliderCount][2] = static_cast<int>(inputData[dataIndex]);
        ++dataIndex;
        sliderCoords[sliderCount][3] = static_cast<int>(inputData[dataIndex]);
        ++dataIndex;
        ++sliderCount;
    }
    
    // Ball starting position and energy
    int ballStartX = static_cast<int>(inputData[dataIndex]);
    ++dataIndex;
    int ballStartY = static_cast<int>(inputData[dataIndex]);
    ++dataIndex;
    int remainingEnergy = static_cast<int>(inputData[dataIndex]);

    // Map to store which sliders exist at each grid point
    unordered_map<Point, vector<int>, PointHasher> gridSliders;
    // Map to store next position for each slider at each point
    unordered_map<SlidePosition, pair<int,int>, SlidePositionHasher> nextPosition;

    // Process each slider to build the grid maps
    int currentSlider = 0;
    while (currentSlider < numSliders) {
        int startX = sliderCoords[currentSlider][0];
        int startY = sliderCoords[currentSlider][1];
        int endX = sliderCoords[currentSlider][2];
        int endY = sliderCoords[currentSlider][3];
        
        // Calculate direction of movement
        int deltaX;
        if (endX > startX) {
            deltaX = 1;
        } else {
            deltaX = -1;
        }
        
        int deltaY;
        if (endY > startY) {
            deltaY = 1;
        } else {
            deltaY = -1;
        }
        
        int sliderLength = abs(endX - startX);
        
        // Handle downward sloping slider
        if (deltaY == -1) {
            int step = 0;
            while (step < sliderLength) {
                int currentX = startX + deltaX * step;
                int currentY = startY - step;
                gridSliders[{currentX, currentY}].push_back(currentSlider);
                nextPosition[{currentX, currentY, currentSlider}] = {currentX + deltaX, currentY - 1};
                ++step;
            }
            gridSliders[{endX, endY}].push_back(currentSlider);
        } 
        // Handle upward sloping slider
        else {
            int step = 0;
            while (step < sliderLength) {
                int currentX = endX - deltaX * step;
                int currentY = endY - step;
                gridSliders[{currentX, currentY}].push_back(currentSlider);
                nextPosition[{currentX, currentY, currentSlider}] = {currentX - deltaX, currentY - 1};
                ++step;
            }
            gridSliders[{startX, startY}].push_back(currentSlider);
        }
        ++currentSlider;
    }

    // Lambda function to simulate gravity fall
    auto applyGravity = [&](int posX, int posY) -> pair<int,int> {
        int checkY = posY - 1;
        while (checkY >= 0) {
            auto foundSlider = gridSliders.find({posX, checkY});
            if (foundSlider != gridSliders.end()) {
                return {posX, checkY};
            }
            --checkY;
        }
        return {posX, 0};
    };

    // Initialize ball position
    int ballX = ballStartX;
    int ballY = ballStartY;
    
    // Check if starting position has a slider, if not apply gravity
    auto initialCheck = gridSliders.find({ballX, ballY});
    if (initialCheck == gridSliders.end()) {
        auto fallenPos = applyGravity(ballX, ballY);
        ballX = fallenPos.first;
        ballY = fallenPos.second;
    }

    // Main simulation loop
    bool continueSimulation = true;
    while (continueSimulation) {
        // Check if ball reached ground
        if (ballY == 0) {
            continueSimulation = false;
            break;
        }
        
        // Check if current position has any sliders
        auto currentPosCheck = gridSliders.find({ballX, ballY});
        
        // No slider at current position - apply gravity
        if (currentPosCheck == gridSliders.end()) {
            auto newPos = applyGravity(ballX, ballY);
            ballX = newPos.first;
            ballY = newPos.second;
            continue;
        }
        
        // Get list of sliders at current position
        auto &sliderList = currentPosCheck->second;
        
        // Single slider at current position
        if (sliderList.size() == 1) {
            int sliderIndex = sliderList[0];
            auto nextPosSearch = nextPosition.find({ballX, ballY, sliderIndex});
            
            // No next position available - apply gravity
            if (nextPosSearch == nextPosition.end()) {
                auto newPos = applyGravity(ballX, ballY);
                ballX = newPos.first;
                ballY = newPos.second;
                continue;
            }
            
            // Out of energy - stop
            if (remainingEnergy == 0) {
                continueSimulation = false;
                break;
            }
            
            // Move to next position on slider
            --remainingEnergy;
            ballX = nextPosSearch->second.first;
            ballY = nextPosSearch->second.second;
        } 
        // Multiple sliders at current position - stuck scenario
        else {
            long long unlockCost = 1LL * ballX * ballY;
            
            // Find available next positions
            vector<pair<int,pair<int,int>>> availableMoves;
            availableMoves.reserve(sliderList.size());
            
            for (int sliderIdx : sliderList) {
                auto moveSearch = nextPosition.find({ballX, ballY, sliderIdx});
                if (moveSearch != nextPosition.end()) {
                    availableMoves.push_back({sliderIdx, moveSearch->second});
                }
            }
            
            // Not enough energy to unlock - check if any moves available
            if (static_cast<long long>(remainingEnergy) <= unlockCost) {
                if (availableMoves.empty()) {
                    auto newPos = applyGravity(ballX, ballY);
                    ballX = newPos.first;
                    ballY = newPos.second;
                    continue;
                }
                continueSimulation = false;
                break;
            }
            
            // Spend energy to unlock
            remainingEnergy -= static_cast<int>(unlockCost);
            
            // No moves available after unlocking - apply gravity
            if (availableMoves.empty()) {
                auto newPos = applyGravity(ballX, ballY);
                ballX = newPos.first;
                ballY = newPos.second;
                continue;
            }
            
            // Choose the move with highest Y coordinate
            int bestX = 0;
            int bestY = -1;
            for (auto &moveOption : availableMoves) {
                int nextX = moveOption.second.first;
                int nextY = moveOption.second.second;
                if (nextY > bestY) {
                    bestY = nextY;
                    bestX = nextX;
                }
            }
            
            // Out of energy - stop
            if (remainingEnergy == 0) {
                continueSimulation = false;
                break;
            }
            
            // Move to best position
            --remainingEnergy;
            ballX = bestX;
            ballY = bestY;
        }
    }

    cout << ballX << " " << ballY << endl;
    return 0;
}