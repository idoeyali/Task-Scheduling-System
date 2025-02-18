#define LOW 0
#define MEDIUM 1
#define HIGH 2

#include "iostream"

#ifndef TASKSCHEDULINGSYSTEM_TASK_HPP
#define TASKSCHEDULINGSYSTEM_TASK_HPP

class Job
{
private:
    int id;
    int difficulty;
    std::string information;
    std::string title;


private:
    int priority;
    double progress;
protected:
    void setProgress(double newProgress)
    {
        progress = newProgress;
    }

public:
    Job(int id, const std::string &title, int difficulty,
        const std::string &information, int priority)
            : id(id), title(title), difficulty(difficulty),
              information(information), priority(priority), progress(0)
    {}

    int getId() const
    { return id; }

    virtual int getDifficulty() const
    { return difficulty; }

    const std::string &getInformation() const
    { return information; }

    int getPriority() const
    { return priority; }

    void changePriority(int newPriority)
    { priority = newPriority; }

    const std::string &getTitle() const
    { return title; }

    void changeTitle(const std::string &title)
    { Job::title = title; }

    virtual double getProgress() const
    { return progress; }

    void changeInformation(const std::string &newInformation)
    { information = newInformation; }

    virtual void updateProgress(int taskId) = 0;

    virtual void printProgress() = 0;

    virtual ~Job() = default;


};

#endif //TASKSCHEDULINGSYSTEM_TASK_HPP
