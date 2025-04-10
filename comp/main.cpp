// #include <iostream>
// #include "parser.h"
// #include "ast.h"
// #include "codegen.h"

// int main() {
//     std::string userInstruction = getUserInput();
//     ParsedInput parsedInput = parseInput(userInstruction);

//     if (parsedInput.action.empty()) {
//         std::cerr << "Error: Could not parse input." << std::endl;
//         return 1;
//     }

//     std::shared_ptr<ASTNode> ast = createAST(parsedInput);
//     if (!ast) {
//         std::cerr << "Error: Could not generate AST." << std::endl;
//         return 1;
//     }

//     std::string generatedCode = generateCode(ast);
//     std::cout << "\nGenerated C++ Code:\n" << generatedCode << std::endl;

//     return 0;
// }










#include <iostream>
#include <string>
#include "parser.h"
#include "ast.h"
#include "codegen.h"

int main() {
    std::cout << "Enter your instruction: ";
    
    std::string userInstruction = getUserInput(); //  Use function from parser.h

    if (userInstruction.empty()) {
        std::cerr << " Error: No input provided.\n";
        return 1;
    }

    //  Parse input into structured data
    ParsedInput parsedInput = parseInput(userInstruction);
    if (parsedInput.action.empty()) {
        std::cerr << " Error: Could not parse input. Please try again.\n";
        return 1;
    }

    std::cout << " Parsed Action: " << parsedInput.action << std::endl;

    //  Generate AST
    std::shared_ptr<ASTNode> ast = createAST(parsedInput);
    if (!ast) {
        std::cerr << " Error: AST generation failed for action: " << parsedInput.action << std::endl;
        return 1;
    }

    std::cout << "\n AST Structure:\n";
    ast->print();  //  Print AST Structure

    std::cout << "\nGenerating C++ Code...\n";
    std::string generatedCode = generateCode(ast);

    if (generatedCode.empty()) {
        std::cerr << " Error: Code generation failed.\n";
        return 1;
    }

    std::cout << "\n Generated C++ Code:\n" << generatedCode << std::endl;

    return 0;
}
