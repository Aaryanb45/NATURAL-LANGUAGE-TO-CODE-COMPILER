# 🧠 Natural Language to C++ Code Compiler

## Overview

The **Natural Language to C++ Code Compiler** is a smart tool that translates plain English programming instructions into valid, working C++ code. It identifies the user's intent, validates input, generates proper C++ code structures (like loops, conditionals, functions), and even allows execution. It also provides error feedback, performance suggestions, and the option to reverse code into pseudocode for learning purposes.

This compiler aims to make C++ coding simpler for beginners, educators, and developers by eliminating syntax complexity and allowing logic-focused development.

---

## ✨ Features

- ✅ **Intent Detection**: Understands if the user wants to create a loop, declare a variable, define a function, etc.
- 🛠️ **Code Generation**: Generates accurate, readable, and formatted C++ code.
- 🧠 **Syntax Correction**: Detects and auto-fixes basic syntactic issues before compilation.
- 🔁 **Reverse Mode**: Converts C++ code back into pseudocode for easy learning.
- 📄 **Documentation Generator**: Automatically creates inline documentation.
- 📈 **Performance Analyzer**: Suggests improvements and flags inefficient code.
- ⚠️ **Error Logger**: Logs and reports all issues and corrections.
- 💬 **Examples & Help**: Offers real-time help, examples, and manual support.
- 🌍 **Language-Ready**: Designed for future support of additional programming languages.

---

## 🖥️ System Requirements

- **Operating System**: Windows, Linux, or macOS  
- **Compiler**: GCC (for compiling generated C++ code)  
- **C++ Version**: C++17 or higher  
- **Java (optional)**: For future GUI integration  
- **Python 3 (optional)**: If used for NLP preprocessing (experimental)

---

## 🛠️ Installation Guide

Follow these steps to install and run the Natural Language to C++ Compiler:

### Step 1: Clone the Repository

Open your terminal or command prompt and run:

```bash
git clone https://github.com/AkshatPandey-2004/NL-to-CPP-Compiler.git
Step 2: Navigate to the Project Directory
cd NL-to-CPP-Compiler
Step 3: Open the Project in Your Editor
code .
Step 4: Compile the Main Code (If C++ Based UI)
g++ -std=c++17 -o compiler main.cpp
Step 5: Run the Compiler
./compiler
You can now enter natural instructions like:
"Create a for loop from 1 to 10 that prints i"
And see the equivalent C++ code instantly!
📁 File Structure

📦 NL-to-CPP-Compiler/
 ┣ 📜 main.cpp
 ┣ 📜 intentDetector.cpp
 ┣ 📜 codeGenerator.cpp
 ┣ 📜 executor.cpp
 ┣ 📜 formatter.cpp
 ┣ 📜 examples/
 ┃ ┗ 📄 sampleInstructions.txt
 ┣ 📜 README.md
 ┗ 📄 error_log.txt
💡 Sample Instruction

Input:
"Define a function called sum that takes two integers and returns their sum"
Generated Output:
int sum(int a, int b) {
    return a + b;
}

HERE ARE SOME SCREENSHOTS OF THE COMPILER HOW IT LOOKS

<img width="1379" alt="Screenshot 2025-04-11 at 2 07 57 AM" src="https://github.com/user-attachments/assets/18c0b3e1-a3e8-4f5e-b4e7-f80b5e610a0b" />

<img width="1388" alt="Screenshot 2025-04-11 at 2 07 29 AM" src="https://github.com/user-attachments/assets/da8f5af4-d2c7-454c-acd4-14f22c00c65c" />

📨 Contact the Developer

If you have any queries, suggestions, or contributions, feel free to reach out:
📧 Email: aryanbansal182004@gmail.com
💻 GitHub: NL-to-CPP-Compiler Repo
🔗 LinkedIn:aryan-bansal-689a41248

Support

If you like this project, leave a ⭐ on GitHub, share it, or contribute!
Issues and pull requests are welcome.

