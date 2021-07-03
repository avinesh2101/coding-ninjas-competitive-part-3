#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cubes[1000000];
void magic()
{
    int k=1;
    cubes[1]=1;
    cubes[0] = -1;
    for(int i = 2;i<=100;i++)//100 ka cube 1000000
    {
        int j = i*i*i;
        for( j = i*i*i;j<=1000000;j+=i*i*i)
        {
            cubes[j] = -1;
        }
       
       
    }
    
    for(int i =1;i<=1000000;i++)
    {
         if(cubes[i]!=-1)
        {
            cubes[i]=k;
        	k++;
        }
    }
}
int main(){
	// Write your code here
    //we have to find cube free no.  so we areae going to 
    // use something like sieve 
    // to do so 
    // just start from 2 and mar its cube as not cube free and eg 2^3 is 8 then 8+8 ,16+8,24+8 as not cube free
    memset(cubes,0,sizeof(cubes));
    int t;
    cin>>t;
    magic();
    int c =1;
    while(t--)
    {
        int n;
        cin>>n;
        
        cout<<"Case "<<c<<": ";
        if(cubes[n] == -1)
        {
            cout<<"Not Cube Free"<<endl;
        }
        else
        {
            cout<<cubes[n]<<endl;
        }
        c++;
    }
	return 0;
}