#include<iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
    class Solution
    {public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    
    
    void dfs(int start,int n,vector<int> adj[],stack<int> &finishedStack,unordered_set<int> &visited)
    {
        visited.insert(start);
        for(int i=0;i<adj[start].size();i++)
        {
            if(visited.count(adj[start][i])==0)
            {
                dfs(adj[start][i],n,adj,finishedStack,visited);
            }
        }
        finishedStack.push(start);
    }
    void dfss(int start,unordered_set<int> visited,vector<int> edgesTranspose[],unordered_set<int> *component )
    {
        visited.insert(start);
        for(int i=0;i<edgesTranspose[start].size();i++)
        {
            if(visited.count(edgesTranspose[start][i])==0)
            {
                dfss(edgesTranspose[start][i],visited,edgesTranspose,component);
            }
        }
        component.insert(start);
    }
    
    int kosaraju(int V, vector<int> adj[]) {
        // step 1 make stack and do dfs and add complete verticies
        // step 2 do dfs on transpose  using stack 
        stack<int> finishedVerticies;
        unordered_set<int> visited;
        
        for(int i=0;i<V;i++)
        {
            if(visited.count(i)==0)
            {
                dfs(i,V,adj,finishedVerticies,visited);    
            }
            
        }
        
        
        vector<int> edgesTranspose[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                edgesTranspose[j].push_back(i);
            }
        }
        
        visited.clear();
        unordered_set< unordered_set<int>*>* output = new unordered_set< unordered_set<int>* >();
        
        
        while(finishedVerticies.size()!=0)
        { 
            int start = finishedVerticies.top();
            finishedVerticies.pop();
            if(visited.count(start)!=0)
            {
                continue;
            }
            unordered_set<int>* component = new unordered_set<int>();
            dfss(start,visited,edgesTranspose,component);
            output->insert(component);
        }
unordered_set<unordered_set<int>*>::iterator it = output->begin();
int ans =0;
while(it!=output->end())
{
    ans++;
}
        
        return ans;
        
    }

    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int V,E;
            cin>>V>>E;

            vector <int> adj[100];

            for(int i=0;i<E;i++)
            {
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
            }

            Solution obj;
            cout<< obj.kosaraju(V,adj)<<"\n";
        }
        return 0;
    }