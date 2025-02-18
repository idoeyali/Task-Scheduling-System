#include "iostream"
#include "Job.hpp"
#include "SubTask.hpp"
#include "vector"

#ifndef TASKSCHEDULINGSYSTEM_PROJECT_HPP
#define TASKSCHEDULINGSYSTEM_PROJECT_HPP

/**
 * @class Project
 * @brief Represents a project which is a complex task with multiple subtasks.
 *
 * A Project contains multiple subtasks and tracks the progress based on the completion of those subtasks.
 */
class Project : public Job
{
private:
    std::vector<SubTask> subTasks; ///< A collection of subtasks associated with the project.
    int completedTasks; ///< The number of completed subtasks.

public:
    /**
     * @brief Constructs a Project with a list of subtasks.
     * @param id The unique identifier for the project.
     * @param title The title of the project.
     * @param difficulty The difficulty level of the project.
     * @param information A description of the project.
     * @param priority The priority level of the project.
     * @param tasks A vector of subtasks associated with the project.
     */
    Project(int id, const std::string &title, int difficulty,
            const std::string &information,
            int priority, const std::vector<SubTask> &tasks);

    /**
     * @brief Constructs a Project with no initial subtasks.
     * @param id The unique identifier for the project.
     * @param title The title of the project.
     * @param difficulty The difficulty level of the project.
     * @param information A description of the project.
     * @param priority The priority level of the project.
     */
    Project(int id, const std::string &title, int difficulty,
            const std::string &information,
            int priority) : Job(id, title, difficulty, information, priority),
                            completedTasks(0)
    {}

    /**
     * @brief Adds a new subtask to the project.
     * @param newSubTask The subtask to be added.
     */
    void addSubTask(const SubTask &newSubTask);

    /**
     * @brief Updates the progress of the project based on the completion of a specific subtask.
     * @param taskId The ID of the subtask to be updated.
     */
    void updateProgress(int taskId) override;

    /**
     * @brief Retrieves the current progress of the project.
     * @return A double representing the progress of the project (from 0 to 1).
     */
    double getProgress() const override;

    /**
     * @brief Prints the current progress of the project.
     */
    void printProgress() override;
};

#endif // TASKSCHEDULINGSYSTEM_PROJECT_HPP
