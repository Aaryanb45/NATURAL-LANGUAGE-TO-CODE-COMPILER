const { exec } = require("child_process");

const compilerPath = "/Users/aryanbansal/Documents/COMPILE/comp/compiler";
const userInput = "find the factorial of 5";

console.log(`Executing: "${compilerPath}" "${userInput}"`);

exec(`"${compilerPath}" "${userInput}"`, (error, stdout, stderr) => {
    if (error) {
        console.error("❌ Execution Error:", error.message);
        return;
    }
    if (stderr) {
        console.error("⚠️ Stderr:", stderr);
        return;
    }
    console.log("✅ Output:", stdout);
});

