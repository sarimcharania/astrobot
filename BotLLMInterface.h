#pragma once

#include <string>
#include <iostream>
//#include <curl/curl.h> // or any HTTP library you prefer

class BotLLMInterface {
public:
    // Simulate sending a message to the API and getting a response
    static std::string processMessage(const std::string& inputMessage) {
        // Simulate sending the message to an API (you'd normally use an HTTP request here)
        std::cout << "Sending message to BotLLMInterface: " << inputMessage << std::endl;
        // Simulated response (replace this with real API call logic)
        return "Processed: " + inputMessage; // Simulate a processed response
    }
};

