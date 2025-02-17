#include "iostream"
#include "Task.hpp"

#ifndef TASKSCHEDULINGSYSTEM_SIMPLETASK_HPP
#define TASKSCHEDULINGSYSTEM_SIMPLETASK_HPP

class SimpleClass : public Task
{
private:
    int priority;
    bool recurring;
    int progress;

public:
    SimpleClass(int id, int difficulty,
                const std::string &information, int priority,
                const std::string &information1,
                bool isRecurring) : Task(id, difficulty,
                                         information),
                                    priority(priority),
                                    recurring(isRecurring),
                                    progress(0)
    {}

    int getPriority() const
    { return priority; }

    void changePriority(int newPriority)
    {
        priority = newPriority;
    }

    bool isRecurring() const
    {
        return recurring;
    }

    void setRecurring(bool isRecurring)
    {
        recurring = isRecurring;
    }

    int getProgress() const
    {
        return progress;
    }

    void updateProgress(int completedPercentage) override
    {
        progress = completedPercentage;
    }
};

#endif //TASKSCHEDULINGSYSTEM_SIMPLETASK_HPP
