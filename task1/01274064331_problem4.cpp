#include <iostream>

using namespace std;

int main()
{
    int i,j,q,z,num,seenNum=1;
    cin>>q;
    for(z=0;z<q;z++){
        cin>>num;
        int arr[num];
        int seen[num]={0};
    for(i=0;i<num;i++){
        cin>>arr[i];
    }
    for(i=0;i<num;i++){
        if(i==num-1){
            seen[i]=0;
        }
        else if(arr[i]<arr[i+1] || i==num-2){
            seen[i]=1;
        }
        else if(arr[i]>arr[i+1]){
            seenNum=1;
            seen[i]=1;
            for(j=i+1;j<num-1;j++){
                if(arr[j]<arr[j+1]){
                    seenNum++;
                    seen[i]=seenNum;
                    if(arr[i]<arr[j+1]){
                        break;
                    }
                }
            }
        }
    }
    for(i=0;i<num;i++){
        cout<<seen[i]<<" ";
    }
    cout<<"\n";
}

    return 0;
}
