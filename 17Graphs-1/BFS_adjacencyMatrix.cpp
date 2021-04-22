#include <iostream>
#include<queue>
using namespace std;
void printBFS(int**edges,int start,int n,bool*visited)
{
    queue<int> temp;
   // bool*visited = new bool[n];
    // for(int i=0;i<n;i++){visited[i]=false; }
    
    temp.push(start);
    visited[start] = true;
    
  while(!temp.empty() )
  {
      int currentVertex=temp.front();
      temp.pop();
      cout<<currentVertex<<" ";
      for(int i=0;i<n;i++)
      {
          // if(i==currentVertex){
          //     continue;   
          // }// ignoring from checking  zero adjacent to zero like things
         
          if(edges[currentVertex][i] == 1 && !visited[i])
          {
              temp.push(i);
              visited[i]=true;
              
          }
    
      }
      
  }
}

int main() {
  
    int n ,e;
    cin>>n>>e;
    if(n==0 && e==0)
    {
        return 0;
    }

    int** edges = new int*[n];
  for(int i=0; i<n; i++){
    edges[i]=new int[n];
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }

  for(int i=0; i<e; i++){//this means edge btw f and s
    int f,s;
    cin >> f >> s; 
    edges[f][s]=1;
    edges[s][f]=1;
  }
    
    bool*visited = new bool[n];//we are making a visited array in main function to get the BFS for in case of more than one component
  for(int i=0;i<n;i++){visited[i]=false; }
    for(int i=0;i<n;i++){
        if(!visited[i]){//i is start
            printBFS(edges,i,n,visited);
        }
    }
    
  
    
    
}