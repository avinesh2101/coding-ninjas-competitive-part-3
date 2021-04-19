#include<bits/stdc++.h>
using namespace std;
void magic(int**edges_btw_verticies,int*visited,int start,int n)
{
    cout<<start<<" ";
    visited[start]=1;
    for(int i=0;i<n;i++)
    {
        if(i==start)
        {
            continue;
        }
        if(edges_btw_verticies[start][i]==1)
        {
            if(visited[i]==1){
                continue;
            }
            magic(edges_btw_verticies,visited,i,n);
        }
    }


}

int main()
{
    int n,E;//no. of verticies and no. of edges
    cin>> n>>E;

    int**edges_btw_verticies = new int*[n];
    for(int i=0;i<n;i++)
    {

        edges_btw_verticies[i] = new int [n];
        for(int j=0;j<n;j++)
        {
            edges_btw_verticies[i][j]=0;
        }
    }

    for(int i=0;i<E;i++)
    {
        int f,s;
        cin>>f>>s;
        edges_btw_verticies[f][s]=1;
        edges_btw_verticies[s][f]=1;
    }
    int*visited = new int[n];

    for(int i=0;i<n;n++)
    {
        visited[i]=0;
    }

    magic(edges_btw_verticies,visited,0,n);

    return 0;
} 
