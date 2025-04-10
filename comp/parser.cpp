// #include "parser.h"
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <vector>
// #include <fstream>
// #include <cctype>

// // ✅ Get user input
// std::string getUserInput() {
//     std::string input;
//     std::cout << "Enter your instruction: ";
//     std::getline(std::cin, input);
//     return input;
// }

// // ✅ Normalize Input (Lowercase + Remove Extra Spaces)
// std::string normalizeInput(const std::string &input) {
//     std::string result = input;
//     std::transform(result.begin(), result.end(), result.begin(), ::tolower);
//     result.erase(std::unique(result.begin(), result.end(),
//               [](char a, char b) { return std::isspace(a) && std::isspace(b); }), result.end());
//     return result;
// }

// // ✅ Validate Syntax (Ensure input starts with a valid word or number)
// bool validateSyntax(const std::string &input) {
//     if (input.empty()) {
//         std::cerr << "ERROR: Input is empty!\n";
//         return false;
//     }
//     std::string trimmed = input;
//     trimmed.erase(0, trimmed.find_first_not_of(" "));

//     if (!std::isalpha(trimmed[0]) && !std::isdigit(trimmed[0])) { 
//         std::cerr << "ERROR: Input should start with a valid word or number!\n";
//         return false;
//     }
//     return true;
// }

// // ✅ Debugging Function
// void debugInput(const std::string &input) {
//     std::cout << "DEBUG: Original input -> " << input << std::endl;
//     std::cout << "DEBUG: Normalized input -> " << normalizeInput(input) << std::endl;
// }

// // ✅ Parse Sorting Instruction
// std::pair<std::string, std::string> parseSorting(const std::string &input) {
//     if (input.find("generate sorting program using") != std::string::npos) {
//         std::string algorithm = input.substr(32); // Extract sorting algorithm
//         return {"sorting", algorithm};
//     }
//     return {"", ""};
// }

// // ✅ Parse Numerical Calculations (Factorial, Fibonacci, Prime, Armstrong)
// std::pair<std::string, std::string> parseNumericalCalculations(const std::string &input) {
//     std::istringstream stream(input);
//     std::string word, number, type, extra;

//     stream >> word; // "Find"
//     if (word == "find") {
//         stream >> word; // "if", "the", or directly "prime"

//         if (word == "if") { // Case: "Find if 153 is an Armstrong number"
//             stream >> number >> word; // number = "153", word = "is"
//             if (std::all_of(number.begin(), number.end(), ::isdigit)) {
//                 stream >> word; // "an" or the type directly
//                 if (word == "an") stream >> type; // type = "Armstrong"
//                 else type = word; // if "an" is missing, word itself is type

//                 stream >> extra; // extra = "number"
//                 if ((type == "prime" || type == "armstrong") && (extra == "number")) {
//                     return {type, number};
//                 }
//             }
//         } 
//         else if (word == "the") { 
//             stream >> type; // Expecting: "prime", "factorial", "fibonacci"
            
//             if (type == "factorial" || type == "fibonacci") { // "Find the factorial of 5"
//                 stream >> word; // "of"
//                 stream >> number;
//                 if (std::all_of(number.begin(), number.end(), ::isdigit)) {
//                     return {type, number};
//                 }
//             }
//             else if (type == "prime" || type == "armstrong") { // "Find the prime number 7"
//                 stream >> word; // "number"
//                 if (word == "number") {
//                     stream >> number;
//                     if (std::all_of(number.begin(), number.end(), ::isdigit)) {
//                         return {type, number};
//                     }
//                 }
//             }
//         } 
//         else { // Case: "Find Fibonacci numbers up to 10"
//             std::string operation = word;
//             stream >> word; // "numbers" or "number"
//             if (word == "numbers" || word == "number") {
//                 stream >> word; // "up" or "upto"
//                 if (word == "up" || word == "upto") {
//                     stream >> word; // "to" (optional)
//                     if (word == "to" || word.empty()) {
//                         stream >> number;
//                         if (std::all_of(number.begin(), number.end(), ::isdigit)) {
//                             return {operation, number};
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return {"", ""}; // Return empty if input is not recognized
// }


