/*Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :*/

#include <iostream>
#include<map>
#include<queue>
using namespace std;
void getPathBFS(int**edges,bool*visited,int current_element,int find_value,int n)
{
   
    map<int,int>ans; //it stores value and its parent value so that when we find our value woth bfs we can write the path by which we reached here
    //  value parent         
    queue<int>remaining_verticies;//for normal bfs
    remaining_verticies.push(current_element);
    visited[current_element] = true;
    ans[current_element]=-1;//map
    
    while(!remaining_verticies.empty())
    {
    
        int current = remaining_verticies.front();
        if(current == find_value)
        {
            break;
        }
        remaining_verticies.pop();
        
        for(int i=0;i<n;i++)
        {
            if(edges[current][i]==1 && !visited[i] && i!=current)
            {
                remaining_verticies.push(i);
                visited[i]=true;
                ans[i]=current;    //map
                if(i==find_value){
                    break;
                }
                
            }
        }
        
        if(remaining_verticies.empty())
        {
            return;
        }
        
    }
    
    // int i=find_value;
    // cout<<find_value<<" ";
    // while(i!=current_element)
    // {
    //     cout<<ans[i]<<" ";
    //     i=ans[i];
    // }

    
    
    auto itr = ans.find(find_value);
if(itr != ans.end())
{
    if(itr->second==-1)
  		  {
        cout<<current_element;
        return;
         } 
    else
    {
        vector<int>ans1;
        ans1.push_back(find_value);
    	while(itr->second!= -1)
        {
            ans1.push_back(itr->second);
            itr=ans.find(itr->second);
        }
      for(int i=0;i<ans1.size();i++)
       {
           cout<<ans1[i]<<" ";
       }
        
        
         
    }
}
   
    else{
        return ;
    }
    
    
    
    
}
int main() {
    // Write your code here
    int  n,e;
    cin>>n>>e;
    
    int**edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new int [n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    
    bool*visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    
    while(e--)
    {
        int a,b;
        cin>>a;
        cin>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    
    int start,findValue;
    cin>>start>>findValue;
    getPathBFS(edges,visited,start,findValue,n);
}