#define _GNU_SOURCE
#include "todolist.h"
#include <ncurses.h>
#include <string.h>

void initializeTodoList(todoList *list) { list->count = 0; }

void addNewTask(todoList *list) {
  if (list->count >= maxItems) {
    printw("Max items reached, please complete your previous tasks.\n");
    return;
  }

  char newTask[maxLength];
  printw("Enter new task: ");
  refresh();
  echo();
  getstr(newTask);
  noecho();

  strcpy(list->items[list->count].task, newTask);
  list->items[list->count].completed = 0;
  list->items[list->count].priority = 1; // Default priority
  list->count++;
}

void markTaskComplete(todoList *list) {
  int index;

  printw("Enter index of task to complete: ");
  refresh();
  scanw("%d", &index);
  noecho();

  if (index < 1 || index > list->count) {
    printf("Invalid index\n");
    return;
  }

  list->items[index - 1].completed = 1;
}

void deleteTask(todoList *list) {
  int index;
  clear();
  printw("Enter the index of the task to delete: ");
  refresh();
  scanw("%d", &index);
  noecho();

  if (index < 1 || index > list->count) {
    printw("Invalid index\n");
    return;
  }
  for (int i = index - 1; i < list->count - 1; ++i) {
    strcpy(list->items[i].task, list->items[i + 1].task);
    list->items[i].completed = list->items[i + 1].completed;
    list->items[i].priority = list->items[i + 1].priority;
  }
  list->count--;
}

void editTask(todoList *list) {
  int index;

  printw("Enter index of task to edit: ");
  refresh();
  scanw("%d", &index);
  noecho();

  if (index < 1 || index > list->count) {
    printf("Invalid index\n");
    return;
  }

  char newTask[maxLength];
  int newPriority;

  printw("Enter new task name: ");
  refresh();
  echo();
  getstr(newTask);
  noecho();

  printw("Enter new priority (1-5): ");
  refresh();
  echo();
  scanw("%d", &newPriority);
  noecho();

  if (newPriority < 1 || newPriority > 5) {
    printw("Invalid priority");
    return;
  }

  strcpy(list->items[index - 1].task, newTask);
  list->items[index - 1].priority = newPriority;
}

void searchTasks(todoList *list) {
  char searchTerm[maxLength];
  printw("Enter the search term: ");
  refresh();
  echo();
  getstr(searchTerm);
  noecho();

  int found = 0;
  clear();
  for (int i = 0; i < list->count; ++i) {
    char *ptr = strcasestr(list->items[i].task, searchTerm);
    if (ptr != NULL) {
      printw("%d. [%c] %s (Priority: %d)\n", i + 1,
             (list->items[i].completed ? 'x' : ' '), list->items[i].task,
             list->items[i].priority);
      found = 1;
    }
  }

  if (!found) {
    printw("No tasks found\n");
  }
  printw("\nPress any key to return to the menu...");
  refresh();
  getch();
}

void filterTasks(todoList *list) {
  int priority;
  int completed;

  printw("Enter priority level (1-5, 0 for all): ");
  refresh();
  echo();
  scanw("%d", &priority);
  noecho();

  printw("Enter completion status (0 for incomplete, 1 for completed, 2 for "
         "all): ");
  refresh();
  echo();
  scanw("%d", &completed);
  noecho();

  clear();
  int found = 0;
  for (int i = 0; i < list->count; ++i) {
    if ((priority == 0 || list->items[i].priority == priority) &&
        (completed == 2 || list->items[i].completed == completed)) {
      printw("%d. [%c] %s (Priority: %d)\n", i + 1,
             (list->items[i].completed ? 'x' : ' '), list->items[i].task,
             list->items[i].priority);
      found = 1;
    }
  }

  if (!found) {
    printw("No tasks matched the filter\n");
  }
  printw("\nPress any key to return to the menu...");
  refresh();
  getch();
}