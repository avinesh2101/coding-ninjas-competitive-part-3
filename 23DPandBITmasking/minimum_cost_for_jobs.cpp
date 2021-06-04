#include<iostream>
using namespace std;

//-----------------------------------iterative------------------------------------
int iterativeMinCost(int cost[][4],int n)
{
    int *dp=new int [1<<n];
    for(int i=0; i<(1<<n); i++)
    {
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(int mask=0; mask<(1<<n)-1; mask++)
    {
        //now we have to count the number of set bits
        int temp=mask;
        int k=0;
        while(temp>0)
        {
            if(temp%2==1)
            {
                k++;
            }
            temp/=2;
        }
        for(int j=0; j<n; j++)
        {
            if(!(mask&(1<<j)))
            {
                dp[mask|(1<<j)]=min(dp[mask|(1<<j)], dp[mask]+cost[k][j]);
            }
        }
    }
    return dp[(1<<n)-1];
}



//------------------------------recursive+memoization------------------
int minCost(int cost[4][4] , int n,int p,int mask,int*dp)
{//p person
    if(p>=n)
    {
        return 0;
    }


    if(dp[mask] != INT_MAX)
    {
        return dp[mask];
    }
        int minimum = INT_MAX;
    for(int j=0;j<n;j++)
    {
        if( !( mask & (1<<j) ) )//check jTH bit if it is not set than go ahead and set it
        {
            
            int ans = minCost(cost,n,p+1,(mask || (1<<j)),dp) +  cost[p][j];
             //setting jTH bit and then sending for further process (mask)  
         if(ans < minimum)
        {
            minimum = ans;
        }  

        }                              
                                 
    }

    dp[mask] = minimum;
    return minimum;

}

int main()
{
    int cost[4][4] = {{10,2,6,5},
                      {1,15,12,8},
                      {7,8,9,3},
                      {15,13,4,10}
                      };

    int*dp = new int[1<<4];//1*2^4 or 2^n size
     for(int i=0;i<(1<<4);i++)
     {
         dp[i] = INT_MAX;
     }


     cout<<minCost(cost,4,0,0,dp)<<endl;

}
