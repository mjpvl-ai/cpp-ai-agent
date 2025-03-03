#include "AIClient.h"
#include "Agent.h"
#include "VectorDB.h"
#include <iostream>

int main() {
    AIClient llm("deepseek-r1:1.5b");

    std::string response = llm.query("What is AI?");
    std::cout << "AI: " << response << std::endl;

    Agent textProcessor("Processor", [](std::string input) {
        return "Processed: " + input;
    });

    Agent summarizer("Summarizer", [](std::string input) {
        return "Summary: " + input.substr(0, 10);
    });

    textProcessor.addNext(&summarizer);
    std::cout << textProcessor.execute("This is a test.") << std::endl;

    return 0;
}
