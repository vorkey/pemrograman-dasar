#include <string>
class Plant {
public:
  int id;
  std::string name;
  std::string type;
  std::string date_planted;
  std::string watering_schedule;
  std::string notes;
  int user_id;

  Plant(std::string name, std::string type, std::string date_planted,
        std::string watering_schedule, std::string notes, int user_id);
};