#include <iostream>
#include "robots.h"
#include "users.h"
#include <string.h>
#include <vector>


using namespace std;

int main()
{
    int q;
    cout<<"welcome Amin to robot Rental system"<<endl;
    cout<<"Main menu: "<<endl;
    cout<<"\t\t 1.Add robot \n\t\t 2.Add user \n\t\t 3.Display all robots \n\t\t 4.Display all users \n\t\t 5.Search for robot by name \n\t\t 6.Search for user by name \n\t\t 7.Rent robot \n\t\t 8.EXIT\n";


    int i=0;
    string search,userSearch;
    bool rented ;
    string rentdate[10];



    Robots robot[3];

    users user[3];
/*    user[0].username="mohamed";
    user[0].email="mohamedmm@gmail.com";
    user[0].phoneNumber="01274064331";
    user[1].username="rafik";
    user[1].email="rafiksameh12@gmail.com";
    user[1].phoneNumber="01559971009";
    user[2].username="ahmed";
    user[2].email="ahmedmmaa@gmail.com";
    user[2].phoneNumber="015155458233";
*/
while(1){
    cout<<"choose from main menu"<<endl;
        cin>>q;
    switch(q)
    {

    case 1: //add robot
        int num_robots;
        cout<<"how many robots will you add?"<<endl;
        cin>>num_robots;
        for(int i=0;i<num_robots;i++){
            robot[i].addRobot();
        }

        break;


    case 2:  //add user
        int num_users;
        cout<<"how many users will you add?"<<endl;
        cin>>num_users;
        for(int i=0;i<(num_users);i++){
            user[i].addUser();
        }

            break;

    case 3:    //display all robots
        for(i=0;i<3;i++){
            robot[i].displayR();
        }
            break;
    case 4:     //display all users
        for(i=0;i<3;i++){
            user[i].displayUsers();
        }
            break;
    case 5:     //search for robot by name
        robot[2].searchForRobot(search,robot);
            break;

    case 6:     //search for user by name
        user[2].searchForUser(userSearch,user);
            break;

    case 7:     //rent robot to user   // not completed
        for(i=0;i<2;i++){
            robot[i].rented_dates((bool)rented,rentdate);
        }
        break;
    case 8:   //exit
        return 0;


}}
    return 0;
}
