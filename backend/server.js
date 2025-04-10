const express = require("express");
const cors = require("cors");
const { spawn } = require("child_process");

const app = express();
app.use(express.json());
app.use(cors());

const compilerPath = "/Users/aryanbansal/compilerfinale/comp/compiler"; 

app.post("/compile", (req, res) => {
    const userInput = req.body.input;
    console.log(`Received input: ${userInput}`);

    // Spawn a new process for the compiler
    const compilerProcess = spawn(compilerPath);

    let outputData = "";

    // Listen for output from the compiler
    compilerProcess.stdout.on("data", (data) => {
        outputData += data.toString();
    });

    compilerProcess.stderr.on("data", (data) => {
        console.error("Error:", data.toString());
    });

    // Send user input to the compiler
    compilerProcess.stdin.write(userInput + "\n");
    compilerProcess.stdin.end(); // Close input stream

    // When the process exits, send the output back to frontend
    compilerProcess.on("close", (code) => {
        console.log(`Compiler process exited with code ${code}`);
        res.json({ output: outputData });
    });
});

app.listen(3001, () => console.log("✅ Server running on port 3001"));
