#include "Bot.h"
#include "BotLLMInterface.h"

// Initialize static instance
Bot* Bot::instance = nullptr;

// Private constructor
Bot::Bot(const std::string& token) : mClient(token, (dpp::i_all_intents))
{
    // Set up logging for DPP events
    mClient.on_log(dpp::utility::cout_logger());

    // Register event handlers
    mClient.on_ready([this](const dpp::ready_t& event) {
        onReady(event);
        });

    mClient.on_message_create([this](const dpp::message_create_t& event) {
        onMessageCreate(event);
        });

    mClient.on_slashcommand([this](const dpp::slashcommand_t& event) {
        onSlashCommand(event);
        });
}

// Event Handler: Bot is ready
void Bot::onReady(const dpp::ready_t& event)
{
    //uint64_t guild_id = <YOUR_GUILD_ID>;  // Replace with your actual guild ID
    //registerHelloCommand(/*guild_id*/);
}

// Register slash command (Hello)
void Bot::registerHelloCommand(uint64_t guild_id)
{
    dpp::slashcommand hello_command("hello", "Say hello!", guild_id);
    mClient.global_command_create(hello_command);
}

// Event Handler: Message received
void Bot::onMessageCreate(const dpp::message_create_t& event)
{
    // Ignore bot's own messages
    if (event.msg.author.is_bot()) return;

    // Check if the message starts with "ab" TODO: Fix!
    if (event.msg.content.substr(0, 2) == "ab") {
        std::string processed_message = event.msg.content.substr(2);
        processMessageAndReply(processed_message, event);
    }
}

// Process message and send to BotLLMInterface API
void Bot::processMessageAndReply(const std::string& message, const dpp::message_create_t& event)
{
    // Send message to the imaginary BotLLMInterface and get response
    std::string api_response = BotLLMInterface::processMessage(message);

    // Reply back with the response from the API
    event.reply(api_response);
}

// Event Handler: Slash command received
void Bot::onSlashCommand(const dpp::slashcommand_t& event)
{
    if (event.command.get_command_name() == "hello") {
        event.reply("Hello, world!");
    }
}

// Singleton instance retrieval
Bot* Bot::getInstance(const std::string& token) 
{
    if (instance == nullptr) {
        instance = new Bot(token);
    }
    return instance;
}

// Get the client
dpp::cluster& Bot::getClient()
{
    return mClient;
}
