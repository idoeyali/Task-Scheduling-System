#include "iostream"
#include "SimpleTask.hpp"
#include "Project.hpp"
#include "Scheduler.hpp"

/**
 * @brief Handles user input for managing projects.
 *
 * This function provides a menu of options for interacting with projects in the scheduler.
 * It allows the user to add a new project, update a project's progress, add subtasks, and show project progress.
 *
 * @param scheduler A pointer to the `Scheduler` object that handles jobs (projects and simple tasks).
 */
void runProject(Scheduler *scheduler)
{
    std::cout << "Select one of the following actions:\n";
    std::cout << "1. Add New Project    |    2. Update Project's progress\n";
    std::cout << "3. Add Sub-Task to Project  |  4. Show Project's progress\n";
    int input;
    std::cin >> input;
    switch (input)
    {
        case 1:
            scheduler->addJob(true); // Adds a new project
            break;
        case 2:
            scheduler->updateJobProgress(true); // Updates the progress of a project
            break;
        case 3:
            scheduler->expandProject(); // Expands a project by adding subtasks
            break;
        case 4:
            scheduler->printJobProgress(true); // Prints the progress of a project
            break;
        default:
            std::cout << "Invalid option.\n"; // Invalid option selected
    }
}

/**
 * @brief Handles user input for managing simple tasks.
 *
 * This function provides a menu of options for interacting with simple tasks in the scheduler.
 * It allows the user to add a new simple task, update a simple task's progress, and show the progress of a simple task.
 *
 * @param scheduler A pointer to the `Scheduler` object that handles jobs (projects and simple tasks).
 */
void runSimpleTask(Scheduler *scheduler)
{
    std::cout << "Select one of the following actions:\n";
    std::cout << "1. Add New Simple-Task   |   2. Update Simple-Task's progress\n";
    std::cout << "3. Show Simple-Task's progress\n";
    int input;
    std::cin >> input;
    switch (input)
    {
        case 1:
            scheduler->addJob(false); // Adds a new simple task
            break;
        case 2:
            scheduler->updateJobProgress(false); // Updates the progress of a simple task
            break;
        case 3:
            scheduler->printJobProgress(false); // Prints the progress of a simple task
            break;
        default:
            std::cout << "Invalid option.\n"; // Invalid option selected
    }
}

/**
 * @brief Displays the next job to be completed according to priority.
 *
 * This function retrieves and displays the ID of the next job to be completed from the scheduler's queue.
 * If no jobs are left to do, it informs the user.
 *
 * @param scheduler A pointer to the `Scheduler` object that handles jobs (projects and simple tasks).
 */
void runNextJob(Scheduler *scheduler)
{
    int nextId = scheduler->getNextJob(); // Gets the ID of the next job
    if(nextId == -1){
        std::cout << "There is no more jobs to do.\n"; // No more jobs left
        return;
    }
    else{
        std::cout << "The next Job to do: " << nextId << std::endl; // Displays the next job's ID
    }
}

/**
 * @brief Starts and runs the main scheduler menu.
 *
 * This function is the main entry point of the scheduler application. It presents the user with options to interact
 * with either projects or simple tasks, as well as the option to retrieve the next job to be completed.
 * It continuously runs until the user exits the program.
 */
void runScheduler(int userId, const std::string &userName)
{
    auto *scheduler = new Scheduler(userId, userName); // Creates a new scheduler
    // instance

    while (true)
    {
        std::cout << "Select one of the following actions:\n";
        std::cout << "1. Project     |     2. Simple Task\n";
        std::cout << "3. Get next job to do\n";

        int input;
        std::cin >> input;
        switch (input)
        {
            case 1:
                runProject(scheduler); // Runs the project menu
                break;
            case 2:
                runSimpleTask(scheduler); // Runs the simple task menu
                break;
            case 3:
                runNextJob(scheduler); // Runs the next job retrieval
                break;
            default:
                std::cout << "Invalid option.\n"; // Invalid option selected
        }
    }
}
/**
 * @brief Prompts the user for their ID and name.
 *
 * This function asks the user to enter their ID and name, then returns these values.
 *
 * @param userId A reference to an integer where the user ID will be stored.
 * @param userName A reference to a string where the user name will be stored.
 */
void getUserInfo(int &userId, std::string &userName)
{
    std::cout << "Enter your ID: ";
    std::cin >> userId;

    std::cout << "Enter your name: ";
    std::cin >> userName;
}
/**
 * @brief Main entry point for the program.
 */
int main()
{
    int userId;
    std::string userName;

    // Get user ID and name from the input
    getUserInfo(userId, userName);

    // Pass the user info to the scheduler
    runScheduler(userId, userName);

    return 0;
}
