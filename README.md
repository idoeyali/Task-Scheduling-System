# Task Scheduling System

## Overview
The **Task Scheduling System** is a C++ application that allows users to manage and track projects, simple tasks, and subtasks. It supports features such as adding tasks, updating their progress, viewing task progress, and getting the next job to work on. The system uses a priority queue to manage jobs and allows users to perform actions based on the type of task (Project or Simple Task).

## Features

- **Add New Tasks**: Users can add new tasks, both projects and simple tasks.
- **Update Progress**: Users can update the progress of tasks, whether it's a project or a simple task.
- **View Progress**: View the progress of the task, showing how much of the task is completed.
- **Handle Subtasks**: Projects can have multiple subtasks. Subtasks can be marked as completed.
- **Priority Management**: Tasks are managed based on their priority using a priority queue.
- **User Interaction**: Users interact with the system through a simple console interface.

## Classes

The system is organized into several classes that define the main components of the scheduling system:

- **`Job`**: The base class representing a general job. It stores task details like ID, title, priority, and progress.
- **`SimpleTask`**: A derived class from `Job` that represents a simple task, which can be recurring.
- **`SubTask`**: Represents subtasks that are part of a project.
- **`Project`**: A derived class from `Job` that represents a project, which can contain multiple subtasks.
- **`Scheduler`**: Handles the job queue, adds new jobs, updates job progress, and prints job progress.
- **`UserInputHandler`**: Handles user input for task details and validation.
- **`JobComparator`**: Used to compare jobs based on priority.

## Getting Started

### Prerequisites

To run the system, you need to have the following installed:

- C++ compiler (e.g., `g++`)
- C++ Standard Library

## Usage

Once the program is running, you will be prompted to select actions. You can choose between adding tasks, updating their progress, or viewing their status.

The program allows you to:

- **Manage Projects and Simple Tasks**: Add new tasks and update progress for both projects and simple tasks.
- **View Task Progress**: Check the progress of any task.
- **Get Next Job**: Retrieve the next job to work on based on priority.

## Example Interaction

### For Projects


- **Option 1**: Adds a new project.
- **Option 2**: Updates the progress of an existing project.
- **Option 3**: Adds a new sub-task to an existing project.
- **Option 4**: Displays the progress of a project.

### For Simple Tasks


- **Option 1**: Adds a new simple task.
- **Option 2**: Updates the progress of an existing simple task.
- **Option 3**: Displays the progress of a simple task.

### Get Next Job


- **Option 1**: Retrieves and displays the next job to work on based on priority.

## User Input

The program will prompt you for the following inputs:

- **User ID**: Enter your unique identifier.
- **User Name**: Enter your name.
- **Task Title**: Provide a title for your task.
- **Task Difficulty**: Enter the difficulty level of the task.
- **Task Priority**: Input the priority level (e.g., Low, Medium, High).
- **Task Recurrence**: For simple tasks, specify if the task is recurring.
- **Subtask Details**: For projects, enter details for each subtask until you indicate that you are finished.

## Contributions

Contributions to this project are welcome! If you'd like to contribute, please follow these steps:

1. **Fork** the repository.
2. **Create a new branch** for your feature or bug fix.
3. **Make your changes**.
4. **Submit a pull request** with a detailed description of your changes.

Feel free to open an issue if you have any suggestions or encounter any bugs.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
