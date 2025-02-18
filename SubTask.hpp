#include "iostream"

#ifndef TASKSCHEDULINGSYSTEM_SUBTASK_HPP
#define TASKSCHEDULINGSYSTEM_SUBTASK_HPP

/**
 * @class SubTask
 * @brief Represents a smaller unit of work within a larger task.
 *
 * A SubTask can be marked as completed and contains descriptive details.
 */
class SubTask
{
private:
    bool completed; ///< Indicates whether the subtask is completed.
    std::string details; ///< Description or details of the subtask.

public:
    /**
     * @brief Constructs a SubTask with the given details.
     * @param information A description of the subtask.
     */
    explicit SubTask(const std::string &information) : completed(false),
                                                       details(information)
    {}

    /**
     * @brief Marks the subtask as completed.
     */
    void markComplete()
    { completed = true; }

    /**
     * @brief Checks if the subtask is completed.
     * @return True if the subtask is completed, false otherwise.
     */
    bool isComplete() const
    { return completed; }

    /**
     * @brief Retrieves the details of the subtask.
     * @return A string containing the subtask details.
     */
    const std::string &getDetails() const
    { return details; }

    /**
     * @brief Updates the details of the subtask.
     * @param newDetails The new details to be assigned to the subtask.
     */
    void changeDetails(const std::string &newDetails)
    { details = newDetails; }
};

#endif // TASKSCHEDULINGSYSTEM_SUBTASK_HPP
