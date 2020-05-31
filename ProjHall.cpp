#include "ConsoleHandler.h"

int main()
{
    ConsoleHandler console;
    string command;

    while (true)
    {
        getline(cin, command);
        string firstWord = command.substr(0, command.find(" "));
        if (firstWord == "exit")
        {
            cout << "Exiting the program..." << endl;
            return 0;
        }
        else console.processCommand(firstWord, command);
    }

    return 0;
}