// // ✅ Main Input Parsing Function
// ParsedInput parseInput(const std::string& input) {
//     ParsedInput parsed;
//     std::string normalizedInput = normalizeInput(input);

//     debugInput(input); // Print debug information

//     if (!validateSyntax(normalizedInput)) {
//         return parsed;
//     }

//     auto sortInst = parseSorting(normalizedInput);
//     if (!sortInst.first.empty()) {
//         parsed.action = sortInst.first;
//         parsed.params["algorithm"] = sortInst.second;
//         return parsed;
//     }

//     auto numCalc = parseNumericalCalculations(normalizedInput);
//     if (!numCalc.first.empty()) {
//         parsed.action = numCalc.first;
//         parsed.params["code"] = numCalc.second;
//         return parsed;
//     }

//     // ✅ Handle Predefined Program Generation
//     if (normalizedInput.find("hello world") != std::string::npos) {
//         parsed.action = "hello_world";
//         return parsed;
//     }
//     if (normalizedInput.find("basic math") != std::string::npos) {
//         parsed.action = "basic_math";
//         return parsed;
//     }
//     if (normalizedInput.find("file handling") != std::string::npos) {
//         parsed.action = "file_handling";
//         return parsed;
//     }
//     if (normalizedInput.find("matrix multiplication") != std::string::npos) {
//         parsed.action = "matrix_multiplication";
//         return parsed;
//     }

//     std::cerr << "DEBUG: Unknown input format!" << std::endl;
//     return parsed;
// }


// // std::string generateArithmeticCode(const std::string &operation, int num1, int num2) {
// //     if (operation == "add") {
// //         return "#include <iostream>\n"
// //                "int main() {\n"
// //                "    int a = " + std::to_string(num1) + ", b = " + std::to_string(num2) + ";\n"
// //                "    std::cout << \"The sum is: \" << (a + b) << std::endl;\n"
// //                "    return 0;\n"
// //                "}";
// //     } 
// //     if (operation == "subtract") {
// //         return "#include <iostream>\n"
// //                "int main() {\n"
// //                "    int a = " + std::to_string(num1) + ", b = " + std::to_string(num2) + ";\n"
// //                "    std::cout << \"The difference is: \" << (a - b) << std::endl;\n"
// //                "    return 0;\n"
// //                "}";
// //     } 
// //     std::cerr << "ERROR: Unsupported operation: " << operation << std::endl;
// //     return "Error: Unsupported operation";
// // }












// #include "parser.h"
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <vector>
// #include <fstream>
// #include <cctype>
// #include <memory>

// // ✅ Utility function to print trees
// void printTree(const std::shared_ptr<TreeNode>& node, int depth) { // 🔥 Removed default argument
//     if (!node) return;
//     std::cout << std::string(depth * 4, ' ') << "|-- " << node->value << "\n";
//     for (const auto& child : node->children) {
//         printTree(child, depth + 1);
//     }
// }

// // ✅ Get user input
// std::string getUserInput() {
//     std::string input;
//     std::cout << "Enter your instruction: ";
//     std::getline(std::cin, input);
//     return input;
// }

// // ✅ Normalize Input (Lowercase + Remove Extra Spaces)
// std::string normalizeInput(const std::string &input) {
//     std::string result = input;
//     std::transform(result.begin(), result.end(), result.begin(), ::tolower);
//     result.erase(std::unique(result.begin(), result.end(),
//               [](char a, char b) { return std::isspace(a) && std::isspace(b); }), result.end());
//     return result;
// }

// // ✅ Validate Syntax
// bool validateSyntax(const std::string &input) {
//     if (input.empty()) {
//         std::cerr << "ERROR: Input is empty!\n";
//         return false;
//     }
//     std::string trimmed = input;
//     trimmed.erase(0, trimmed.find_first_not_of(" "));

//     if (!std::isalpha(trimmed[0]) && !std::isdigit(trimmed[0])) { 
//         std::cerr << "ERROR: Input should start with a valid word or number!\n";
//         return false;
//     }
//     return true;
// }

