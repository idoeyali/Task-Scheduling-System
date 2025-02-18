#include "SimpleTask.hpp"


void SimpleTask::updateProgress(int completedPercentage)
{
    this->setProgress(completedPercentage / 100.0);
}

int SimpleTask::getDifficulty() const
{
    if (Job::getProgress() > MOST_COMPLETED)
    {
        return LOW;
    }
    if (Job::getProgress() > HALF_COMPLETED)
    {
        return std::max(Job::getDifficulty() - 1, LOW);
    }
    return Job::getDifficulty();
}

void SimpleTask::printProgress()
{
    std::cout << "--- Single Task " << this->getTitle() << " progress ---" <<
              std::endl;
    std::cout << getProgress() * 100 << "% of the task completed" << std::endl;
    std::vector<std::string> levels = {"low", "medium", "high"};
    std::cout << "This Task has " << levels[getDifficulty()]
              << " difficulty level";
    std::cout << " and it in " << levels[getPriority()] << " priority!"
              << std::endl;
}