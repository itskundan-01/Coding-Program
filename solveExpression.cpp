#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <array>
#include <utility>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

// Function to divide LED display rows into blocks based on step size
vector<string> divideIntoBlocks(const vector<string> &displayRows, int stepSize)
{
    int maxWidth = 0;
    
    // Calculate maximum width across all rows
    for (auto &row : displayRows) {
        if (static_cast<int>(row.size()) > maxWidth) {
            maxWidth = static_cast<int>(row.size());
        }
    }

    // Normalize all rows to same width by padding with spaces
    vector<string> normalizedRows = displayRows;
    for (auto &row : normalizedRows) {
        if (static_cast<int>(row.size()) < maxWidth) {
            row += string(maxWidth - row.size(), ' ');
        }
    }

    // Minimum width check
    if (maxWidth < 3) {
        return {};
    }

    int totalBlocks = (maxWidth + (stepSize - 3)) / stepSize;
    vector<string> extractedBlocks;

    // Extract blocks from normalized rows
    int blockIndex = 0;
    while (blockIndex < totalBlocks) {
        int startPosition = blockIndex * stepSize;
        string blockData;
        
        int rowIndex = 0;
        while (rowIndex < 3) {
            string currentRow = normalizedRows[rowIndex];
            if (startPosition + 3 > static_cast<int>(currentRow.size())) {
                currentRow += string(startPosition + 3 - currentRow.size(), ' ');
            }
            blockData += currentRow.substr(startPosition, 3);
            ++rowIndex;
        }
        extractedBlocks.push_back(blockData);
        ++blockIndex;
    }
    return extractedBlocks;
}

