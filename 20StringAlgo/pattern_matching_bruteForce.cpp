#include<iostream>
#include<string>
using namespace std;

bool isMatching(string a,string b)
{
	int n=a.size();
	int m=b.size();

	for(int i=0;i<n-m;i++)
	{
		bool isFound = true;
		for(int j=0;j<m;j++)
		{
			if(a[i+j]!=b[j])
			{
				isFound=false;
				break;
			}

		}

        if(isFound==true)
	{
		return true;
	}
	}
		return false;
	
}



int main()
{

	string a,b;
	cin>>a>>b;

	cout<<isMatching(a,b)<<endl;
}

