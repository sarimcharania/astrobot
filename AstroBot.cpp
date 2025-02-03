// AstroBot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <dpp/dpp.h>

//Local Includes
#include <Bot.h>

#pragma warning(disable : 4251)


std::string getEnvironmentVariable(const char* var_name) 
{
    std::ifstream file("config.env");
    if (!file.is_open()) {
        return "";
    }

    std::string line;
    while (std::getline(file, line)) {
        // Ignore empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Find the token in the format KEY=VALUE
        size_t delimiterPos = line.find('=');
        if (delimiterPos != std::string::npos) {
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);

            // Check if the key matches the desired var_name
            if (key == var_name) {
                return value;
            }
        }
    }

    return ""; // Return empty if the var_name is not found
}

int main() {
    std::string sToken = getEnvironmentVariable("DISCORD_BOT_TOKEN");

    if (sToken.empty()) {
        std::cerr << "Error: DISCORD_BOT_TOKEN is not set!\n";
        return 1;
    }

    //Create & Start the bot
    Bot::getInstance(sToken)->getClient().start(dpp::st_wait);

    return 0;
}
