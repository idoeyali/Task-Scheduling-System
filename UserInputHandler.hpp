#ifndef TASKSCHEDULINGSYSTEM_USERINPUTHANDLER_HPP
#define TASKSCHEDULINGSYSTEM_USERINPUTHANDLER_HPP
#include <iostream>
#include <string>
#include "unordered_map"
#include "vector"
#include "SubTask.hpp"

class UserInputHandler
{
public:
    static int getIDFromUser();

    static bool isNumeric(const std::string& str);

    static std::string getDetailsFromUser();

    static int getLevelFromUser();

    static std::vector<SubTask> getSubTaskSet();

};


#endif //TASKSCHEDULINGSYSTEM_USERINPUTHANDLER_HPP