// // ✅ Parse Numerical Calculations (Factorial, Fibonacci, Prime, Armstrong)
// std::pair<std::shared_ptr<TreeNode>, std::pair<std::string, std::string>> parseNumericalCalculations(const std::string &input) {
//     std::istringstream stream(input);
//     std::string word, number, type;

//     std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>("FIND");

//     stream >> word;
//     if (word == "find") {
//         root->addChild(std::make_shared<TreeNode>("THE"));

//         stream >> word;
//         if (word == "the") {  // ✅ Skip "the" if it appears
//             stream >> word;
//         }

//         type = word;
//         root->addChild(std::make_shared<TreeNode>(type));

//         if (type == "factorial" || type == "fibonacci") {
//             stream >> word; // "of"
//             stream >> number;
//             root->addChild(std::make_shared<TreeNode>(number));
//             return {root, {type, number}};
//         }
//         else if (type == "prime" || type == "armstrong") {
//             stream >> word; // "number"
//             if (word == "number") {
//                 stream >> number;
//                 root->addChild(std::make_shared<TreeNode>(number));
//                 return {root, {type, number}};
//             }
//         }
//     }
//     return {nullptr, {"", ""}};
// }


// // ✅ Convert Parser Tree to AST
// std::shared_ptr<TreeNode> convertToAST(const std::shared_ptr<TreeNode>& parserTree) {
//     if (!parserTree) return nullptr;
    
//     std::shared_ptr<TreeNode> astRoot = std::make_shared<TreeNode>(parserTree->children[1]->value);
//     astRoot->addChild(std::make_shared<TreeNode>(parserTree->children[2]->value));
    
//     return astRoot;
// }

// // ✅ Main Input Parsing Function
// ParsedInput parseInput(const std::string& input) {
//     ParsedInput parsed;
//     std::string normalizedInput = normalizeInput(input);

//     if (!validateSyntax(normalizedInput)) {
//         return parsed;
//     }

//     auto numCalc = parseNumericalCalculations(normalizedInput);
//     if (numCalc.second.first.empty()) {
//         std::cerr << "ERROR: Unknown input format!\n";
//         return parsed;
//     }

//     // ✅ Display Parser Tree
//     std::cout << "\nParser Tree\n";
//     printTree(numCalc.first, 0); // 🔥 Pass depth explicitly

//     // ✅ Convert to AST
//     std::shared_ptr<TreeNode> astTree = convertToAST(numCalc.first);
//     std::cout << "\n **Abstract Syntax Tree (AST)** \n";
//     printTree(astTree, 0); // 🔥 Pass depth explicitly

//     // ✅ Store the parsed data
//     parsed.action = numCalc.second.first;
//     parsed.params["code"] = numCalc.second.second;
    
//     return parsed;
// }










#include "parser.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cctype>
#include <memory>

//  Utility function to print trees
void printTree(const std::shared_ptr<TreeNode>& node, int depth) {
    if (!node) return;
    std::cout << std::string(depth * 4, ' ') << "|-- " << node->value << "\n";
    for (const auto& child : node->children) {
        printTree(child, depth + 1);
    }
}

// Get user input
std::string getUserInput() {
    std::string input;
    std::cout << "Enter your instruction: ";
    std::getline(std::cin, input);
    return input;
}

//  Normalize Input (Lowercase + Remove Extra Spaces)
std::string normalizeInput(const std::string &input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    result.erase(std::unique(result.begin(), result.end(),
              [](char a, char b) { return std::isspace(a) && std::isspace(b); }), result.end());
    return result;
}

//  Validate Syntax
bool validateSyntax(const std::string &input) {
    if (input.empty()) {
        std::cerr << "ERROR: Input is empty!\n";
        return false;
    }
    std::string trimmed = input;
    trimmed.erase(0, trimmed.find_first_not_of(" "));

    if (!std::isalpha(trimmed[0]) && !std::isdigit(trimmed[0])) { 
        std::cerr << "ERROR: Input should start with a valid word or number!\n";
        return false;
    }
    return true;
}

