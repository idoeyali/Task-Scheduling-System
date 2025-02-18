#include "iostream"
#include "algorithm"
#include "Job.hpp"
#include "vector"
#define MOST_COMPLETED 0.75
#define HALF_COMPLETED 0.5

#ifndef TASKSCHEDULINGSYSTEM_SIMPLETASK_HPP
#define TASKSCHEDULINGSYSTEM_SIMPLETASK_HPP

class SimpleTask : public Job
{
private:
    bool recurring;

public:
    SimpleTask(int id, const std::string &title, int difficulty, const
    std::string
    &information, int priority, bool isRecurring) :
            Job(id, title, difficulty, information, priority),
            recurring(isRecurring)
    {}

    bool isRecurring() const
    {
        return recurring;
    }

    void setRecurring(bool isRecurring)
    {
        recurring = isRecurring;
    }

    void printProgress() override;

    void updateProgress(int completedPercentage) override;

    int getDifficulty() const override;
};

#endif //TASKSCHEDULINGSYSTEM_SIMPLETASK_HPP
