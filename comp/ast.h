// #ifndef AST_H
// #define AST_H

// #include <string>
// #include <memory>
// #include "parser.h"

// // AST Node Structure
// struct ASTNode {
//     std::string type;
//     std::string value;
//     std::shared_ptr<ASTNode> left;
//     std::shared_ptr<ASTNode> right;

//     // Constructor
//     ASTNode(const std::string& t, const std::string& v)
//         : type(t), value(v), left(nullptr), right(nullptr) {}
// };

// // Function to create an AST from parsed input
// std::shared_ptr<ASTNode> createAST(const ParsedInput& input);

// #endif // AST_H






#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "parser.h"

//  Improved AST Node Structure
struct ASTNode {
    std::string type;  // Type of the node (Function, Statement, Expression, etc.)
    std::string value; // Actual value or code snippet
    std::vector<std::shared_ptr<ASTNode>> children; //  Support multiple children

    // Constructor
    ASTNode(const std::string& t, const std::string& v) : type(t), value(v) {}

    //  Function to print AST structure
    void print(int depth = 0) const {
        std::string indent(depth * 4, ' '); // Indentation for readability
        std::cout << indent << " Node Type: " << type << std::endl;

        if (!value.empty()) {
            std::cout << indent << "  └── Value: " << value.substr(0, 50) << "..." << std::endl; // Limiting preview
        }

        for (const auto& child : children) {
            child->print(depth + 1); // Recursive call for nested nodes
        }
    }
};

//  Function to create an AST from parsed input
std::shared_ptr<ASTNode> createAST(const ParsedInput& input);

#endif // AST_H

