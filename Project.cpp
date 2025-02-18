#include "Project.hpp"

Project::Project(int id, const std::string &title, int difficulty, const
std::string &information, int priority, const std::vector<SubTask> &tasks) :
        Job(id, title, difficulty, information, priority)
{
    subTasks = tasks;
    completedTasks = 0;
}

void Project::updateProgress(int taskIndex)
{
    if (taskIndex >= subTasks.size())
    {
        std::cout << "Invalid task number" << std::endl;
        return;
    }
    if (subTasks[taskIndex].isComplete())
    {
        std::cout << "The task as been already completed." << std::endl;
        return;
    }
    subTasks[taskIndex].markComplete();
    completedTasks += 1;
}

double Project::getProgress() const
{
    return completedTasks / (double) subTasks.size();
}

void Project::addSubTask(const SubTask &newSubTask, int taskIndex)
{
    subTasks.insert(subTasks.begin() + taskIndex, newSubTask);
}

void Project::printProgress()
{
    std::cout << "--- Project " << this->getTitle() << " progress ---" <<
              std::endl;
    std::cout << getProgress() * 100 << "% of the project tasks completed:" <<
              std::endl;
    for (int i = 0; i < subTasks.size(); i++)
    {
        std::cout << "Sub Task " << i << " --- ";
        if (!subTasks[i].isComplete())
        {
            std::cout << "in";
        }
        std::cout << "complete" << std::endl;
    }
    std::vector<std::string> levels = {"low", "medium", "high"};
    std::cout << "This project has " << levels[getDifficulty()]
              << " difficulty level";
    std::cout << " and it in " << levels[getPriority()] << " priority!"
              << std::endl;
}