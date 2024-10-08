#include <string>
class User {
public:
  int id;
  std::string username;
  std::string password;
  std::string role;

  User(std::string username, std::string password, std::string role);
};