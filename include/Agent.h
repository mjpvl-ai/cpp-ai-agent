#ifndef AGENT_H
#define AGENT_H

#include <string>
#include <vector>
#include <functional>

class Agent {
public:
    Agent(const std::string& name, std::function<std::string(std::string)> action);
    std::string execute(const std::string& input);
    void addNext(Agent* nextAgent);
    
private:
    std::string name;
    std::function<std::string(std::string)> action;
    std::vector<Agent*> nextAgents;
};

#endif
