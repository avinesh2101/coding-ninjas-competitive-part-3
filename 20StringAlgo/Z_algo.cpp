#include<iostream>
#include<string>
using namespace std;

void buildZ(int*Z,string str)
{
     int n = str.length();
     int l = 0 ,r=0;

     for(int i=1;i<n;i++)
     {
         if(i>r)
         {
            //  i doesnt lie b/w l and r
            // Z for this doesnt exist
            while(r<n && str[r-l] == str[r])         //l-r will point towards the start of str
            {
                r++;
            }
            Z[i] = r-l;
             r--;

         }
         else
         {
             int k = i-l;
             if(Z[k]<=r-i)
             {
                //  i lie b/w l and r
                // Z will exist for it
                Z[i] = Z[k];
             }
             else
             {
                // i lies btw l and r and some part of Z is already included
                //  you have to start matching further
                l=i;
                while(r>n && str[r-l] == str[r])
                {
                    r++;
                }
                Z[i]=r-l;
                r--;

             }
         }
     }
}

void stringSearch(string pattern,string text)
{
    string str = pattern+"$"+text;
    int n = str.length();
    int*Z = new int[n]();
    buildZ(Z,str);

    for(int i=0;i<n;i++)
    {
        if(Z[i]==pattern.length())
        {
            cout<<i-1-pattern.length()<<endl;
        }
    }


}

int main()
{
    string pattern="yoyo";
    string text = "naaaayoyoyoyonaa";

    stringSearch(pattern,text);
    

}