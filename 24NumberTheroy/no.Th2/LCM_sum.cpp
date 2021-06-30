/*LCM SUM
Send Feedback
Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
Line 1 : Integer n
Output Format :
Required sum
Constraints :
1 <= T <= 300000
1 <= n <= 1000000
Sample Input 1 :
5
Sample Output 1 :
55
Sample Input 2 :
2
Sample Output 2 :
4*/
#include<bits/stdc++.h>
using ll= long long;


// O(N logN)
void func(long long n)
{
	// Write your code here
    ll ans = 0;
    
    for(ll i=1;i<=n;i++)
    {
        ll temp = __gcd(i, n);//stl gcd
        ans += (i*n) / temp ;
    }
    cout<<ans<<endl;
}


//  O(N log log(n))
// ------------------------------------------------

long long * precal(long long * res, long long * phi, long long n) {
  for (long long i = 1; i <= n; ++i) phi[i] = i;
  
  for (long long i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] /= i;
        phi[j] *= i - 1;
      }
    }
  }

  for (long long i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) res[j] += (i * phi[i]);
  }
  return phi;
}

void func(long long n) {
  long long * res = new long long[1000010];
  long long * phi = new long long[1000010];
  phi = precal(res, phi, 1000000);
  long long ans = res[n] + 1;
  ans *= n;
  ans /= 2;
  printf("%lld\n", ans);
}