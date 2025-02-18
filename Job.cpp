#include "Job.hpp"

bool Job::operator<(const Job &other) const
{
    if (this->priority != other.priority)
    {
        return this->priority < other.priority;
    }
    if (this->progress != other.getProgress())
    {
        return this->progress < other.getProgress();
    }
    if (this->difficulty != other.getDifficulty())
    {
        return this->difficulty < other.getDifficulty();
    }
    return this->id < other.getId();
}

