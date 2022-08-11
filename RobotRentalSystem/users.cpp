#include "users.h"
#include <iostream>

using namespace std;


users::users()
{

}
void users::addUser()
{
    cout<<"user's name "<<endl;
    cin>>username;
    cout<<"phone number : "<<endl;
    cin>>phoneNumber;
    cout<<"email address : "<<endl;
    cin>>email;

}
void users::displayUsers()
{
    cout<<username<<"\t"<<phoneNumber<<"\t"<<email<<"\t"<<robotsRented<<endl;
}
string users::searchForUser(string userSearch,users user[])
{
    cout<<"search for "<<endl;
    cin>>userSearch;
    for(int j=0;j<3;j++)
    {
        if (userSearch == user[j].username){
            user[j].displayUsers();
        }
    }
}
