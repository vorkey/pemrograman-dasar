#include "plant.h"
#include "user.h"
#include <sqlite3.h>
#include <string>
#include <vector>

class Database {
private:
  sqlite3 *db;

public:
  Database();
  ~Database();
  bool connect;
  void createTables();
  bool registerUser(const std::string &username, const std::string password,
                    const std::string role);
  bool loginUser(const std::string &username, const std::string password,
                 User &loggedInUser);

  void addPlant(const Plant &plant);
  std::vector<Plant> getPlants(int user_id);
  void updatePlant(const Plant &plant);
  void deletePlant(int plant_id);
};