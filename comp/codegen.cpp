// #include "codegen.h"
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <cmath>

// // ✅ Generate Code from AST
// std::string generateCode(std::shared_ptr<ASTNode> root) {
//     if (!root) {
//         return "Error: AST is empty.";
//     }
//     return root->value;
// }

// // ✅ Fibonacci Program
// std::string createFibonacciProgram(const std::string &number) {
//     return "#include <iostream>\n"
//            "void generateFibonacci(int n) {\n"
//            "    int t1 = 0, t2 = 1, nextTerm;\n"
//            "    for (int i = 1; i <= n; ++i) {\n"
//            "        std::cout << t1 << ' ';\n"
//            "        nextTerm = t1 + t2;\n"
//            "        t1 = t2;\n"
//            "        t2 = nextTerm;\n"
//            "    }\n"
//            "}\n"
//            "int main() {\n"
//            "    generateFibonacci(" + number + ");\n"
//            "    return 0;\n"
//            "}\n";
// }

// // ✅ Factorial Program
// std::string createFactorialProgram(const std::string &number) {
//     return "#include <iostream>\n"
//            "int factorial(int n) {\n"
//            "    return (n == 0) ? 1 : n * factorial(n - 1);\n"
//            "}\n"
//            "int main() {\n"
//            "    std::cout << factorial(" + number + ") << std::endl;\n"
//            "    return 0;\n"
//            "}\n";
// }

// // ✅ Prime Check
// std::string createPrimeProgram(const std::string &number) {
//     return "#include <iostream>\n"
//            "bool isPrime(int n) {\n"
//            "    if (n <= 1) return false;\n"
//            "    for (int i = 2; i * i <= n; i++) {\n"
//            "        if (n % i == 0) return false;\n"
//            "    }\n"
//            "    return true;\n"
//            "}\n"
//            "int main() {\n"
//            "    std::cout << (isPrime(" + number + ") ? \"Prime\" : \"Not Prime\") << std::endl;\n"
//            "    return 0;\n"
//            "}\n";
// }

// // ✅ Armstrong Number Check
// std::string createArmstrongProgram(const std::string &number) {
//     return "#include <iostream>\n"
//            "#include <cmath>\n"
//            "bool isArmstrong(int num) {\n"
//            "    int sum = 0, temp = num, remainder, digits = 0;\n"
//            "    while (temp != 0) { temp /= 10; digits++; }\n"
//            "    temp = num;\n"
//            "    while (temp != 0) {\n"
//            "        remainder = temp % 10;\n"
//            "        sum += pow(remainder, digits);\n"
//            "        temp /= 10;\n"
//            "    }\n"
//            "    return (sum == num);\n"
//            "}\n"
//            "int main() {\n"
//            "    std::cout << (isArmstrong(" + number + ") ? \"Armstrong\" : \"Not Armstrong\") << std::endl;\n"
//            "    return 0;\n"
//            "}\n";
// }

// // ✅ Hello World Program
// std::string createHelloWorldProgram() {
//     return "#include <iostream>\n"
//            "int main() {\n"
//            "    std::cout << \"Hello, World!\" << std::endl;\n"
//            "    return 0;\n"
//            "}\n";
// }

// // ✅ Basic Math Program
// std::string createBasicMathProgram() {
//     return "#include <iostream>\n"
//            "int main() {\n"
//            "    int a = 5, b = 10;\n"
//            "    std::cout << \"Sum: \" << (a + b) << std::endl;\n"
//            "    return 0;\n"
//            "}\n";
// }

// // ✅ File Handling Program
// std::string createFileHandlingProgram() {
//     return "#include <iostream>\n"
//            "#include <fstream>\n"
//            "int main() {\n"
//            "    std::ofstream file(\"output.txt\");\n"
//            "    file << \"Hello, file!\";\n"
//            "    file.close();\n"
//            "    return 0;\n"
//            "}\n";
// }

// // ✅ Matrix Multiplication Program
// std::string createMatrixMultiplicationProgram() {
//     return "#include <iostream>\n"
//            "void multiplyMatrices(int A[2][2], int B[2][2], int C[2][2]) {\n"
//            "    for (int i = 0; i < 2; i++) {\n"
//            "        for (int j = 0; j < 2; j++) {\n"
//            "            C[i][j] = 0;\n"
//            "            for (int k = 0; k < 2; k++) {\n"
//            "                C[i][j] += A[i][k] * B[k][j];\n"
//            "            }\n"
//            "        }\n"
//            "    }\n"
//            "}\n";
// }


// std::string createSortingProgram(const std::string &algorithm) {
//     if (algorithm == "bubble") {
//         return "#include <iostream>\n"
//                "void bubbleSort(int arr[], int n) {\n"
//                "    for (int i = 0; i < n - 1; i++) {\n"
//                "        for (int j = 0; j < n - i - 1; j++) {\n"
//                "            if (arr[j] > arr[j + 1]) {\n"
//                "                std::swap(arr[j], arr[j + 1]);\n"
//                "            }\n"
//                "        }\n"
//                "    }\n"
//                "}\n";
//     } 
//     else if (algorithm == "quick") {
//         return "#include <iostream>\n"
//                "int partition(int arr[], int low, int high) {\n"
//                "    int pivot = arr[high];\n"
//                "    int i = low - 1;\n"
//                "    for (int j = low; j < high; j++) {\n"
//                "        if (arr[j] < pivot) {\n"
//                "            std::swap(arr[++i], arr[j]);\n"
//                "        }\n"
//                "    }\n"
//                "    std::swap(arr[i + 1], arr[high]);\n"
//                "    return i + 1;\n"
//                "}\n"
//                "void quickSort(int arr[], int low, int high) {\n"
//                "    if (low < high) {\n"
//                "        int pi = partition(arr, low, high);\n"
//                "        quickSort(arr, low, pi - 1);\n"
//                "        quickSort(arr, pi + 1, high);\n"
//                "    }\n"
//                "}\n";
//     } 
//     else {
//         return "Error: Unsupported sorting algorithm -> " + algorithm;
//     }
// }


