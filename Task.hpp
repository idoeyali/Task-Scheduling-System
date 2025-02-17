#define LOW 0
#define MEDIUM 1
#define HIGH 2

#include "iostream"

#ifndef TASKSCHEDULINGSYSTEM_TASK_HPP
#define TASKSCHEDULINGSYSTEM_TASK_HPP

class Task
{
private:
    int ID;
    int difficulty;
    std::string information;

public:
    Task(int id, int difficulty, const std::string &information)
            : ID(id), difficulty(difficulty),
              information(information)
    {}
    int getId() const
    { return ID; }

    int getDifficulty() const
    { return difficulty; }

    const std::string &getInformation() const
    { return information; }
    

    void changeInformation(const std::string &newInformation)
    {
        information = newInformation;
    }

    virtual void updateProgress(int taskId) = 0;

    virtual ~Task() = default;



};

#endif //TASKSCHEDULINGSYSTEM_TASK_HPP
