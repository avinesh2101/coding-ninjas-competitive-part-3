// //fibonacci of n in O(logN)
#include<iostream>
using namespace std;
void multiply(int a[][2],int b[][2])
{
    int first_value = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    int second_value = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    int third_value = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    int  fourth_value = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    a[0][0] = first_value;
    a[0][1] = second_value;

    a[1][0] = third_value;
    a[1][1] = fourth_value;
}
void power(int A[][2],int n)
{
    if(n==1)
    return ;

    power(A,n/2);

    multiply(A,A);
    //odd
    if(n%2 != 0)
    {
        int F[2][2] = {{1,1},{1,0}};
        multiply(A,F);
    }
}

int getFibo(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
        int A[2][2] = {{1,1},{1,0}};
        power(A,n-1);
        return A[0][0];
}

int main()
{
    int n;
    cin>>n;
    cout<<getFibo(n)<<endl;
    return 0;
}




// int getFibo(int n){
// 	if(n==0 || n==1){
// 		return n;
// 	}
// 	int A[2][2] = {{1,1},{1,0}};
// 	power(A,n-1);
// 	return A[0][0];
// }
// int main(){
// 	int n;
// 	cin >> n;
// 	cout << getFibo(n)<<endl;
// 	return 0;
// }