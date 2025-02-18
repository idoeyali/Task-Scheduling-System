#ifndef TASKSCHEDULINGSYSTEM_USERINPUTHANDLER_HPP
#define TASKSCHEDULINGSYSTEM_USERINPUTHANDLER_HPP
#include <iostream>
#include <string>
#include "unordered_map"
#include "vector"
#include "SubTask.hpp"

/**
 * @class UserInputHandler
 * @brief Handles user input operations for creating tasks and managing subtasks.
 *
 * This class contains static methods that facilitate interaction with the user, such as getting task ID,
 * details, level, job type, and handling subtasks.
 */
class UserInputHandler
{
public:
    /**
     * @brief Prompts the user to input a unique task ID.
     * @return The ID entered by the user as an integer.
     */
    static int getIDFromUser();

    /**
     * @brief Checks if the provided string represents a numeric value.
     * @param str The string to be checked.
     * @return True if the string is numeric, otherwise false.
     */
    static bool isNumeric(const std::string& str);

    /**
     * @brief Prompts the user to input details about the task or subtask.
     * @return The details entered by the user as a string.
     */
    static std::string getDetailsFromUser();

    /**
     * @brief Prompts the user to input a priority level for the task.
     * @return The priority level entered by the user as an integer.
     */
    static int getLevelFromUser();

    /**
     * @brief Asks the user if the task is recurring.
     * @return True if the task is recurring, otherwise false.
     */
    static bool getRecurring();

    /**
     * @brief Prompts the user to select the type of job (simple task or project).
     * @return True if the user selects a project, otherwise false (simple task).
     */
    static bool getJobType();

    /**
     * @brief Prompts the user to input a set of subtasks for a project or task.
     * @return A vector of SubTask objects entered by the user.
     */
    static std::vector<SubTask> getSubTaskSet();
};

#endif // TASKSCHEDULINGSYSTEM_USERINPUTHANDLER_HPP
