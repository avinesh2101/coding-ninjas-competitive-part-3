#include<iostream>
using namespace std;
// Φ(n) = Euler totient function of n
// Φ(a,b) = Φ(a)*Φ(b)  only when gcd(a,b) =1
//using this we will get Φ(n)
// n can be represented in the form of prime factors as 2^a 3^b 5^c..... so on
// and gcd of primes or their power will always be 1
// so we end up on formula 
//   Φ(n) = n*(1-1/p1)*(1-1/p2)*(1-1/p3)*.......*(1-1/pk)
// now implementing this using sieve we get

// sieve can be used as make an array and fill it as a[i] = i
// if a[i] = i then it is prime now multipy all its multiple with (1-1/i)
// and we are done

int magic(int n)
{
    int*arr = new int[n+3];
    for(int i=0;i<=n;i++)
    {
        arr[i] = i;
    }

    for(int i=2;i<=n;i++)
    {
        if(arr[i] == i)//i.e prime so mulltipy all its multiple with (1-1/i) //and its ans will be i-1 as it is prime so its gcd with all no. smaller then it is 1 
        {
            arr[i] = i-1;
            for(int j=2*i;j<=n;j+=i)
            {
                arr[j] = (arr[j] * (i-1) )/i;
            }
        }
    }

    return arr[n];
}

int main()
{
    int n;
    cin>>n;

    cout<<"Euler totient of "<<n<<" is :"<<magic(n)<<endl;
}


/*#include<iostream>
using namespace std;


void eulerPhi(int n){

	int phi[n+1];

	for(int i=1;i<=n;i++){
		phi[i] = i;
	}

	for(int i=2;i<=n;i++){
		if(phi[i] == i){
			phi[i] = i-1;
			for(int j=2*i;j<=n;j+=i){
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}

	for(int i=1;i<=n;i++){
		cout << "Euler Totient Phi For " << i << "Is :" << phi[i]<<endl;
	}

}
int main(){

	eulerPhi(10);
	return 0;
}*/