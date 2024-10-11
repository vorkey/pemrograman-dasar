#ifndef TODOLIST_H
#define TODOLIST_H

#define maxItems 100
#define maxLength 100

typedef struct {
  char task[maxLength];
  int completed;
  int priority;
} todoItem;

typedef struct {
  todoItem items[maxItems];
  int count;
} todoList;

void initializeTodoList(todoList *list);
void addNewTask(todoList *list);
void markTaskComplete(todoList *list);
void deleteTask(todoList *list);
void editTask(todoList *list);
void searchTasks(todoList *list);
void filterTasks(todoList *list);

#endif