#include <bits/stdc++.h>

using namespace std;

int main()
{

    int q,z,i;
    char c;
    cin>>q;
    for(z=0;z<q;z++)
    {
        string s;
        cin>>s;
        int n=s.length();
        for(i=0;i<n;i++)
        {
            if(s[i+2]=='&'){
                if(s[i]=='1'){
                    c=s[i+1]+58;
                    cout<<c;
                }
                else{
                    char c =s[i+1]+68;
                    cout<<c;
                }
                i+=2;
            }
            else{
                c=s[i]+48;
                cout<<c;
            }
        }
        cout<<endl;
    }
    return 0;
}
