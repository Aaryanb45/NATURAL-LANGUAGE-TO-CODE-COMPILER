// #ifndef PARSER_H
// #define PARSER_H

// #include <string>
// #include <map>

// // Struct to hold parsed data
// struct ParsedInput {
//     std::string action;
//     std::map<std::string, std::string> params;
// };

// // Function prototypes
// std::string getUserInput();
// ParsedInput parseInput(const std::string& input);
// bool validateSyntax(const std::string& input);

// // **NEW FUNCTIONS**
// std::pair<std::string, std::string> parseVariables(const std::string &input);
// std::pair<std::string, std::string> parseLoops(const std::string &input);
// std::pair<std::string, std::string> parseConditionals(const std::string &input);
// std::pair<std::string, std::string> parseFunctions(const std::string &input);
// std::pair<std::string, std::string> parseOperators(const std::string &input);
// std::pair<std::string, std::pair<int, int>> parseArithmeticOperations(const std::string &input);

// #endif






#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <map>
#include <memory>
#include <vector>

//  Struct to hold parsed data
struct ParsedInput {
    std::string action;
    std::map<std::string, std::string> params;
};

//  TreeNode structure for Parser Tree and AST
struct TreeNode {
    std::string value;
    std::vector<std::shared_ptr<TreeNode>> children;
    
    TreeNode(const std::string& val) : value(val) {}
    
    void addChild(std::shared_ptr<TreeNode> child) {
        children.push_back(child);
    }
};

// Function prototypes
std::string getUserInput();
ParsedInput parseInput(const std::string& input);
bool validateSyntax(const std::string& input);

//  New Parsing Functions (Return TreeNode for Parser Tree)
std::pair<std::shared_ptr<TreeNode>, std::pair<std::string, std::string>> parseVariables(const std::string& input);
std::pair<std::shared_ptr<TreeNode>, std::pair<std::string, std::string>> parseLoops(const std::string& input);
std::pair<std::shared_ptr<TreeNode>, std::pair<std::string, std::string>> parseConditionals(const std::string& input);
std::pair<std::shared_ptr<TreeNode>, std::pair<std::string, std::string>> parseFunctions(const std::string& input);
std::pair<std::shared_ptr<TreeNode>, std::pair<std::string, std::pair<int, int>>> parseArithmeticOperations(const std::string& input);

// AST Generation
std::shared_ptr<TreeNode> convertToAST(const std::shared_ptr<TreeNode>& parserTree);

// Utility Functions
void printTree(const std::shared_ptr<TreeNode>& node, int depth = 0);

#endif // PARSER_H