//  Parse Print Statements
std::pair<std::shared_ptr<TreeNode>, std::string> parsePrintStatement(const std::string &input) {
    std::istringstream stream(input);
    std::string word;

    // Create the root node for "PRINT"
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>("PRINT");

    // Check if the input starts with "print"
    stream >> word;
    if (word == "print") {
        // Check if there are quotes for the message
        stream >> word;  // Expecting the quote symbol (either single or double quotes)
        
        if (word == "'" || word == "\"") {
            std::string message;
            // If quotes are found, extract everything inside the quotes (single or double)
            std::getline(stream, message, word[0]);  // Use the same quote symbol to extract the message
            
            // Remove leading and trailing spaces from the message (optional but improves input handling)
            message = normalizeInput(message);
            
            // Store the message in the tree and return
            root->addChild(std::make_shared<TreeNode>(message));
            return {root, message};
        } else {
            std::cerr << "ERROR: Missing opening quote in print statement!\n";
        }
    }

    // If the input doesn't match the expected format, return an empty pair
    return {nullptr, ""};
}


// Parse Numerical Calculations (Factorial, Fibonacci, Prime, Armstrong)
std::pair<std::shared_ptr<TreeNode>, std::pair<std::string, std::string>> parseNumericalCalculations(const std::string &input) {
    std::istringstream stream(input);
    std::string word, number, type;

    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>("FIND");

    stream >> word;
    if (word == "find") {
        root->addChild(std::make_shared<TreeNode>("THE"));

        stream >> word;
        if (word == "the") {
            stream >> word;
        }

        type = word;  // Parsing type like "factorial", "fibonacci", "prime"
        root->addChild(std::make_shared<TreeNode>(type));

        std::cout << "Debug: Type: " << type << std::endl;

        if (type == "factorial" || type == "fibonacci") {
            stream >> word; // "of"
            stream >> number;
            root->addChild(std::make_shared<TreeNode>(number));

            std::cout << "Debug: Number: " << number << std::endl;

            return {root, {type, number}};
        } 
        else if (type == "prime" || type == "armstrong") {
            stream >> word; // "number"
            if (word == "number") {
                stream >> number;
                root->addChild(std::make_shared<TreeNode>(number));

                std::cout << "Debug: Number: " << number << std::endl;

                return {root, {type, number}};
            }
        }
    }

    std::cerr << "ERROR: Numerical calculation format mismatch!\n";
    return {nullptr, {"", ""}};
}

//  Convert Parser Tree to AST
std::shared_ptr<TreeNode> convertToAST(const std::shared_ptr<TreeNode>& parserTree, const std::string& action) {
    if (!parserTree) {
        std::cerr << " Error: Parser tree is empty!\n";
        return nullptr;
    }

    std::shared_ptr<TreeNode> astRoot;

    if (action == "create_program") {
        astRoot = std::make_shared<TreeNode>("PROGRAM");

        // Check the program type from the parser tree
        if (parserTree->children.size() >= 2) {  // Expect at least two children (CREATE and 'A')
            std::string programType = parserTree->children[1]->value;  // Check the second child for program type
            std::cout << " Extracted Program Type: " << programType << "\n";

            // Handle hello_world case specifically
            if (programType == "hello_world") {
                astRoot->addChild(std::make_shared<TreeNode>("HELLO_WORLD"));
            } else {
                astRoot->addChild(std::make_shared<TreeNode>(programType));
            }
        } else {
            std::cerr << " Error: Program type missing in AST generation!\n";
            return nullptr;
        }
    } else {
        std::cerr << " Error: AST generation failed for action: " << action << "\n";
        return nullptr;
    }

    return astRoot;
}


//  Updated `parseProgrammingTask` to handle multi-word program types
std::pair<std::shared_ptr<TreeNode>, std::string> parseProgrammingTask(const std::string &input) {
    std::istringstream stream(input);
    std::string word, programType;

    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>("CREATE");

    stream >> word;

    if (word == "create" || word == "write" || word == "generate" || word == "sort") {
        root->addChild(std::make_shared<TreeNode>("A"));

        // Handle "hello world" case
        stream >> word;  // "hello"
        if (word == "hello") {
            stream >> word;  // "world"
            if (word == "world") {
                root->addChild(std::make_shared<TreeNode>("HELLO_WORLD"));
                return {root, "hello_world"};
            } else {
                std::cerr << "ERROR: 'world' is missing after 'hello'.\n";
            }
        }

        // Handle other program types as before
        stream >> word;
        programType = word;
        root->addChild(std::make_shared<TreeNode>(programType));

        return {root, programType};
    }

    std::cerr << "ERROR: Did not match any programming task.\n";
    return {nullptr, ""};
}


