#include "AIClient.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

AIClient::AIClient(const std::string& modelName) : model(modelName) {}

std::string AIClient::query(const std::string& prompt) {
    std::ostringstream command;
    command << "ollama run " << model << " \"" << prompt << "\"";

    std::string response;
    FILE* pipe = popen(command.str().c_str(), "r");
    if (!pipe) return "Error: Unable to execute Ollama";

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        response += buffer;
    }
    pclose(pipe);

    return response;
}
