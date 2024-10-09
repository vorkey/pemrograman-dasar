#include "database.h"
#include <iostream>
Database::Database() {
  connect();
  createTables();
}

bool Database::connect() {
  if (sqlite3_open("flowerdb.db", &db) != SQLITE_OK) {
    std::cerr << "Error opening database\n";
    return false;
  }
  return true;
}

Database::createTables() {
  .
}