#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxItems 100
#define maxLength 50

typedef struct {
  char task[maxLength];
  int completed;
} todoItem;

typedef struct {
  todoItem items[maxItems];
  int count;
} todoList;

void saveToFile(todoList *list, const char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp != NULL) {
    for (int i = 0; i < list->count; i++) {
      fprintf(fp, "%d, %s\n", list->items[i].completed, list->items[i].task);
    }
  } else {
    perror("Error opening file");
    return;
  }
  fclose(fp);
}

void loadFromFile(todoList *list, const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp != NULL) {
    list->count = 0;
    while (fscanf(fp, "%d, %[^\n]\n", &list->items[list->count].completed,
                  list->items[list->count].task) == 2) {
      list->count++;
      if (list->count >= maxItems) {
        break;
      }
    }
  } else {
    printf("Error opening file");
    return;
  }
  // fclose(fp);
}

void addItem(todoList *list, const char *task) {
  if (list->count >= maxItems) {
    printf("Max items reached, please complete your previous tasks.");
    return;
  } else {
    strcpy(list->items[list->count].task, task);
    list->items[list->count].completed = 0;
    list->count++;
  }
}

void deleteItem(todoList *list, int index) {
  if (index < 0 || index >= list->count) {
    printf("Invalid index\n");
    return;
  } else {
    for (int i = index; i < list->count - 1; ++i) {
      strcpy(list->items[i].task, list->items[i + 1].task);
      list->items[i].completed = list->items[i + 1].completed;
    }
    list->count--;
  }
}

void markComplete(todoList *list, int index) {
  if (index < 0 || index >= list->count) {
    printf("Invalid index\n");
    return;
  } else {
    list->items[index].completed = 1;
  }
}

void printList(todoList *list) {
  for (int i = 0; i < list->count; ++i) {
    printw("%d. [%c] %s\n", i + 1, (list->items[i].completed ? 'x' : ' '),
           list->items[i].task);
  }
}

int main() {
  todoList todolist;
  todolist.count = 0;

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  char fileName[] = "tasks.txt";
  loadFromFile(&todolist, fileName);

  int choice;

  char newTask[maxLength];

  do {
    clear();
    printw("----Manage Your Task----\n");
    printw("------------------------\n");
    printList(&todolist);

    printw("\n\n");
    printw("1. Add new task \n");
    printw("2. Mark as completed \n");
    printw("3. Delete task \n");
    printw("4. Save and quit \n");
    printw("Enter your choice: ");
    refresh();

    echo();
    scanw("%d", &choice);
    refresh();

    switch (choice) {
      int indexChoice;
    case 1:
      clear();
      printw("Add new task: ");
      refresh();
      echo();
      getstr(newTask);
      noecho();
      addItem(&todolist, newTask);
      break;

    case 2:
      clear();
      printw("Enter index of task to complete: ");
      refresh();
      scanw("%d", &indexChoice);
      noecho();
      markComplete(&todolist, indexChoice - 1);
      break;
    case 3:
      clear();
      printw("Enter the index of the task to delete: ");
      refresh();
      scanw("%d", &indexChoice);
      deleteItem(&todolist, indexChoice - 1);
      break;
    case 4:
      saveToFile(&todolist, fileName);
      break;
    default:
      printw("Invalid choice\n");
      break;
    }
    refresh();
  } while (choice != 4);

  endwin();
  return 0;
}