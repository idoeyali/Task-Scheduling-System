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
                                                      {"high",   2}};

    std::string level;
    std::cin >> level;
    while (levelsMap.find(level) == levelsMap.end())
    {
        std::cout
                << "This level should be low/medium/high. Please enter level again: ";
        std::cin >> level;
    }
    return levelsMap[level];
}


std::string UserInputHandler::getDetailsFromUser()
{

    std::string input;
    std::cin.ignore();
    std::getline(std::cin, input);

    while (input.empty())
    {
        std::cout
                << "The input should contain at least 1 character. Please enter input again: ";
        std::getline(std::cin, input);
    }
    return input;
}

std::vector<SubTask> UserInputHandler::getSubTaskSet()
{
    std::vector<SubTask> tasks;
    std::cin.ignore();
    while (true)
    {
        std::cout << "Enter the details for sub-task " << tasks.size() << " (type '!' to stop)\n";

        std::string input;

        std::getline(std::cin, input);
        if (input == "!")
        {
            break;
        }

        tasks.emplace_back(input);
    }
    return tasks;
}


bool UserInputHandler::getRecurring()
{
    std::cout << "This task is recurring? Enter Y/N.: ";
    std::string input;
    std::cin >> input;
    while (input != "Y" && input != "N")
    {
        std::cout << "Enter Y/N. Please enter input again: ";
        std::cin >> input;
    }
    if(input == "Y"){
        return true;
    }
    return false;
}

bool UserInputHandler::getJobType()
{
    std::string input;
    std::cin >> input;
    while (input != "project" && input != "simple-task")
    {
        std::cout << "Choose project/simple-task. Please enter input again: ";
        std::cin >> input;
    }
    return true ? input == "project" : false;
}