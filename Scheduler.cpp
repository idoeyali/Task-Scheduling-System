#include "Scheduler.hpp"

void Scheduler::addJob(bool isProject)
{
    std::cout << "--- Adding a new project ---\n";
    std::cout << "Enter Project ID: ";
    int projectId = UserInputHandler::getIDFromUser();
    while (allProjects.find(projectId) != allProjects.end())
    {
        std::cout << "This ID already used! ";
        projectId = UserInputHandler::getIDFromUser();
    }
    std::cout << "Enter Project Title: ";
    std::string title = UserInputHandler::getDetailsFromUser();
    std::cout << "Enter Project Information: ";
    std::string information = UserInputHandler::getDetailsFromUser();
    std::cout << "Enter Project Difficulty Level: ";
    int difficulty = UserInputHandler::getLevelFromUser();
    std::cout << "Enter Project Priority Level: ";
    int priority = UserInputHandler::getLevelFromUser();
    if (isProject)
    {

    }
    std::vector<SubTask> tasks = UserInputHandler::getSubTaskSet();
    allProjects[projectId] = std::make_shared<Project>(projectId, title,
                                                       difficulty,
                                                       information, priority,
                                                       tasks);
    jobsQueue.push(allProjects[projectId]);
    std::cout << "--- Project added to the schedule successfully! ---\n\n";

}

void Scheduler::printJobProgress()
{
    std::cout << "------\n";
    int projectId = UserInputHandler::getIDFromUser();
    while (allProjects.find(projectId) == allProjects.end())
    {
        std::cout << "This ID doesn't exist! ";
        projectId = UserInputHandler::getIDFromUser();
    }
    allProjects[projectId]->printProgress();
}

void Scheduler::updateJobProgress()
{
    std::cout << "--- Updating job progress ---\n";
    std::cout << "Enter Project ID: ";
    int projectId = UserInputHandler::getIDFromUser();
    while (allProjects.find(projectId) == allProjects.end())
    {
        std::cout << "This ID doesn't exist! ";
        projectId = UserInputHandler::getIDFromUser();
    }
    std::cout << "Enter sub-task number to complete: ";
    int progress = UserInputHandler::getIDFromUser();
    allProjects[projectId]->updateProgress(progress);
}



