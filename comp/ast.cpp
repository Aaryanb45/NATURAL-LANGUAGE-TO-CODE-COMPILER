// #include "ast.h"
// #include "codegen.h"
// #include <iostream>
// #include <memory>
// #include <string>

// std::shared_ptr<ASTNode> createAST(const ParsedInput& input) {
//     std::cout << "Creating AST for action: " << input.action << std::endl;

//     if (input.action == "hello_world") {
//         return std::make_shared<ASTNode>("Function", createHelloWorldProgram());
//     }
//     if (input.action == "basic_math") {
//         return std::make_shared<ASTNode>("Function", createBasicMathProgram());
//     }
//     if (input.action == "file_handling") {
//         return std::make_shared<ASTNode>("Function", createFileHandlingProgram());
//     }
//     if (input.action == "matrix_multiplication") {
//         return std::make_shared<ASTNode>("Function", createMatrixMultiplicationProgram());
//     }
//     if (input.action == "sorting") {
//         return std::make_shared<ASTNode>("Function", createSortingProgram(input.params.at("algorithm")));
//     }
//     if (input.action == "fibonacci") {
//         return std::make_shared<ASTNode>("Function", createFibonacciProgram(input.params.at("code")));
//     }
//     if (input.action == "factorial") {
//         return std::make_shared<ASTNode>("Function", createFactorialProgram(input.params.at("code")));
//     }
//     if (input.action == "prime") {
//         return std::make_shared<ASTNode>("Function", createPrimeProgram(input.params.at("code")));
//     }
//     if (input.action == "armstrong") {
//         return std::make_shared<ASTNode>("Function", createArmstrongProgram(input.params.at("code")));
//     }

//     if (input.action == "arithmetic") {
//         if (input.params.find("operation") == input.params.end() ||
//             input.params.find("num1") == input.params.end() ||
//             input.params.find("num2") == input.params.end()) {
//             std::cerr << "ERROR: Missing parameters for arithmetic operation.\n";
//             return nullptr;
//         }
//         std::string operation = input.params.at("operation");
//         int num1 = std::stoi(input.params.at("num1"));
//         int num2 = std::stoi(input.params.at("num2"));
//         return std::make_shared<ASTNode>("Function", generateArithmeticCode(operation, num1, num2));
//     }

//     std::cerr << "ERROR: Could not create AST for action: " << input.action << std::endl;
//     return nullptr;
// }








#include "ast.h"
#include "codegen.h"
#include <iostream>
#include <memory>
#include <string>

// Helper function to retrieve a required parameter
std::string getParamOrError(const ParsedInput& input, const std::string& key) {
    if (input.params.find(key) == input.params.end()) {
        std::cerr << "ERROR: Missing '" << key << "' parameter for " << input.action << ".\n";
        return "";
    }
    return input.params.at(key);
}

//  Function to print the parse tree structure
void printParseTree(const ParsedInput& input) {
    std::cout << "\n Parse Tree Structure \n";
    std::cout << "Action: " << input.action << std::endl;
    for (const auto& param : input.params) {
        std::cout << "  ├── " << param.first << ": " << param.second << std::endl;
    }
    std::cout << "-----------------------------\n";
}

//  Function to print the AST structure
void printAST(const std::shared_ptr<ASTNode>& node, int depth = 0) {
    if (!node) return;
    
    // Indentation for tree visualization
    std::string indent(depth * 4, ' ');
    std::cout << indent << " Node Type: " << node->type << std::endl;
    
    if (!node->value.empty()) {
        std::cout << indent << "  └── Value: (Code Snippet)\n";
        std::cout << indent << "      " << node->value.substr(0, 50) << "..." << std::endl; // Limiting preview
    }

    for (const auto& child : node->children) {
        printAST(child, depth + 1);
    }
}

//  Modified createAST function to include Parse Tree and AST printing
std::shared_ptr<ASTNode> createAST(const ParsedInput& input) {
    printParseTree(input); //  Print the Parse Tree first

    std::cout << "Creating AST for action: " << input.action << std::endl;

    std::shared_ptr<ASTNode> root = nullptr;

    if (input.action == "hello_world") {
        root = std::make_shared<ASTNode>("Function", createHelloWorldProgram());
    }
    else if (input.action == "basic_math") {
        root = std::make_shared<ASTNode>("Function", createBasicMathProgram());
    }
    else if (input.action == "file_handling") {
        root = std::make_shared<ASTNode>("Function", createFileHandlingProgram());
    }
    else if (input.action == "matrix_multiplication") {
        root = std::make_shared<ASTNode>("Function", createMatrixMultiplicationProgram());
    }
    else if (input.action == "sorting") {
        std::string algorithm = getParamOrError(input, "algorithm");
        if (!algorithm.empty()) {
            root = std::make_shared<ASTNode>("Function", createSortingProgram(algorithm));
        }
    }
    else if (input.action == "fibonacci") {
        std::string code = getParamOrError(input, "code");
        if (!code.empty()) {
            root = std::make_shared<ASTNode>("Function", createFibonacciProgram(code));
        }
    }
    else if (input.action == "factorial") {
        std::string code = getParamOrError(input, "code");
        if (!code.empty()) {
            root = std::make_shared<ASTNode>("Function", createFactorialProgram(code));
        }
    }
    else if (input.action == "prime") {
        std::string code = getParamOrError(input, "code");
        if (!code.empty()) {
            root = std::make_shared<ASTNode>("Function", createPrimeProgram(code));
        }
    }
    else if (input.action == "armstrong") {
        std::string code = getParamOrError(input, "code");
        if (!code.empty()) {
            root = std::make_shared<ASTNode>("Function", createArmstrongProgram(code));
        }
    }
    else if (input.action == "arithmetic") {
        std::string operation = getParamOrError(input, "operation");
        std::string num1Str = getParamOrError(input, "num1");
        std::string num2Str = getParamOrError(input, "num2");
        if (!operation.empty() && !num1Str.empty() && !num2Str.empty()) {
            int num1 = std::stoi(num1Str);
            int num2 = std::stoi(num2Str);
            root = std::make_shared<ASTNode>("Function", generateArithmeticCode(operation, num1, num2));
        }
    }
    
    if (!root) {
        std::cerr << "ERROR: AST generation failed for action: " << input.action << std::endl;
        return nullptr;
    }

    std::cout << "\n AST Tree Structure 🛠️\n";
    printAST(root); //  Print the AST before returning

    return root;
}
