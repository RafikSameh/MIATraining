#include "robots.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
            int temp=0;
Robots::Robots()
{

}

void Robots::addRobot()    //add robots to the array of robot
{
    cout<<"robots name "<<endl;
    cin>>Rname;
    int fnnums;
    cout<<"number of functions"<<endl;
    cin>>fnnums;
    for(int i=0;i<((fnnums*2)-1);i++)
    {
        cin>>functionID[i];

    }
    functioncheck(fnnums,functionID);
    cout<<"price per day"<<endl;
    cin>>PricePerDay;
}
void Robots::displayR()   //display the array of robot
{

    rented_dates(rented,rentdate);

    cout<<Rname<<"\t"<<PricePerDay<<"\t"<<functionID<<"\t"<<(bool)rented<<"\t";
        display_rented_dates(temp,rented,rentdate);
    cout<<endl;



}
string Robots::searchForRobot(string search,Robots robot[])    //search for robot by name in array of robots
{
    cout<<"search for "<<endl;
    cin>>search;
    for(int j=0;j<3;j++)
    {
        if (search == robot[j].Rname){
            robot[j].displayR();
        }
    }
}
void Robots::functioncheck(int fnnums,char functionID[]) //checks the wrong function ID
{
    for(int i=0;i<((fnnums*2)-1);i+=2)
    {
        if(((int)functionID[i]>'5') || ((int)functionID[i]<'1')){
            cout<<"in valid fn no."<<functionID[i]<<endl;

            cin>>functionID[i];
            while (functionID[i]>'5' || functionID[i]<'1') {
                cout<<"invalid fn "<<endl;
                cin>>functionID[i];
            }
        }
        else{
            continue;
        }
    }
}
void Robots::rented_dates(bool rented,string rentdate[])
{
    cout<<"is it rented?"<<endl;
    cin>>rented;
    if(rented != 1 && rented != 0){
        cout<<"error enter 1/0"<<endl;
        cin>>rented;
    }
    else{
    if(rented==1)
    {
        cout<<"how many times is it rented"<<endl;
        cin>>temp;
        cout<<"enter the rented dates"<<endl;
        for(int i=0;i<temp;i++)
        {
            cin>>rentdate[i];
        }
    }
    else{
        cout<<"no rented dates";
        rentdate[0]="0";
    }}

}
void Robots::display_rented_dates(int temp,bool rented,string rentdate[])
{
    for(int i =0;i<temp;i++)
    {
        if(rented==0){
            rentdate[0]="0";
            cout<<"no rented dates";
        }
        else{
            cout<<rentdate[i]<<",";
        }
    }

}
