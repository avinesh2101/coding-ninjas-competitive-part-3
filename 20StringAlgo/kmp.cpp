#include<iostream>
using namespace std;

int* getlps(string pattern )
{
    
    int len = pattern.length();
    int*lps = new int [len];
    lps[0]=0;
    int i=1;
    int j=0;

    while (i<len)
    {
        if(pattern[i]==pattern[j])
        {
            lps[i]=j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

bool kmp(string text,string pattern)
{
    int textlen = text.length();
    int patternlen = pattern.length();
int i=0;
int j=0;
int*lps = getlps(pattern);
// for(int i=0;i<pattern.length();i++)
// {
//     cout<<lps[i]<<" ";
// }
// cout<<endl;
    while(i<textlen && j<patternlen)
    {
        if(text[i] ==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];//ise phle jitna bhi pattern same hoga usme chle jaega

            }
            else            
            {
                i++;
            }
        }
    }
    return j==patternlen?true:false;
}
int main()
{
    string text="hiniggawashiup";
    string pattern = "fuckfuck";

    // cout<<kmp(text,pattern)<<endl;

    if(kmp(text,pattern)==true)
    {
        cout<<":yes";
    }   
    else{
        cout<<":no";
    }

}