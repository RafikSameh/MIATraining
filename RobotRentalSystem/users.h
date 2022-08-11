#ifndef USERS_H
#define USERS_H
#include <string>

using namespace std;


class users
{
public:
    string username;
    string phoneNumber;
    string email;
    string robotsRented;

public:
    void addUser();
    void displayUsers();
    string searchForUser(string userSearch,users user[]);

    users();
};

#endif // USERS_H
