#include "UserInputHandler.hpp"

int UserInputHandler::getIDFromUser()
{
    std::string stringId;
    while (true)
    {
        std::cin >> stringId;
        if (!isNumeric(stringId))
        {
            std::cout << "Invalid input! Please enter input again: ";
            continue;
        }
        int id = std::stoi(stringId);
        return id;
    }
}

bool UserInputHandler::isNumeric(const std::string &str)
{
    for (char ch: str)
    {
        if (!std::isdigit(ch))
        {
            return false;  // Found a non-digit character
        }
    }
    return !str.empty();
}

int UserInputHandler::getLevelFromUser()
{
    std::unordered_map<std::string, int> levelsMap = {{"low",    0},
                                                      {"medium", 1},
                                                      {
                                                       "high",   2}};
    std::string level;
    std::cin >> level;
    while (levelsMap.find(level) == levelsMap.end())
    {
        std::cout << "This level should be low/medium/high. Please enter "
                     "level again: ";
        std::cin >> level;
    }
    return levelsMap[level];
}

std::string UserInputHandler::getDetailsFromUser()
{
    std::string input;
    std::cin >> input;
    while (input.empty())
    {
        std::cout
                << "The input should contain at least 1 character. Please enter input again: ";
        std::cin >> input;
    }
    return input;
}

std::vector<SubTask> UserInputHandler::getSubTaskSet()
{
    std::vector<SubTask> tasks;
    std::string input = "temp";
    int count = 0;
    while (input != "!")
    {
        std::cout << "Enter the details for the " << count << " sub-task (type"
                                                              " '!' to stop)\n";
        std::cin >> input;
        tasks.emplace_back(input);
        count++;
    }
    return tasks;
}