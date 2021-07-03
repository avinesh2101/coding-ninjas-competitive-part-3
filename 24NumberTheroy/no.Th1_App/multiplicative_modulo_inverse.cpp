#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
    int x;
    int y;
    int gcd;
};

Triplet extendedEuclid(int a,int b)
{
    //base case
    if(b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    //Extended Euclid algorithm
    Triplet smallAns = extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x -(a/b)*smallAns.y;
    return ans;
}

int multplicative_modulo_inverse(int a,int m)
{
    Triplet ans = extendedEuclid(a,m);
    return ans.x;
}
int main()
{

    int a =15;
    int b=10;//m in case of mmi
//-----multiplicative modulo inverse-------
    int ans  = multplicative_modulo_inverse(a,b);
    cout<<"multiplicative modulo inverse is "<<ans<<endl;   

    // Triplet ans = extendedEuclid(a,b);//ax+by = gcd(a,b) ->given
    //                                 // calculate x,y
    //                                 //for this we use Extended gcd algorithm
    // cout<<"gcd:"<<ans.gcd<<"\n";
    // cout<<"x value:"<<ans.x<<" y-value:"<<ans.y<<"\n";
    return 0;
}