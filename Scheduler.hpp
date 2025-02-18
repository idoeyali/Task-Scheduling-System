#ifndef TASKSCHEDULINGSYSTEM_SCHEDULER_HPP
#define TASKSCHEDULINGSYSTEM_SCHEDULER_HPP

#include "Project.hpp"
#include "SimpleTask.hpp"
#include "unordered_map"
#include "queue"
#include <iostream>
#include <string>
#include <memory>
#include "UserInputHandler.hpp"

/**
 * @struct JobComparator
 * @brief A comparator used to compare jobs in the priority queue.
 *
 * This comparator defines how jobs are compared based on their priority
 * and is used in the priority queue to sort jobs by priority.
 */
struct JobComparator
{
    /**
     * @brief Compares two jobs based on their priority.
     * @param a A shared pointer to the first job.
     * @param b A shared pointer to the second job.
     * @return True if the first job has a lower priority than the second, false otherwise.
     */
    bool operator()(const std::shared_ptr<Job> &a,
                    const std::shared_ptr<Job> &b) const
    {
        return *a < *b;  // Use Job's comparison logic
    }
};

/**
 * @class Scheduler
 * @brief Manages the scheduling of jobs (tasks and projects) and their progress.
 *
 * The Scheduler class handles adding jobs to the queue, updating progress, and printing progress.
 * It organizes jobs by priority and supports handling both simple tasks and projects.
 */
class Scheduler
{
private:
    std::unordered_map<int, std::shared_ptr<Project>> allProjects; ///< Stores all projects by their IDs
    std::unordered_map<int, std::shared_ptr<SimpleTask>> allSimpleTasks; ///< Stores all simple tasks by their IDs
    std::priority_queue<std::shared_ptr<Job>, std::vector<std::shared_ptr<Job>>, JobComparator> jobsQueue; ///< Priority queue of jobs

    int userId; ///< The ID of the user
    std::string userName; ///< The name of the user

    /**
     * @brief Updates the progress of a simple task.
     * @param simpleTaskId The ID of the simple task to be updated.
     */
    void updateSimpleTaskHandler(int simpleTaskId);

    /**
     * @brief Updates the progress of a project.
     * @param projectId The ID of the project to be updated.
     */
    void updateProjectHandler(int projectId);

public:
    /**
     * @brief Constructs a Scheduler object with the user's ID and name.
     * @param userId The user's ID.
     * @param userName The user's name.
     */
    Scheduler(int userId, const std::string &userName) : userId(userId),
                                                         userName(userName)
    {}

    /**
     * @brief Gets the user's ID.
     * @return The user's ID.
     */
    int getUserId() const
    { return userId; }

    /**
     * @brief Gets the user's name.
     * @return The user's name.
     */
    const std::string &getUserName() const
    { return userName; }

    /**
     * @brief Adds a new job (project or simple task) to the scheduler.
     * @param isProject Indicates whether the job is a project (true) or a simple task (false).
     */
    void addJob(bool isProject);

    /**
     * @brief Expands a project by adding its subtasks to the scheduler.
     */
    void expandProject();

    /**
     * @brief Updates the progress of a job (project or simple task).
     * @param isProject Indicates whether the job is a project (true) or a simple task (false).
     */
    void updateJobProgress(bool isProject);

    /**
     * @brief Prints the progress of a job (project or simple task).
     * @param isProject Indicates whether the job is a project (true) or a simple task (false).
     */
    void printJobProgress(bool isProject);

    /**
     * @brief Gets the ID of the next job in the priority queue.
     * @return The ID of the next job.
     */
    int getNextJob();
};

#endif // TASKSCHEDULINGSYSTEM_SCHEDULER_HPP
