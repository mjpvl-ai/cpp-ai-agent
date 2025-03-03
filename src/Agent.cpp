#include "Agent.h"
#include <iostream>

Agent::Agent(const std::string& name, std::function<std::string(std::string)> action)
    : name(name), action(action) {}

std::string Agent::execute(const std::string& input) {
    std::string result = action(input);
    for (auto* nextAgent : nextAgents) {
        result = nextAgent->execute(result);
    }
    return result;
}

void Agent::addNext(Agent* nextAgent) {
    nextAgents.push_back(nextAgent);
}
