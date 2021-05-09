#include<bits/stdc++.h>
using namespace std;

bool isbipartite(vector<int>* edges,int n)
{
    vector<int> pending;
    int set[n];
    for(int i=0;i<n;i++)
        set[i]=-1;
    int fl=0;
    for(int i=0;i<n;i++)
    {
        if(set[i]==-1)
        {
            pending.push_back(i);
            set[i]=0;
            while(!pending.empty())
            {
                int curr=pending.back();
                pending.pop_back();
                for(int j=0;j<edges[curr].size();j++)
                {
                    int nw=edges[curr][j];
                    if(set[nw]==-1)
                    { 
                     set[nw]=1-set[curr];
                     pending.push_back(nw);
                    }
                    else if(set[curr]==set[nw])
                        return false;
                   
                }
            }
        }
    }
    return true;
}

int rep(int x,int* parent)
{
    if(x!=parent[x])
        parent[x]=rep(parent[x],parent);
    return parent[x];
}


void unite(int x,int y,int *parent,int* rank)
{
    int px=rep(x,parent);
    int py=rep(y,parent);
    if(px==py)
        return;
    if(rank[px]<rank[py])
    {
        parent[px]=py;
    }
    else if(rank[py]<rank[px])
    {
        parent[py]=px;
    }
    else
    {
        parent[py]=px;
        rank[px]++;
    }
}

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n,q,x,y,val;
        cin>>n>>q;
        vector<int>* edges=new vector<int>[n];
        int parent[n];
        int rank[n]={0};
        for(int i=0;i<n;i++)
            parent[i]=i;
        int setcnt=0;
        int fl=0;
        for(int i=0;i<q;i++)
        {
            
            cin>>x>>y>>val;
            x--;
            y--;
            if(x==y and val ==1)
                fl=1;
            if(val==0)
            {
                unite(x,y,parent,rank);
            }
            else
            {
                edges[x].push_back(y);
            }
        }
        if(fl==1)
        {
            cout<<"no"<<"\n";
            continue;
        }
        vector<int>* nedges=new vector<int>[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<edges[i].size();j++)
            {
                int curr=edges[i][j];
                int p1=rep(i,parent);
                int p2=rep(curr,parent);
                if(p1==p2)
                {
                fl=1;
                break;
                }
                else
                {
                    nedges[p1].push_back(p2);
                    nedges[p2].push_back(p1);
                }
            }
            if(fl==1)
                break;
        }
        if(fl==1)
        {
            cout<<"no"<<"\n";
            continue;
        }
        if(isbipartite(nedges,n))
            cout<<"yes\n";
        else
            cout<<"no\n";
        delete [] edges;
        delete [] nedges;
    }
	return 0;
}