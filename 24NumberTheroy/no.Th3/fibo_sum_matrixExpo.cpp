#include<iostream>
#include<cstring>
using namespace std;
#define mod 1000000007
#define ll unsigned long long


inline void multiply(ll mat1[2][2], ll mat2[2][2])
{
    ll new_mat[2][2] = {
        {(((mat1[0][0])%mod * (mat2[0][0])%mod)%mod + ((mat1[0][1])%mod * (mat2[1][0])%mod)%mod)%mod,
         (((mat1[0][0])%mod * (mat2[0][1])%mod)%mod + ((mat1[0][1])%mod * (mat2[1][1])%mod)%mod)%mod},
        {(((mat1[1][0])%mod * (mat2[0][0])%mod)%mod + ((mat1[1][1])%mod * (mat2[1][0])%mod)%mod)%mod,
         (((mat1[1][0])%mod * (mat2[0][1])%mod)%mod + ((mat1[1][1])%mod * (mat2[1][1])%mod)%mod)%mod}};
    mat1[0][0] = new_mat[0][0]%mod;
    mat1[0][1] = new_mat[0][1]%mod;
    mat1[1][0] = new_mat[1][0]%mod;
    mat1[1][1] = new_mat[1][1]%mod;
}
inline void power(ll mat[2][2], ll n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    power(mat, n / 2);
    multiply(mat, mat);
    if (n % 2 != 0)
    {
        ll temp[2][2] = {{1, 1}, {1, 0}};
        multiply(mat, temp);
    }
}
inline ll fib(ll n)
{
    ll mat[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
    {
        return 0;
    }
    power(mat, n - 1);
    return mat[0][0]%mod;
}
inline unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
    return (fib(n + 2)%mod - fib(m + 1)%mod+mod)%mod;
}


int main()
{
    unsigned long long m,n;
    cin>>m>>n;
	cout<<fiboSum(m,n);
    return 0;
}
