#pragma once

#include <dpp/dpp.h>

class Bot 
{
private:
    static Bot* instance;
    dpp::cluster mClient;  // Client instance for the bot

    // Private constructor to prevent external instantiation
    Bot(const std::string& token);

public:
    static Bot* getInstance(const std::string& token);
    dpp::cluster& getClient();

private:
    void registerHelloCommand(uint64_t guild_id);
    void onReady(const dpp::ready_t& event);
    void onMessageCreate(const dpp::message_create_t& event);
    void processMessageAndReply(const std::string& message, const dpp::message_create_t& event);
    void onSlashCommand(const dpp::slashcommand_t& event);

};
