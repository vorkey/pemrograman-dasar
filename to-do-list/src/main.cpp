#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
private:
  string name;
  string description;
  string dueDate;
  bool completed;

public:
  Task(const string &name, const string &description, const string &dueDate)
      : name(name), description(description), dueDate(dueDate),
        completed(false) {}

  // Getter for task name
  string getName() const { return name; }

  // Getter for task description
  string getDescription() const { return description; }

  // Getter for task due date
  string getDueDate() const { return dueDate; }

  // Getter for task completion status
  bool isCompleted() const { return completed; }

  // Setter for task name
  void setName(const string &name) { this->name = name; }

  // Setter for task description
  void setDescription(const string &description) {
    this->description = description;
  }

  // Setter for task due date
  void setDueDate(const string &dueDate) { this->dueDate = dueDate; }

  // Mark the task as completed
  void markCompleted() { completed = true; }

  void displayTask() const {
    cout << name << " (" << (completed ? "Completed" : "Pending")
         << ") - Due: " << dueDate << endl
         << "   Description: " << description << endl;
  }
};

class ToDoList {
private:
  vector<Task> tasks;

public:
  void displayMenu() {
    cout << "\n---------- To-Do List Menu -----------\n";
    cout << "1. Add Task\n";
    cout << "2. Delete Task\n";
    cout << "3. Display Tasks\n";
    cout << "4. Mark task as completed\n";
    cout << "5. Edit task\n";
    cout << "6. Exit\n";
    cout << "--------------------------------------"
            "\n";
  }

  void addTask() {
    string name, description, dueDate;
    cout << "Enter task name: ";
    cin.ignore();
    // Get input from console that allows whitespace in it
    getline(cin, name);
    cout << "Enter task desciption: ";
    getline(cin, description);
    cout << "Enter task due date (YYYY-MM-DD): ";
    getline(cin, dueDate);

    tasks.emplace_back(name, description, dueDate);
    cout << "Task added successfully!" << endl;
  }

  void deleteTask() {
    if (tasks.empty()) {
      cout << "No tasks to delete!" << endl;
      return;
    }
    cout << "Tasks:" << endl;
    for (unsigned int i = 0; i < tasks.size(); ++i) {
      cout << i + 1 << ". " << tasks[i].getName() << endl;
    }
    cout << "Enter the task number to delete: ";
    unsigned int taskNumber;
    cin >> taskNumber;
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
      tasks.erase(tasks.begin() + taskNumber + 1);
      cout << "Task deleted successfully!" << endl;
    } else {
      cout << "Invalid task number!" << endl;
    }
  }

  void displayTask() {
    if (tasks.empty()) {
      cout << "No tasks to display!" << endl;
      return;
    }
    cout << "Tasks:" << endl;
    for (unsigned int i = 0; i < tasks.size(); ++i) {
      cout << i + 1 << ". ";
      tasks[i].displayTask();
    }
  }

  void markTaskCompleted() {
    if (tasks.empty()) {
      cout << "No tasks to mark as completed!" << endl;
      return;
    }
    cout << "Tasks:" << endl;
    for (unsigned int i = 0; i < tasks.size(); ++i) {
      cout << i + 1 << ". " << tasks[i].getName() << endl;
    }
    cout << "Enter the task number to mark as completed: ";
    unsigned int taskNumber;
    cin >> taskNumber;
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
      tasks[taskNumber - 1].markCompleted();
      cout << "Task marked as completed!" << endl;
    } else {
      cout << "Invalid task number!" << endl;
    }
  }

  void editTask() {
    if (tasks.empty()) {
      cout << "No tasks to edit!" << endl;
      return;
    }
    cout << "Tasks:" << endl;
    for (unsigned int i = 0; i < tasks.size(); ++i) {
      cout << i + 1 << ". " << tasks[i].getName() << endl;
    }
    cout << "Enter the task number to edit: ";
    unsigned int taskNumber;
    cin >> taskNumber;
    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
      Task &task = tasks[taskNumber - 1];
      string name, description, dueDate;
      cout << "Enter new task name (Current: " << task.getName() << "): ";
      cin.ignore();
      getline(cin, name);
      cout << "Enter new task desciption (Current: " << task.getDescription()
           << "): ";
      getline(cin, description);
      cout << "Enter new task due date (YYYY-MM-DD) (Current: "
           << task.getDueDate() << "): ";
      getline(cin, dueDate);

      task.setName(name);
      task.setDescription(description);
      task.setDueDate(dueDate);
      cout << "Task updated successfully!" << endl;

    } else {
      cout << "Invalid task number!" << endl;
    }
  }

  void run() {
    int choice;
    do {
      displayMenu();
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice) {
      case 1:
        addTask();
        break;
      case 2:
        deleteTask();
        break;
      case 3:
        displayTask();
        break;
      case 4:
        markTaskCompleted();
        break;
      case 5:
        editTask();
        break;
      case 6:
        cout << "Exiting program. Bye!" << endl;
        break;
      default:
        cout << "Invalid choice. Please try again!" << endl;
      }

    } while (choice != 6);
  }
};

int main() {
  ToDoList toDoList;
  toDoList.run();
  return 0;
}