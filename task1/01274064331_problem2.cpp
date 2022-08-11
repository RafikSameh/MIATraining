#include <iostream>

using namespace std;

int main()
{
    int q=0,hp=0,p=0,h=0;
    int i=0,j=0,z=0;
    cin >> q;
    string arr[q];
    for(i=0;i<q;i++){
        cin>>hp;
        cin>>p;
        cin>>h;
        for(j=0;j<p;j++){
            hp=(hp/2)+10;
        }
        for(z=0;z<h;z++){
            hp-=10;
        }
        if(hp<=0){
            arr[i]="YES \n";
        }
        else{
            arr[i]="NO \n";
        }

    }
    for(i=0;i<q;i++){
        cout<<arr[i];
    }
    return 0;
}
