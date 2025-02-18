#include "iostream"

#ifndef TASKSCHEDULINGSYSTEM_SUBTASK_HPP
#define TASKSCHEDULINGSYSTEM_SUBTASK_HPP

class SubTask
{
private:
    bool completed;
    std::string details;

public:
    explicit SubTask(const std::string &information) : completed(false),
                                                       details(information)
    {}

    void markComplete()
    { completed = true; }

    bool isComplete() const
    { return completed; }

    const std::string &getDetails() const
    { return details; }

    void changeDetails(const std::string &newDetails)
    { details = newDetails; }
};

#endif //TASKSCHEDULINGSYSTEM_SUBTASK_HPP
