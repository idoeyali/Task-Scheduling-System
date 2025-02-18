#include "iostream"
#include "algorithm"
#include "Job.hpp"
#include "vector"

#define MOST_COMPLETED 0.75
#define HALF_COMPLETED 0.5

#ifndef TASKSCHEDULINGSYSTEM_SIMPLETASK_HPP
#define TASKSCHEDULINGSYSTEM_SIMPLETASK_HPP

/**
 * @class SimpleTask
 * @brief Represents a basic task in the scheduling system.
 *
 * This class extends the Job class and introduces the concept of recurring tasks.
 * SimpleTask provides specific implementations for updating and printing progress.
 */
class SimpleTask : public Job
{
private:
    bool recurring; ///< Indicates whether the task is recurring.

public:
    /**
     * @brief Constructs a SimpleTask object.
     * @param id Unique job ID.
     * @param title Title of the task.
     * @param difficulty Difficulty level of the task.
     * @param information Additional details about the task.
     * @param priority Priority level (LOW, MEDIUM, HIGH).
     * @param isRecurring Indicates if the task is recurring.
     */
    SimpleTask(int id, const std::string &title, int difficulty,
               const std::string &information, int priority, bool isRecurring)
            :
            Job(id, title, difficulty, information, priority),
            recurring(isRecurring)
    {}

    /**
     * @brief Checks if the task is recurring.
     * @return True if the task is recurring, false otherwise.
     */
    bool isRecurring() const
    { return recurring; }

    /**
     * @brief Sets whether the task is recurring.
     * @param isRecurring True if the task should be recurring, false otherwise.
     */
    void setRecurring(bool isRecurring)
    { recurring = isRecurring; }

    /**
     * @brief Prints the current progress of the task.
     */
    void printProgress() override;

    /**
     * @brief Updates the progress of the task.
     * @param completedPercentage The percentage of completion (0-100).
     */
    void updateProgress(int completedPercentage) override;

    /**
     * @brief Retrieves the difficulty level of the task.
     * @return The difficulty level as an integer.
     */
    int getDifficulty() const override;
};

#endif // TASKSCHEDULINGSYSTEM_SIMPLETASK_HPP
