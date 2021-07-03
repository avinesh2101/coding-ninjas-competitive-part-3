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
int main()
{

    int a =15;
    int b=10;
    Triplet ans = extendedEuclid(a,b);//ax+by = gcd(a,b) ->given
                                    // calculate x,y
                                    //for this we use Extended gcd algorithm
    cout<<"gcd:"<<ans.gcd<<"\n";
    cout<<"x value:"<<ans.x<<" y-value:"<<ans.y<<"\n";
    return 0;
}