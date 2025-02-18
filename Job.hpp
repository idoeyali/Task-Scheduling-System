#define LOW 0
#define MEDIUM 1
#define HIGH 2

#include "iostream"

#ifndef TASKSCHEDULINGSYSTEM_TASK_HPP
#define TASKSCHEDULINGSYSTEM_TASK_HPP

/**
 * @class Job
 * @brief Represents a generic job/task in the scheduling system.
 *
 * This abstract base class provides common attributes and methods for different types of jobs.
 * Derived classes must implement specific behavior for updating and printing progress.
 */
class Job
{
private:
    int id;                  ///< Unique identifier for the job.
    int difficulty;          ///< Difficulty level of the job.
    std::string information; ///< Additional information about the job.
    std::string title;       ///< Title of the job.
    int priority;            ///< Priority level of the job (LOW, MEDIUM, HIGH).
    double progress;         ///< Progress of the job (0.0 to 1.0).

protected:
    /**
     * @brief Sets the progress of the job.
     * @param newProgress The new progress value (0.0 - 1.0).
     */
    void setProgress(double newProgress)
    {
        progress = newProgress;
    }

public:
    /**
     * @brief Constructor for the Job class.
     * @param id Unique job ID.
     * @param title Title of the job.
     * @param difficulty Difficulty level of the job.
     * @param information Additional details about the job.
     * @param priority Priority level (LOW, MEDIUM, HIGH).
     */
    Job(int id, const std::string &title, int difficulty,
        const std::string &information, int priority)
            : id(id), title(title), difficulty(difficulty),
              information(information), priority(priority), progress(0)
    {}

    /**
     * @brief Retrieves the job ID.
     * @return Job ID.
     */
    int getId() const
    { return id; }

    /**
     * @brief Retrieves the difficulty level of the job.
     * @return Difficulty level.
     */
    virtual int getDifficulty() const
    { return difficulty; }

    /**
     * @brief Retrieves additional job information.
     * @return Job information string.
     */
    const std::string &getInformation() const
    { return information; }

    /**
     * @brief Retrieves the priority level of the job.
     * @return Priority level (LOW, MEDIUM, HIGH).
     */
    int getPriority() const
    { return priority; }

    /**
     * @brief Changes the priority level of the job.
     * @param newPriority New priority level (LOW, MEDIUM, HIGH).
     */
    void changePriority(int newPriority)
    { priority = newPriority; }

    /**
     * @brief Retrieves the title of the job.
     * @return Job title.
     */
    const std::string &getTitle() const
    { return title; }

    /**
     * @brief Changes the title of the job.
     * @param title New title string.
     */
    void changeTitle(const std::string &title)
    { Job::title = title; }

    /**
     * @brief Retrieves the progress of the job.
     * @return Progress as a double (0.0 - 1.0).
     */
    virtual double getProgress() const
    { return progress; }

    /**
     * @brief Updates the job's additional information.
     * @param newInformation New information string.
     */
    void changeInformation(const std::string &newInformation)
    { information = newInformation; }

    /**
     * @brief Updates the progress of the job.
     * @param taskId Identifier of the task being updated.
     */
    virtual void updateProgress(int taskId) = 0;

    /**
     * @brief Prints the progress of the job.
     */
    virtual void printProgress() = 0;

    /**
     * @brief Compares two jobs based on priority, progress, difficulty, and ID.
     * @param other The job to compare against.
     * @return True if this job has lower priority than the other job.
     */
    virtual bool operator<(const Job& other) const;

    /**
     * @brief Virtual destructor for proper cleanup in derived classes.
     */
    virtual ~Job() = default;
};

#endif // TASKSCHEDULINGSYSTEM_TASK_HPP
