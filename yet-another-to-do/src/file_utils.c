#include "file_utils.h"
#include <stdio.h>

void saveToFile(todoList *list, const char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp != NULL) {
    for (int i = 0; i < list->count; i++) {
      fprintf(fp, "%d, %s, %d\n", list->items[i].completed, list->items[i].task,
              list->items[i].priority);
    }
    fclose(fp);
  } else {
    perror("Error opening file");
  }
}

void loadFromFile(todoList *list, const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp != NULL) {
    list->count = 0;
    while (fscanf(fp, "%d, %[^,], %d\n", &list->items[list->count].completed,
                  list->items[list->count].task,
                  &list->items[list->count].priority) == 3) {
      list->count++;
      if (list->count >= maxItems) {
        break;
      }
    }
    fclose(fp);
  } else {
    perror("Error opening file");
  }
}