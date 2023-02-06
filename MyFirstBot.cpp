#include <dpp/dpp.h>
#include <iostream>
#include <sstream>
#include <string>
#include "MyFirstBot.h"

const std::string    BOT_TOKEN = "MTA3MjE2MjA2MTI2MzU4NTM0Mw.GJwDVK.VJLT9tu_NP2roA8vqlTaloHYmVPk9STB61FZ8s";

bool bCheckForGam(const std::string& str)
{
    std::string word = "";
    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ' || i == (n - 1))
        {
            if (word == "gam" || "GAM")
            {
                return true;
                break;
            }
        }
        else
        {
            word += str[i];
        }
    }
}


int main() {
    dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_message_create([&bot](const dpp::message_create_t& event)
    {
            if (event.msg.author.is_bot() == false && bCheckForGam(event.msg.content) == true)
            {
                dpp::message msg(event.msg.channel_id, "I believe it's spelt game!");
                bot.message_create(msg);
            }
    });

    bot.start(dpp::st_wait);
    return 0;
}

