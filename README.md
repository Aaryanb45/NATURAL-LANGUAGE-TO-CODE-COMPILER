# 🧠 Natural Language to C++ Code Compiler

A compiler that takes **high-level natural language instructions** and generates **syntactically correct, functional C++ code**. Designed for educational and development use, this tool bridges the gap between human thinking and code logic.

---

## 🚀 Features

- 📝 Convert natural instructions to C++ code (e.g., *"create a loop from 1 to 10"*)
- 🔍 Detects intents: variable declarations, loops, conditionals, functions, etc.
- ⚙️ Generates Three Address Code (TAC) and Conceptual Assembly for each step
- 📦 Modular functions to handle parsing, mapping, and code generation
- 🧪 Supports error handling, syntax validation, and performance suggestions
- 📚 Converts code back to pseudocode for learning
- 🌐 Designed for multi-language support in the future

---

## 🛠️ Architecture Overview


---

## 📦 Core Modules and Responsibilities

| Module Function                      | Responsibility |
|-------------------------------------|----------------|
| `getUserInput()`                    | Captures raw input |
| `tokenizeInput()`                   | Splits input into tokens |
| `normalizeInput()`                 | Standardizes input (e.g., lowercase) |
| `detectLanguageIntent()`           | Identifies what the user wants to do |
| `validateSyntax()`                 | Checks grammar and instruction structure |
| `parseVariables()`, `parseLoops()` | Identifies relevant structures |
| `mapToCppX()` (conditional, loop)  | Maps instructions to C++ syntax |
| `generateCppX()`                   | Generates C++ code blocks |
| `compileCode()`, `executeCode()`   | Builds and runs the code |
| `saveCodeToFile()`, `loadCodeFromFile()` | I/O functions for user code |
| `generateDocumentation()`          | Creates inline docs |
| `convertCodeToPseudoCode()`        | Reverses generated code to explain logic |

---

## 💡 Example Usage

**Input:**

**TAC:**
```cpp
t1 = 1
t2 = 10
t3 = "for"
t4 = generateCppLoop(t3, t1 < t2)
for (int i = 1; i <= 10; i++) {
    std::cout << i << std::endl;
}


FOLDER STRUCTURE


📦 compiler/
 ┣ 📜 main.cpp
 ┣ 📜 parser.cpp
 ┣ 📜 generator.cpp
 ┣ 📜 optimizer.cpp
 ┣ 📜 pseudoCode.cpp
 ┣ 📜 README.md
 ┣ 📁 examples/
 ┃ ┗ 📜 loopExample.txt
 ┗ 📁 docs/
    ┗ 📜 userManual.pdf

🧪 Future Enhancements

🧠 Natural Language Processing (NLP) engine for better parsing
🌍 Multilingual support
📘 Integration with popular IDEs (VSCode extension)
📈 Code performance benchmarking
🧩 Visual drag-drop instruction builder


Getting Started

Clone this repository
git clone https://github.com/yourusername/nl-to-cpp-compiler.git
cd nl-to-cpp-compiler
Build
g++ -std=c++17 -o compiler main.cpp
Run
./compiler

HERE ARE SOME SCREENSHOTS OF THE COMPILER HOW IT LOOKS
# NATURAL-LANGUAGE-TO-CODE-COMPILER<img width="1470" alt="Screenshot 2025-04-11 at 1 59 26 AM" src="https://github.com/user-attachments/assets/77df2267-afd7-48e2-acb3-f64e44777941" />
<img width="1410" alt="Screenshot 2025-04-11 at 2 00 42 AM" src="https://github.com/user-attachments/assets/277467dd-7d19-4d36-8233-d91060190ccf" />
<img width="1372" alt="Screenshot 2025-04-11 at 2 01 49 AM" src="https://github.com/user-attachments/assets/a2ce0536-ffc5-44a7-baa9-5f4f47be2398" />


Support

If you like this project, leave a ⭐ on GitHub, share it, or contribute!
Issues and pull requests are welcome.

