#include<bits/stdc++.h>
using namespace std;
//modExp recursive    T.C O(logn)
int pow(int a,int b,int c)
{
    if(a==0) return 0;

    if(b==0) return 1;

    //b is even
    if(b%2 == 0)
    {
        long smallAns = pow(a,b/2,c);
        long ans = (smallAns*smallAns)%c;
        // return int(ans);//to handle negative integers we added c and then did modulo
        return int((ans+c)%c);

    }//b is odd
    else{
        long smallAns = pow(a,(b-1)/2,c);
        long ans = a % c;//bringing it down to the range of c as ans can be lrger then c
        ans  = (ans*smallAns*smallAns)%c;
        return int((ans+c)%c);  
    }
}

// mod exp - iterative way
int modExp(int a,int b,int c)
{
    long ans=1;
    //based on breaking b into binomial representation and then using that to solve the problem
    while(b!=0)
    {
        if(b&1 == 1)//rightmost bit is set or is 1
        {
            // then multilply with a ki power that thing
            ans = (ans*a)%c;
        }
        a = (a*a)%c;
        b = b/2;


    }

    return ans;
}
int main()
{
    int a,b,c;
    c = 1e9+7;
    cin>>a>>b>>c;
    cout<<pow(a,b,c)<<endl;
}
//e.g a =2 b = 10 c =5
//ans = 4 as 2^10 is 1024 and 1024%5=4