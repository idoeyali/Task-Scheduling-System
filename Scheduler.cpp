#include "Scheduler.hpp"

void Scheduler::addJob(bool isProject)
{
    std::cout << "--- Adding a new project ---\n";
    std::cout << "Enter ID: ";
    int jobId = UserInputHandler::getIDFromUser();
    while (allProjects.find(jobId) != allProjects.end() ||
           allSimpleTasks.find(jobId) != allSimpleTasks.end())
    {
        std::cout << "This ID already used! ";
        jobId = UserInputHandler::getIDFromUser();
    }
    std::cout << "Enter Title: ";
    std::string jobTitle = UserInputHandler::getDetailsFromUser();
    std::cout << "Enter Project Information: ";
    std::string jobInformation = UserInputHandler::getDetailsFromUser();
    std::cout << "Enter Difficulty Level: ";
    int jobDifficulty = UserInputHandler::getLevelFromUser();
    std::cout << "Enter Priority Level: ";
    int jobPriority = UserInputHandler::getLevelFromUser();
    if (isProject)
    {
        std::vector<SubTask> tasks = UserInputHandler::getSubTaskSet();
        allProjects[jobId] = std::make_shared<Project>(jobId, jobTitle,
                                                       jobDifficulty,
                                                       jobInformation,
                                                       jobPriority,
                                                       tasks);
        jobsQueue.push(allProjects[jobId]);
    } else
    {
        bool isRecurring = UserInputHandler::getRecurring();
        allSimpleTasks[jobId] = std::make_shared<SimpleTask>(jobId,
                                                             jobTitle,
                                                             jobDifficulty,
                                                             jobInformation,
                                                             jobPriority,
                                                             isRecurring);
        jobsQueue.push(allSimpleTasks[jobId]);
    }


    std::cout << "--- Project added to the schedule successfully! ---\n\n";

}

void Scheduler::printJobProgress(bool isProject)
{
    std::cout << "------\n";
    std::cout << "Enter ID: ";
    int jobId = UserInputHandler::getIDFromUser();
    while (allProjects.find(jobId) == allProjects.end()
           && allSimpleTasks.find(jobId) == allSimpleTasks.end())
    {
        std::cout << "This ID doesn't exist! ";
        jobId = UserInputHandler::getIDFromUser();
    }
    if (isProject)
    {
        allProjects[jobId]->printProgress();
    } else
    {
        allSimpleTasks[jobId]->printProgress();
    }
}


void Scheduler::updateProjectHandler(int projectId)
{
    std::cout << "Enter sub-task number to complete: ";
    int progress = UserInputHandler::getIDFromUser();
    allProjects[projectId]->updateProgress(progress);
    if (allProjects[projectId]->getProgress() == 1)
    {
        std::cout << "--- Good Job - Project Have Been Completed!!!! ---\n";
        allProjects.erase(projectId);
    }
}

void Scheduler::updateJobProgress(bool isProject)
{
    std::cout << "--- Updating Job progress ---\n";
    std::cout << "Enter ID: ";
    int jobId = UserInputHandler::getIDFromUser();
    while (allSimpleTasks.find(jobId) == allSimpleTasks.end()
           && allProjects.find(jobId) == allProjects.end())
    {
        std::cout << "This ID doesn't exist! ";
        jobId = UserInputHandler::getIDFromUser();
    }
    if (isProject)
    {
        updateProjectHandler(jobId);
    } else
    {
        updateSimpleTaskHandler(jobId);
    }
    std::cout << "------------\n\n";
}

void Scheduler::updateSimpleTaskHandler(int simpleTaskId)
{
    std::cout << "Enter percentage that have been completed: ";
    int percentage = UserInputHandler::getIDFromUser();
    allSimpleTasks[simpleTaskId]->updateProgress(percentage);
    if (allSimpleTasks[simpleTaskId]->getProgress() == 1)
    {
        std::cout << "--- Good Job - Task Have Been Completed!!!! ---\n";
        if (allSimpleTasks[simpleTaskId]->isRecurring())
        {
            allSimpleTasks[simpleTaskId]->updateProgress(0);
        } else
        {
            allSimpleTasks.erase(simpleTaskId);
        }
    }
}

void Scheduler::expandProject()
{
    std::cout << "--- Expanding Project ---\n";
    std::cout << "Enter Project ID: ";
    int projectId = UserInputHandler::getIDFromUser();
    while (allProjects.find(projectId) == allProjects.end())
    {
        std::cout << "This ID doesn't exist! ";
        projectId = UserInputHandler::getIDFromUser();
    }
    std::cout << "Enter new sub-task details:\n";
    SubTask newSubTask = SubTask(UserInputHandler::getDetailsFromUser());
    allProjects[projectId]->addSubTask(newSubTask);
}

int Scheduler::getNextJob()
{
    if (jobsQueue.empty())
    {
        return -1;
    }
    int nextId = jobsQueue.top()->getId();
    while (allProjects.find(nextId) == allProjects.end() &&
           allSimpleTasks.find(nextId) == allSimpleTasks.end())
    {
        jobsQueue.pop();
        if (jobsQueue.empty())
        {
            return -1;
        }
        nextId = jobsQueue.top()->getId();
    }
    return nextId;
}



