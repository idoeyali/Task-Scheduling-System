#include "iostream"
#include "Job.hpp"
#include "SubTask.hpp"
#include "vector"

#ifndef TASKSCHEDULINGSYSTEM_PROJECT_HPP
#define TASKSCHEDULINGSYSTEM_PROJECT_HPP


class Project : public Job
{
private:
    std::vector<SubTask> subTasks;
    int completedTasks;
public:
    Project(int id, const std::string title, int difficulty, const std::string
    &information, int priority, const std::vector<SubTask> &tasks);

    void addSubTask(const SubTask &newSubTask, int taskIndex);

    void updateProgress(int taskId) override;

    double getProgress() const override;

    void printProgress() override;


};


#endif //TASKSCHEDULINGSYSTEM_PROJECT_HPP
