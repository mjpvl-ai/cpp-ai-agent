#include "AIClient.h"
#include <iostream>

int main() {
    AIClient ai("models/deepseek-llm-7b-chat.Q2_K.gguf");  // Make sure to use a GGUF model
    std::string response = ai.query("What is AI?");
    std::cout << "AI Response: " << response << std::endl;
    return 0;
}