//  Updated `parseInput()` to detect different types of input
ParsedInput parseInput(const std::string& input) {
    ParsedInput parsed;
    std::string normalizedInput = normalizeInput(input);

    if (!validateSyntax(normalizedInput)) {
        return parsed;
    }

    //  First, check if the input is a print statement
    auto printTask = parsePrintStatement(normalizedInput);
    if (!printTask.second.empty()) {
        std::cout << "\nParser Tree for Print Statement\n";
        printTree(printTask.first, 0);

        parsed.action = "print";
        parsed.params["message"] = printTask.second;
        return parsed;
    }

    //  Then, check if the input is a programming task
    auto programTask = parseProgrammingTask(normalizedInput);
    if (!programTask.second.empty()) {
        std::cout << "\nParser Tree for Program Creation\n";
        printTree(programTask.first, 0);

        parsed.action = "create_program";
        parsed.params["type"] = programTask.second;
        return parsed;
    }

    //  Otherwise, check if it's a mathematical calculation
    auto numCalc = parseNumericalCalculations(normalizedInput);
    if (!numCalc.second.first.empty()) {
        std::cout << "\nParser Tree for Numerical Calculation\n";
        printTree(numCalc.first, 0);

        parsed.action = numCalc.second.first;
        parsed.params["code"] = numCalc.second.second;
        return parsed;
    }



    

    //  If input does not match any known format
    std::cerr << "ERROR: Unknown input format!\n";
    return parsed;
}





















// #include "parser.h"
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <vector>
// #include <fstream>
// #include <cctype>
// #include <memory>

// // ✅ Utility function to print trees
// void printTree(const std::shared_ptr<TreeNode>& node, int depth) {
//     if (!node) return;
//     std::cout << std::string(depth * 4, ' ') << "|-- " << node->value << "\n";
//     for (const auto& child : node->children) {
//         printTree(child, depth + 1);
//     }
// }

// // ✅ Get user input
// std::string getUserInput() {
//     std::string input;
//     std::cout << "Enter your instruction: ";
//     std::getline(std::cin, input);
//     return input;
// }

// // ✅ Normalize Input (Lowercase + Remove Extra Spaces)
// std::string normalizeInput(const std::string &input) {
//     std::string result = input;
//     std::transform(result.begin(), result.end(), result.begin(), ::tolower);
//     result.erase(std::unique(result.begin(), result.end(),
//               [](char a, char b) { return std::isspace(a) && std::isspace(b); }), result.end());
//     return result;
// }

// // ✅ Validate Syntax
// bool validateSyntax(const std::string &input) {
//     if (input.empty()) {
//         std::cerr << "ERROR: Input is empty!\n";
//         return false;
//     }
//     std::string trimmed = input;
//     trimmed.erase(0, trimmed.find_first_not_of(" "));

//     if (!std::isalpha(trimmed[0]) && !std::isdigit(trimmed[0])) { 
//         std::cerr << "ERROR: Input should start with a valid word or number!\n";
//         return false;
//     }
//     return true;
// }

// // ✅ Parse Print Statements
// std::pair<std::shared_ptr<TreeNode>, std::string> parsePrintStatement(const std::string &input) {
//     std::istringstream stream(input);
//     std::string word;

//     // Create the root node for "PRINT"
//     std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>("PRINT");

//     // Check if the input starts with "print"
//     stream >> word;
//     if (word == "print") {
//         // Check if there are quotes for the message
//         stream >> word;  // Expecting the quote symbol (either single or double quotes)
        
//         if (word == "'" || word == "\"") {
//             std::string message;
//             // If quotes are found, extract everything inside the quotes (single or double)
//             std::getline(stream, message, word[0]);  // Use the same quote symbol to extract the message
            
//             // Remove leading and trailing spaces from the message (optional but improves input handling)
//             message = normalizeInput(message);
            
