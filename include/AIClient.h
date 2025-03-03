#ifndef AICLIENT_H
#define AICLIENT_H

#include <string>

class AIClient {
public:
    AIClient(const std::string& modelName);
    std::string query(const std::string& prompt);
    
private:
    std::string model;
};

#endif
