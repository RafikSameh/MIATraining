#ifndef ROBOTS_H
#define ROBOTS_H
#include <string>
#include <vector>

using namespace std;


class Robots
{
public:

    string Rname;
    int PricePerDay;
    bool rented;
    char functionID[9]={0};
    int date;
    string rentdate[10]={"0"};



public:
    void addRobot();
    void displayR();
    string searchForRobot(string search,Robots robot[]);
    void functioncheck(int fnnums,char functionID[]);
    void rented_dates (bool rented,string rentdate[]);
    void display_rented_dates(int temp,bool rented,string rentdate[]);

    Robots();
};

#endif // ROBOTS_H
