#include <iostream>
#include<queue>
using namespace std;
// --------------------------dfs-----------------------
bool haspath(int**edges,bool*visited,int n,int a,int b)//a is start do bfs or dfs from that
{
    queue<int> temp;
    temp.push(a);
    
	while(!temp.empty())
    {
        int current = temp.front();
        visited[current] = 1;
        temp.pop();
        if(current==b){
            return true;
        }
        
        for(int i=0;i<n;i++)
        {
            if(current == i){ continue;}
            
            if(edges[current][i]==1 && !visited[i])
            {
                temp.push(i);
                visited[i] = 1;
                
            }
        }
    }
    return false;
    
}

// --------------------------bfs-----------------------
//  bool haspath(int** arr, bool* visited, int v, int current_vertex, int v2)
// {
// 	if (current_vertex == v2)
// 	{
// 		return true;
// 	}
     
// 	for (int i = 0; i < v; i++)
// 	{
// 		if (!visited[i] && i != current_vertex && arr[current_vertex][i]==1)
// 		{
// 			visited[i] = true;
            
// 			if (haspath(arr,  visited,v, i, v2))
// 			{
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }
int main() {
//     int n,e;
//     cin>>n>>e;
    
//     int** edges =new int*[n];
//     for(int i=0;i<n;i++)
//     {
//         edges[i] = new int[i];
//         for(int j=0;j<n;j++){
//             edges[i][j] = 0;
//         }
//     }
    
    
//     for(int i=0;i<e;i++)
//     {
//         int f;
//         int s;
//         cin>>f>>s;
//         edges[f][s]=1;
//         edges[s][f]=1;
//     }
//     int a,b;
//     cin>>a>>b;
//     bool*visited=new bool[n];
//     for(int i=0;i<n;i++){ visited[i] =0 ;}//memeset(visited,0);
//     visited[a]=1;
//     if(haspath(edges,visited,n,a,b))//in this case a will be start 
//     {
//         cout<<"true";
//     }
//     else{
//         cout<<"false";
//     }
//  return 0;   
    
    int v, e;
	cin >> v >> e;
	int** arr = new int* [v];
	for (int i = 0; i < v; i++)
	{
		arr[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			arr[i][j] = 0;
		}
	}
	while (e--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	int v1, v2;
	cin >> v1 >> v2;
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = 0;
	}
	visited[v1] = true;
    
    if(haspath(arr,visited,v,v1,v2))//in this case a will be start 
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
 return 0;   
}