// #ifndef CODEGEN_H
// #define CODEGEN_H

// #include <iostream>
// #include <memory>
// #include <string>
// #include "ast.h"

// // ✅ Function to generate C++ code from AST
// std::string generateCode(std::shared_ptr<ASTNode> root);

// // ✅ Sorting Function (Ensure it matches codegen.cpp)
// std::string createSortingProgram(const std::string &algorithm);

// // ✅ Math-related functions
// std::string createFibonacciProgram(const std::string &number);
// std::string createFactorialProgram(const std::string &number);
// std::string createPrimeProgram(const std::string &number);
// std::string createArmstrongProgram(const std::string &number);

// // ✅ Predefined Programs
// std::string createHelloWorldProgram();
// std::string createBasicMathProgram();
// std::string createFileHandlingProgram();
// std::string createMatrixMultiplicationProgram();
// extern std::string generateArithmeticCode(const std::string&, int, int);
// std::string generateCodeForNode(ASTNode *node);

// #endif // CODEGEN_H







#ifndef CODEGEN_H
#define CODEGEN_H

#include <iostream>
#include <memory>
#include <string>
#include "ast.h"

//  Function to generate C++ code from AST
std::string generateCode(std::shared_ptr<ASTNode> root);

//  Sorting Functions
std::string createSortingProgram(const std::string &algorithm);

//  Math-related Functions
std::string createFibonacciProgram(const std::string &number);
std::string createFactorialProgram(const std::string &number);
std::string createPrimeProgram(const std::string &number);
std::string createArmstrongProgram(const std::string &number);

//  Predefined Programs
std::string createHelloWorldProgram();
std::string createBasicMathProgram();
std::string createFileHandlingProgram();
std::string createMatrixMultiplicationProgram();

// Arithmetic Code Generation
std::string generateArithmeticCode(const std::string &operation, int num1, int num2);

//  Node Code Generation
std::string generateCodeForNode(std::shared_ptr<ASTNode> node);

#endif // CODEGEN_H
