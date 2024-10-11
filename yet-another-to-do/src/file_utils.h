#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "todolist.h"

void saveToFile(todoList *list, const char *filename);
void loadFromFile(todoList *list, const char *filename);

#endif