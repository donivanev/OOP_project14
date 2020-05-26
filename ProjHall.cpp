#include "ConsoleHandler.h"

int main()
{
    ConsoleHandler console;
    string command;

    while (true)
    {
        getline(cin, command);
        string firstWord = command.substr(0, command.find(" "));
        console.processCommand(firstWord, command);
    }
}