// std::string generateArithmeticCode(const std::string &operation, int num1, int num2) {
//     if (operation == "add") {
//         return "#include <iostream>\n"
//                "int main() {\n"
//                "    int a = " + std::to_string(num1) + ", b = " + std::to_string(num2) + ";\n"
//                "    int sum = a + b;\n"
//                "    std::cout << \"The sum is: \" << sum << std::endl;\n"
//                "    return 0;\n"
//                "}";
//     } 
//     else if (operation == "subtract") {
//         return "#include <iostream>\n"
//                "int main() {\n"
//                "    int a = " + std::to_string(num1) + ", b = " + std::to_string(num2) + ";\n"
//                "    int diff = a - b;\n"
//                "    std::cout << \"The difference is: \" << diff << std::endl;\n"
//                "    return 0;\n"
//                "}";
//     }
//     return ""; 
// }








#include "codegen.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>

//  Print Parser Tree Before AST Generation
void printParserTree(const ParsedInput& input) {
    std::cout << "\n **Parser Tree Generated:**" << std::endl;
    std::cout << "  ├── Action: " << input.action << std::endl;
    for (const auto& param : input.params) {
        std::cout << "  │   ├── " << param.first << ": " << param.second << std::endl;
    }
}

//  Generate Code from AST
std::string generateCode(std::shared_ptr<ASTNode> root) {
    if (!root) return "Error: AST is empty.";

    std::cout << "\n **Abstract Syntax Tree (AST) Generated:**" << std::endl;
    root->print();  //  Print AST Before Code

    return root->value;
}

//  Fibonacci Program
std::string createFibonacciProgram(const std::string &number) {
    return R"cpp(#include <iostream>
void generateFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    for (int i = 1; i <= n; ++i) {
        std::cout << t1 << ' ';
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}
int main() {
    generateFibonacci()cpp" + number + R"cpp();
    return 0;
})cpp";
}

// Factorial Program
std::string createFactorialProgram(const std::string &number) {
    return R"cpp(#include <iostream>
int factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}
int main() {
    std::cout << factorial()cpp" + number + R"cpp() << std::endl;
    return 0;
})cpp";
}

//  Prime Check
std::string createPrimeProgram(const std::string &number) {
    return R"cpp(#include <iostream>
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    std::cout << (isPrime()cpp" + number + R"cpp() ? "Prime" : "Not Prime") << std::endl;
    return 0;
})cpp";
}

//  Armstrong Number Check
std::string createArmstrongProgram(const std::string &number) {
    return R"cpp(#include <iostream>
#include <cmath>
bool isArmstrong(int num) {
    int sum = 0, temp = num, remainder, digits = 0;
    while (temp != 0) { temp /= 10; digits++; }
    temp = num;
    while (temp != 0) {
        remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }
    return (sum == num);
}
int main() {
    std::cout << (isArmstrong()cpp" + number + R"cpp() ? "Armstrong" : "Not Armstrong") << std::endl;
    return 0;
})cpp";
}

//  Hello World Program
std::string createHelloWorldProgram() {
    return R"cpp(#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
})cpp";
}

//  Basic Math Program
std::string createBasicMathProgram() {
    return R"cpp(#include <iostream>
int main() {
    int a = 5, b = 10;
    std::cout << "Sum: " << (a + b) << std::endl;
    return 0;
})cpp";
}

//  File Handling Program
std::string createFileHandlingProgram() {
    return R"cpp(#include <iostream>
#include <fstream>
int main() {
    std::ofstream file("output.txt");
    file << "Hello, file!";
    file.close();
    return 0;
})cpp";
}

//  Matrix Multiplication Program
std::string createMatrixMultiplicationProgram() {
    return R"cpp(#include <iostream>
void multiplyMatrices(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
})cpp";
}

//  Sorting Algorithms
std::string createSortingProgram(const std::string &algorithm) {
    if (algorithm == "bubble") {
        return R"cpp(#include <iostream>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
})cpp";
    } else if (algorithm == "quick") {
        return R"cpp(#include <iostream>
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[++i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
})cpp";
    }
    return "Error: Unsupported sorting algorithm -> " + algorithm;
}

//  Arithmetic Operations
std::string generateArithmeticCode(const std::string &operation, int num1, int num2) {
    return R"cpp(#include <iostream>
int main() {
    int a = )cpp" + std::to_string(num1) + ", b = " + std::to_string(num2) + R"cpp(;
    int result = )cpp" + (operation == "add" ? "a + b" : "a - b") + R"cpp(;
    std::cout << "Result: " << result << std::endl;
    return 0;
})cpp";
}