//             // Store the message in the tree and return
//             root->addChild(std::make_shared<TreeNode>(message));
//             return {root, message};
//         } else {
//             std::cerr << "ERROR: Missing opening quote in print statement!\n";
//         }
//     }

//     // If the input doesn't match the expected format, return an empty pair
//     return {nullptr, ""};
// }


// // ✅ Parse Numerical Calculations (Factorial, Fibonacci, Prime, Armstrong, Arithmetic)
// std::pair<std::shared_ptr<TreeNode>, std::pair<std::string, std::string>> parseNumericalCalculations(const std::string &input) {
//     std::istringstream stream(input);
//     std::string word, number1, number2, type, operation;

//     std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>("CALCULATION");

//     stream >> word;
//     if (word == "calculate" || word == "add" || word == "subtract" || word == "multiply" || word == "divide") {
//         // Handling arithmetic operations
//         stream >> number1;  // First number
//         stream >> operation; // Operator (+, -, *, /)
//         stream >> number2;   // Second number

//         root->addChild(std::make_shared<TreeNode>(number1));
//         root->addChild(std::make_shared<TreeNode>(operation));
//         root->addChild(std::make_shared<TreeNode>(number2));

//         int num1 = std::stoi(number1); // Convert to integer
//         int num2 = std::stoi(number2); // Convert to integer
//         int result = 0;

//         // Perform the operation based on the operator
//         if (operation == "+") {
//             result = num1 + num2;
//         } else if (operation == "-") {
//             result = num1 - num2;
//         } else if (operation == "*") {
//             result = num1 * num2;
//         } else if (operation == "/") {
//             if (num2 == 0) {
//                 std::cerr << "ERROR: Division by zero is not allowed!\n";
//                 return {nullptr, {"", ""}};
//             }
//             result = num1 / num2;
//         } else {
//             std::cerr << "ERROR: Unsupported operation: " << operation << "\n";
//             return {nullptr, {"", ""}};
//         }

//         std::cout << "Result: " << result << std::endl;

//         // Return the result in the tree or as part of the parameters
//         return {root, {"arithmetic", std::to_string(result)}};
//     }

//     // If the input doesn't match the expected arithmetic format, check for other calculations like factorial
//     std::istringstream fallbackStream(input);
//     std::string fallbackWord;
//     std::shared_ptr<TreeNode> fallbackRoot = std::make_shared<TreeNode>("FIND");

//     fallbackStream >> fallbackWord;
//     if (fallbackWord == "find") {
//         fallbackRoot->addChild(std::make_shared<TreeNode>("THE"));

//         fallbackStream >> fallbackWord;
//         if (fallbackWord == "the") {
//             fallbackStream >> fallbackWord;
//         }

//         type = fallbackWord;  // Parsing type like "factorial", "fibonacci", "prime"
//         fallbackRoot->addChild(std::make_shared<TreeNode>(type));

//         std::cout << "Debug: Type: " << type << std::endl;

//         if (type == "factorial" || type == "fibonacci") {
//             fallbackStream >> fallbackWord; // "of"
//             fallbackStream >> number1;
//             fallbackRoot->addChild(std::make_shared<TreeNode>(number1));

//             std::cout << "Debug: Number: " << number1 << std::endl;

//             return {fallbackRoot, {type, number1}};
//         } 
//         else if (type == "prime" || type == "armstrong") {
//             fallbackStream >> fallbackWord; // "number"
//             if (fallbackWord == "number") {
//                 fallbackStream >> number1;
//                 fallbackRoot->addChild(std::make_shared<TreeNode>(number1));

//                 std::cout << "Debug: Number: " << number1 << std::endl;

//                 return {fallbackRoot, {type, number1}};
//             }
//         }
//     }

//     std::cerr << "ERROR: Numerical calculation format mismatch!\n";
//     return {nullptr, {"", ""}};
// }

// // ✅ Convert Parser Tree to AST
// std::shared_ptr<TreeNode> convertToAST(const std::shared_ptr<TreeNode>& parserTree, const std::string& action) {
//     if (!parserTree) {
//         std::cerr << "❌ Error: Parser tree is empty!\n";
//         return nullptr;
//     }

//     std::shared_ptr<TreeNode> astRoot;

