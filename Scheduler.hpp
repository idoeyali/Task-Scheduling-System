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

class Scheduler
{
private:
    std::unordered_map<int, std::shared_ptr<Project>> allProjects;
    std::unordered_map<int, std::shared_ptr<SimpleTask>> allSimpleTasks;
    std::priority_queue<std::shared_ptr<Job>> jobsQueue;

    int userId;
    std::string userName;

public:
    Scheduler(int userId, const std::string &userName) : userId(userId),
                                                         userName(userName)
    {}
    int getUserId() const
    { return userId; }

    const std::string &getUserName() const
    { return userName; }

    void addJob();

    void expandProject();


    void updateJobProgress();

    void printJobProgress();

    std::shared_ptr<Job> getNextJob();


};


#endif //TASKSCHEDULINGSYSTEM_SCHEDULER_HPP
