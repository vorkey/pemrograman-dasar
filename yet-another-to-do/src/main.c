#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"
#include "todolist.h"

void printList(todoList *list, int page, int pageSize) {
  int start = (page - 1) * pageSize;
  int end = start + pageSize - 1;

  if (end >= list->count) {
    end = list->count - 1;
  }

  for (int i = start; i <= end; ++i) {
    if (list->items[i].completed) {
      attron(COLOR_PAIR(1));
    } else {
      attron(COLOR_PAIR(2));
    }

    printw("%d. [%c] %s (Priority: %d)\n", i + 1,
           (list->items[i].completed ? 'x' : ' '), list->items[i].task,
           list->items[i].priority);
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
  }
}

int main(int argc, char *argv[]) {
  todoList todolist;
  initializeTodoList(&todolist);

  int pageSize = 10;
  if (argc > 1) {
    pageSize = atoi(argv[1]);
  }

  initscr();
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, 15, COLOR_BLACK);
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  char fileName[] = "tasks.txt";
  loadFromFile(&todolist, fileName);

  int choice;
  int page = 1;

  do {
    clear();
    attron(COLOR_PAIR(3));
    printw("----Manage Your Task----\n");
    printw("------------------------\n");
    attroff(COLOR_PAIR(3));
    printList(&todolist, page, pageSize);

    printw("\n\n");
    attron(COLOR_PAIR(3));
    printw("1. Add new task \n");
    printw("2. Mark as completed \n");
    printw("3. Delete task \n");
    printw("4. Edit task \n");
    printw("5. Search task \n");
    printw("6. Filter tasks \n");
    printw("7. Save and quit \n");
    printw("p. Previous page \n");
    printw("n. Next page \n");
    printw("Enter your choice: ");
    refresh();

    echo();
    scanw("%d", &choice);
    refresh();

    switch (choice) {

    case 1:
      addNewTask(&todolist);
      break;
    case 2:
      markTaskComplete(&todolist);
      break;
    case 3:
      deleteTask(&todolist);
      break;
    case 4:
      editTask(&todolist);
      break;
    case 5:
      searchTasks(&todolist);
      echo();
      refresh();
      break;
    case 6:
      filterTasks(&todolist);
      echo();
      refresh();
      break;
    case 7:
      saveToFile(&todolist, fileName);
      break;
    case 'p':
      if (page > 1) {
        page--;
      }
      break;
    case 'n':
      if (page < (todolist.count + pageSize - 1) / pageSize) {
        page++;
      }
      break;
    default:
      printw("Invalid choice\n");
      echo();
      refresh();
      break;
    }
    refresh();
  } while (choice != 7);

  endwin();
  return 0;
}