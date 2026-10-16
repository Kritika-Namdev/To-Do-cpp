
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Task {
    int id;
    string title;
    bool completed;
};

vector<Task> tasks;
int nextId = 1;

void addTask() {
    string title;

    cout << "Enter task title: ";
    getline(cin, title);

    if (title.empty()) {
        cout << "Task title cannot be empty!\n";
        return;
    }

    tasks.push_back({nextId, title, false});
    nextId++;

    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks found!\n";
        return;
    }

    cout << "\n===== YOUR TASKS =====\n";

    for (const Task& task : tasks) {
        cout << "ID: " << task.id
             << " | " << task.title
             << " | " << (task.completed ? "Completed" : "Pending")
             << "\n";
    }
}

void completeTask() {
    int id;

    cout << "Enter task ID to complete: ";

    if (!(cin >> id)) {
        cout << "Invalid ID!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Task& task : tasks) {
        if (task.id == id) {
            if (task.completed) {
                cout << "Task is already completed!\n";
            } else {
                task.completed = true;
                cout << "Task marked as completed!\n";
            }
            return;
        }
    }

    cout << "Task ID not found!\n";
}

void deleteTask() {
    int id;

    cout << "Enter task ID to delete: ";

    if (!(cin >> id)) {
        cout << "Invalid ID!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "Task deleted successfully!\n";
            return;
        }
    }

    cout << "Task ID not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== TO-DO LIST =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Please enter a valid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout << "Thank you for using To-Do List!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