// Function to identify and extract pattern blocks from display rows
vector<string> detectBlocks(const vector<string> &lines, int expected = -1)
{
    vector<string> blocksWithStep4 = divideIntoBlocks(lines, 4);
    vector<string> blocksWithStep3 = divideIntoBlocks(lines, 3);

    // If expected count is specified, return matching blocks
    if (expected > 0)
    {
        if (static_cast<int>(blocksWithStep4.size()) == expected) {
            return blocksWithStep4;
        }
        if (static_cast<int>(blocksWithStep3.size()) == expected) {
            return blocksWithStep3;
        }
    }

    // Lambda to count non-empty blocks
    auto countNonEmptyBlocks = [](const vector<string> &blockArray)
    {
        int nonEmptyCount = 0;
        for (auto &block : blockArray)
        {
            bool isEmpty = true;
            for (char ch : block) {
                if (ch != ' ') {
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) {
                ++nonEmptyCount;
            }
        }
        return nonEmptyCount;
    };

    // Return blocks with higher non-empty count
    if (countNonEmptyBlocks(blocksWithStep4) >= countNonEmptyBlocks(blocksWithStep3)) {
        return blocksWithStep4;
    } else {
        return blocksWithStep3;
    }
}

// Convert LED block pattern to binary string
string convertToBinaryString(const string &ledBlock)
{
    string binaryResult;
    for (char ch : ledBlock) {
        if (ch == ' ') {
            binaryResult += '0';
        } else {
            binaryResult += '1';
        }
    }
    return binaryResult;
}

// Create mapping between binary patterns and their corresponding symbols
map<string, string> createPatternMapping(const vector<string> &displayLines, const vector<string> &symbolList)
{
    auto extractedBlocks = detectBlocks(displayLines, static_cast<int>(symbolList.size()));
    map<string, string> binaryToSymbolMap;
    
    size_t symbolIndex = 0;
    size_t maxIndex = (extractedBlocks.size() < symbolList.size()) ? extractedBlocks.size() : symbolList.size();
    
    while (symbolIndex < maxIndex) {
        binaryToSymbolMap[convertToBinaryString(extractedBlocks[symbolIndex])] = symbolList[symbolIndex];
        ++symbolIndex;
    }
    return binaryToSymbolMap;
}

// Extract individual tokens (numbers and operators) from expression display
vector<string> extractTokens(const vector<string> &lines, const map<string, string> &allPatterns)
{
    auto extractedBlocks = detectBlocks(lines);
    vector<string> tokenList;
    string digitBuffer;

    for (auto &block : extractedBlocks)
    {
        string binaryPattern = convertToBinaryString(block);
        auto patternIterator = allPatterns.find(binaryPattern);

        if (patternIterator != allPatterns.end())
        {
            string symbolValue = patternIterator->second;
            
            // Check if symbol is a digit
            if (isdigit(symbolValue[0])) {
                digitBuffer += symbolValue;
            } else {
                // Symbol is an operator or bracket
                if (!digitBuffer.empty()) {
                    tokenList.push_back(digitBuffer);
                    digitBuffer.clear();
                }
                tokenList.push_back(symbolValue);
            }
        }
    }
    
    // Add any remaining digits in buffer
    if (!digitBuffer.empty()) {
        tokenList.push_back(digitBuffer);
    }
    return tokenList;
}

// Perform bitwise OR operation on two binary strings
string performBitwiseOR(const string &firstBinary, const string &secondBinary)
{
    int maxLength = (firstBinary.size() > secondBinary.size()) ? firstBinary.size() : secondBinary.size();
    string paddedFirst = string(maxLength - firstBinary.size(), '0') + firstBinary;
    string paddedSecond = string(maxLength - secondBinary.size(), '0') + secondBinary;
    string orResult;
    
    int bitIndex = 0;
    while (bitIndex < maxLength) {
        if (paddedFirst[bitIndex] == '1' || paddedSecond[bitIndex] == '1') {
            orResult += '1';
        } else {
            orResult += '0';
        }
        ++bitIndex;
    }
    return orResult;
}

// Perform bitwise AND operation on two binary strings
string performBitwiseAND(const string &firstBinary, const string &secondBinary)
{
    int maxLength = (firstBinary.size() > secondBinary.size()) ? firstBinary.size() : secondBinary.size();
    string paddedFirst = string(maxLength - firstBinary.size(), '0') + firstBinary;
    string paddedSecond = string(maxLength - secondBinary.size(), '0') + secondBinary;
    string andResult;
    
    int bitIndex = 0;
    while (bitIndex < maxLength) {
        if (paddedFirst[bitIndex] == '1' && paddedSecond[bitIndex] == '1') {
            andResult += '1';
        } else {
            andResult += '0';
        }
        ++bitIndex;
    }
    return andResult;
}

// Perform bitwise NOT operation on binary string
string performBitwiseNOT(const string &binaryInput)
{
    string notResult;
    for (char bit : binaryInput) {
        if (bit == '1') {
            notResult += '0';
        } else {
            notResult += '1';
        }
    }
    return notResult;
}

// Convert numeric string to binary representation using digit mappings
string convertNumberToBinary(const string &numberString, const map<string, string> &digitToBinaryMap)
{
    string binaryOutput;
    for (char digitChar : numberString)
    {
        string singleDigit(1, digitChar);
        auto mappingIterator = digitToBinaryMap.find(singleDigit);
        
        if (mappingIterator != digitToBinaryMap.end()) {
            binaryOutput += mappingIterator->second;
        } else {
            binaryOutput += string(9, '0');
        }
    }
    return binaryOutput;
}

// Convert binary string back to numeric string using reverse mappings
string convertBinaryToNumber(const string &binaryString, const map<string, string> &binaryToDigitMap)
{
    if (binaryString.empty()) {
        return "0";
    }
    
    string paddedBinary = binaryString;
    int extraBits = paddedBinary.size() % 9;
    
    // Pad to make length multiple of 9
    if (extraBits != 0) {
        paddedBinary = string(9 - extraBits, '0') + paddedBinary;
    }

    string numericResult;
    int chunkStart = 0;
    while (chunkStart < static_cast<int>(paddedBinary.size())) {
        string binaryChunk = paddedBinary.substr(chunkStart, 9);
        auto chunkIterator = binaryToDigitMap.find(binaryChunk);
        
        if (chunkIterator != binaryToDigitMap.end()) {
            numericResult += chunkIterator->second;
        } else {
            numericResult += "0";
        }
        chunkStart += 9;
    }

    // Remove leading zeros
    int firstNonZero = 0;
    while (firstNonZero + 1 < static_cast<int>(numericResult.size()) && numericResult[firstNonZero] == '0') {
        ++firstNonZero;
    }
    return numericResult.substr(firstNonZero);
}

// Evaluate the bitwise expression using stacks and operator precedence
string evaluateExpression(const vector<string> &tokenSequence, const map<string, string> &digitToBinaryMap)
{
    stack<string> valueStack;
    stack<string> operatorStack;

    // Lambda function to apply an operator to values in stack
    auto applyOperator = [&](const string &operatorSymbol)
    {
        if (operatorSymbol == "~")
        {
            // NOT operation requires one operand
            if (valueStack.empty()) {
                return;
            }
            string operand = valueStack.top();
            valueStack.pop();
            valueStack.push(performBitwiseNOT(operand));
        }
        else
        {
            // OR and AND operations require two operands
            if (valueStack.size() < 1) {
                return;
            }
            string secondOperand = valueStack.top();
            valueStack.pop();
            
            string firstOperand;
            if (valueStack.empty()) {
                firstOperand = string(9, '0');
            } else {
                firstOperand = valueStack.top();
                valueStack.pop();
            }
            
            if (operatorSymbol == "|") {
                valueStack.push(performBitwiseOR(firstOperand, secondOperand));
            } else {
                valueStack.push(performBitwiseAND(firstOperand, secondOperand));
            }
        }
    };

    // Lambda function to get operator precedence
    auto getOperatorPrecedence = [&](const string &operatorSymbol)
    {
        if (operatorSymbol == "~") {
            return 3;
        }
        if (operatorSymbol == "|") {
            return 2;
        }
        if (operatorSymbol == "&") {
            return 1;
        }
        return 0;
    };

    // Process each token in the expression
    for (auto &token : tokenSequence)
    {
        if (token == "(") {
            operatorStack.push(token);
        }
        else if (token == ")")
        {
            // Process operators until matching opening bracket
            while (!operatorStack.empty() && operatorStack.top() != "(")
            {
                applyOperator(operatorStack.top());
                operatorStack.pop();
            }
            if (!operatorStack.empty()) {
                operatorStack.pop(); // Remove opening bracket
            }
        }
        else if (token == "~" || token == "|" || token == "&")
        {
            // Apply operators with higher or equal precedence
            while (!operatorStack.empty() && operatorStack.top() != "(" && 
                   getOperatorPrecedence(operatorStack.top()) >= getOperatorPrecedence(token))
            {
                applyOperator(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(token);
        }
        else {
            // Token is a number - convert to binary and push
            valueStack.push(convertNumberToBinary(token, digitToBinaryMap));
        }
    }

    // Apply remaining operators
    while (!operatorStack.empty())
    {
        applyOperator(operatorStack.top());
        operatorStack.pop();
    }

    if (valueStack.empty()) {
        return "";
    } else {
        return valueStack.top();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read all 9 lines of input
    vector<string> allInputLines(9);
    int lineIndex = 0;
    while (lineIndex < 9) {
        getline(cin, allInputLines[lineIndex]);
        ++lineIndex;
    }

    // Split input into three parts: digits, operators, and expression
    vector<string> digitDisplayLines(allInputLines.begin(), allInputLines.begin() + 3);
    vector<string> operatorDisplayLines(allInputLines.begin() + 3, allInputLines.begin() + 6);
    vector<string> expressionDisplayLines(allInputLines.begin() + 6, allInputLines.end());

    // Define digit and operator symbols
    vector<string> digitSymbols = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<string> operatorSymbols = {"|", "&", "~", "(", ")"};

    // Create pattern mappings for digits and operators
    auto digitPatternMap = createPatternMapping(digitDisplayLines, digitSymbols);
    auto operatorPatternMap = createPatternMapping(operatorDisplayLines, operatorSymbols);

    // Combine all patterns into single map
    map<string, string> combinedPatternMap = digitPatternMap;
    combinedPatternMap.insert(operatorPatternMap.begin(), operatorPatternMap.end());

    // Create reverse mappings for conversion
    map<string, string> digitToBinaryMap;
    map<string, string> binaryToDigitMap;
    
    for (auto &patternPair : digitPatternMap)
    {
        binaryToDigitMap[patternPair.first] = patternPair.second;
        digitToBinaryMap[patternPair.second] = patternPair.first;
    }

    // Extract tokens from expression and evaluate
    auto expressionTokens = extractTokens(expressionDisplayLines, combinedPatternMap);
    string binaryResult = evaluateExpression(expressionTokens, digitToBinaryMap);
    cout << convertBinaryToNumber(binaryResult, binaryToDigitMap);
    return 0;
}