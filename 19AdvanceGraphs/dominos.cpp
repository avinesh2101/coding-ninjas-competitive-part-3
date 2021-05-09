
// -----------------working in sample test case  buut fails in submit and gives runtime error
// #include<bits/stdc++.h>
// using namespace std;
//  stack<int> finishedStack;
//  vector<int> edges[100010];
//     // vector<int> edgesT[100010];

// void fill_stack(bool*visited,int start,int n)
// {
//     visited[start]=true;
    
//     //check neighbours
// //     for(int i=0;i<edges[start].size() ;i++)
// //     {
// //         if(!visited[edges[start][i]])
// //         {
// //             fill_stack(visited,finishedStack,edges[start][i],n);
// //         }
        
// //     }
    
//     for (auto v :edges[start])
//             if (visited[v] == 0)
//                 fill_stack( visited, v,n );
    
//     finishedStack.push(start);
    
// }

// void dfs(bool *visited,int element,int n)
// {
//     visited[element]=true;
//     for(int i=0;i<edges[element].size() ;i++)
//     {
//         if(!visited[edges[element][i]])
//         {
//             dfs(visited,edges[element][i],n);
//         }
//     }
//     // for (auto v : edges[element]) {
//     //         if (visited[v] == 0)
//     //             dfs(visited, v,n);
//     //     }
// }

// int main()
// {
//    ios_base::sync_with_stdio(false);
//     cin.tie(0);
// 	int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,m;
//         cin>>n>>m;
    
   
//     for(int i=0;i<m;i++)
//     {
//         int a,b;
//         cin>>a>>b;
//         edges[a-1].push_back(b-1);
//         // edgesT[b].push_back(a);//transpose 
//     }
    
// //----------using kosaraju from here--------
//     bool visited[n];
   
//     for(int i=0;i<n;i++)
//     {
//         visited[i]=false;
//     }
    
//     for(int i=0;i<n;i++)
//     {
//         if(visited[i]==false)
//         {
//             fill_stack(visited,i,n);//filling stack using dfs    
//         }
//     }
    
//     // no need of transpose think
//     for(int i=0;i<n;i++)
//     {
//         visited[i]=false;
//     }
//     int count=0;
//     while(!finishedStack.empty())
//     {
//         int element = finishedStack.top();
//         finishedStack.pop();
//         if(!visited[element])
//         {
//         	dfs(visited,element,n);
// 			 count++;
//         }
//     }
    
//     cout<<count<<"\n";
//     }
//     return 0;
// }

// -------------------------------------------------
#include <bits/stdc++.h>

using namespace std;
stack < int > st;
vector < int > adjList[100010];
bool visited[100010];
void dfs2(int index) {
  visited[index] = true;
  for (unsigned int j = 0; j < adjList[index].size(); j++) {
    if (!visited[adjList[index][j]]) {
      dfs2(adjList[index][j]);
    }
  }
}
void dfs(int index) {
  visited[index] = true;
  for (unsigned int j = 0; j < adjList[index].size(); j++) {
    if (!visited[adjList[index][j]]) {
      dfs(adjList[index][j]);
    }
  }
  st.push(index);
}
int main() {
  int tc;
  scanf("%d", & tc);
  while (tc--) {
    memset(visited, false, sizeof(visited));
    int n, m;
    scanf("%d %d", & n, & m);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", & a, & b);
      adjList[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    memset(visited, false, sizeof(visited));
    int count = 0;
    while (!st.empty()) {
      int index = st.top();
      st.pop();
      if (!visited[index]) {
        count++;
        dfs2(index);
      }
    }
    printf("%d\n", count);
    for (int i = 1; i <= n; i++) {
      adjList[i].clear();
    }
  }
  return 0;
}