//     if (action == "create_program") {
//         astRoot = std::make_shared<TreeNode>("PROGRAM");

//         // Check the program type from the parser tree
//         if (parserTree->children.size() >= 2) {  // Expect at least two children (CREATE and 'A')
//             std::string programType = parserTree->children[1]->value;  // Check the second child for program type
//             std::cout << "✅ Extracted Program Type: " << programType << "\n";

//             // Handle hello_world case specifically
//             if (programType == "hello_world") {
//                 astRoot->addChild(std::make_shared<TreeNode>("HELLO_WORLD"));
//             } else {
//                 astRoot->addChild(std::make_shared<TreeNode>(programType));
//             }
//         } else {
//             std::cerr << "❌ Error: Program type missing in AST generation!\n";
//             return nullptr;
//         }
//     } else {
//         std::cerr << "❌ Error: AST generation failed for action: " << action << "\n";
//         return nullptr;
//     }

//     return astRoot;
// }


// // ✅ Updated `parseProgrammingTask` to handle multi-word program types
// std::pair<std::shared_ptr<TreeNode>, std::string> parseProgrammingTask(const std::string &input) {
//     std::istringstream stream(input);
//     std::string word, programType;

//     std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>("CREATE");

//     stream >> word;

//     if (word == "create" || word == "write" || word == "generate" || word == "sort") {
//         root->addChild(std::make_shared<TreeNode>("A"));

//         // Handle "hello world" case
//         stream >> word;  // "hello"
//         if (word == "hello") {
//             stream >> word;  // "world"
//             if (word == "world") {
//                 root->addChild(std::make_shared<TreeNode>("HELLO_WORLD"));
//                 return {root, "hello_world"};
//             } else {
//                 std::cerr << "ERROR: 'world' is missing after 'hello'.\n";
//             }
//         }

//         // Handle other program types as before
//         stream >> word;
//         programType = word;
//         root->addChild(std::make_shared<TreeNode>(programType));

//         return {root, programType};
//     }

//     std::cerr << "ERROR: Did not match any programming task.\n";
//     return {nullptr, ""};
// }


// // ✅ Updated `parseInput()` to detect different types of input
// ParsedInput parseInput(const std::string& input) {
//     ParsedInput parsed;
//     std::string normalizedInput = normalizeInput(input);

//     if (!validateSyntax(normalizedInput)) {
//         return parsed;
//     }

//     // ✅ First, check if the input is a print statement
//     auto printTask = parsePrintStatement(normalizedInput);
//     if (!printTask.second.empty()) {
//         std::cout << "\nParser Tree for Print Statement\n";
//         printTree(printTask.first, 0);

//         parsed.action = "print";
//         parsed.params["message"] = printTask.second;
//         return parsed;
//     }

//     // ✅ Then, check if the input is a programming task
//     auto programTask = parseProgrammingTask(normalizedInput);
//     if (!programTask.second.empty()) {
//         std::cout << "\nParser Tree for Program Creation\n";
//         printTree(programTask.first, 0);

//         parsed.action = "create_program";
//         parsed.params["type"] = programTask.second;
//         return parsed;
//     }

//     // ✅ Lastly, check if the input is a numerical calculation
//     auto calcTask = parseNumericalCalculations(normalizedInput);
//     if (!calcTask.second.first.empty()) {
//         std::cout << "\nParser Tree for Numerical Calculation\n";
//         printTree(calcTask.first, 0);

//         parsed.action = "calculation";
//         parsed.params["type"] = calcTask.second.first;
//         parsed.params["number"] = calcTask.second.second;
//         return parsed;
//     }

//     std::cerr << "ERROR: Input does not match any recognized format.\n";
//     return parsed;
// }

// int main() {
//     std::string userInput;

//     // Get user input
//     userInput = getUserInput();

//     // Parse the input
//     ParsedInput parsed = parseInput(userInput);

//     if (parsed.action != "") {
//         std::cout << "\nExecution Result: " << parsed.action << "\n";
//         for (const auto& param : parsed.params) {
//             std::cout << "Parameter " << param.first << ": " << param.second << std::endl;
//         }
//     }

//     return 0;
// }








