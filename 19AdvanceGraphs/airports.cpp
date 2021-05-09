/*AIRPORTS
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, so if there are several ways of getting the minimal cost, choose the one that has the most airports.
Input
The first line of input contains the integer T (T < 25), the number of test cases. The rest of the input consists of T cases. Each case starts with two integers N, M and A (0 < N ≤ 10, 000, 0 ≤ M ≤ 100, 000, 0 < A ≤ 10, 000) separated by white space. N is the number of locations, M is the number of possible roads that can be built, and A is the cost of building an airport.
The following M lines each contain three integers X, Y and C (1 ≤ X, Y ≤ N, 0 < C ≤ 10, 000), separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output
Your program should output exactly T lines, one for each case. Each line should be of the form ‘Case #X: Y Z’, where X is the case number Y is the minimum cost of making roads and airports so that all locations have access to at least one airport, and Z is the number of airports to be built. As mentioned earlier, if there are several answers with minimal cost, choose the one that maximizes the number of airports.
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
Case #1: 145 1
Case #2: 2090 2*/
#include <bits/stdc++.h>
using namespace std;

class Edges{
  
    public:
    
    int src;
    int dest;
    int weight;
    
};

class compare{
    public:
    bool operator()(Edges const &a,Edges const &b)
    {
        return a.weight<b.weight;
    }
};
    
    

int findParent(int *parent ,int vertex){
    
    if(parent[vertex]==vertex)
        return vertex;
    
    return findParent(parent,parent[vertex]);
    
}

int getOutput(Edges *input,int size,int *parent,int V,int A,int *count){
        
    int totalweight=0;
    
        for(int i=0;i<size;i++)
        {
            Edges e = input[i];
            
            int p1 = findParent(parent,e.src);
            int p2 = findParent(parent,e.dest);
            
            if(p1!=p2 && e.weight<A){
                totalweight += e.weight;
                parent[p1] = p2;
            }
            
            
        }
        
     
    
        for(int i=1;i<=V;i++)
        {
            if(parent[i]==i)
                (*count)++;
        }
        
    totalweight += ((*count)*A);
    
    return totalweight;
    
}

int main()
{
  int t;
  cin>>t;
  int c=1;  
  while(t--)
  {  
  int V,E,A;
  cin>>V>>E>>A;
    
    Edges *input = new Edges[E];
    
    for(int i=0;i<E;i++)
    {
        Edges e;
        cin>>e.src>>e.dest>>e.weight;
        input[i] = e;
    }
    
    sort(input,input+E,compare());
    
    int count = 0;//no. of airports
    
    int *parent = new int[V+1];
    
    for(int i=0;i<=V;i++){
        parent[i] = i;
    }
    int output = getOutput(input,E,parent,V,A,&count);
    
    cout<<"Case #"<<c<<": "<<output<<" "<<count<<endl;   
    c++;      
    
  }

  return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// struct Graph
// {
//     int src;
//     int dest;
//     int cost;
// };
// bool compare(Graph e1,Graph e2)
// {
    
//     return e1.cost<e2.cost;
// }
// int getParent(int v,int* parent)
// {
//     if(parent[v]==v)
//     {
//         return v;
//     }
//     return getParent(parent[v],parent);
// }
// Graph* Kruskals(Graph* edges,int n,int m,int* parent)
// {
//     int i=0;
//     int count=0;
//     Graph* output=new Graph[n-1];
//     while(count<n-1 && i<m)
//     {
//         Graph current=edges[i];
//         int srcParent=getParent(current.src,parent);
//         int destParent=getParent(current.dest,parent);
//         if(srcParent!=destParent)
//         {
//             output[count]=edges[i];
//             count++;
//             parent[destParent]=srcParent;
//         }
//         i++;
//     }
//     return output;
// }
// void DFS(vector<int>* arr,int start,bool* visited)
// {
//     visited[start]=true;
//     for(int i=0;i<arr[start].size();i++)
//     {
//         int adjacent=arr[start][i];
//         if(!visited[adjacent])
//         {
//             DFS(arr,adjacent,visited);
//         }
//     }
//     return;
// }
// int main()
// {
//   	int t;
//     cin>>t;
//     for(int k=0;k<t;k++)
//     {
//         int n,m,a;
//         cin>>n>>m>>a;
//         Graph* edges= new Graph[m];
//         vector<int>* arr=new vector<int>[n];
//         for(int i=0;i<m;i++)
//         {
//             int x,y,c;
//             cin>>x>>y>>c;
//             if(c<a)
//             {
//             	edges[i].src=x-1;
//             	edges[i].dest=y-1;
//             	edges[i].cost=c;    
//                 arr[x-1].push_back(y-1);
//             	arr[y-1].push_back(x-1);
//             }
//         }
//         int* parent=new int[n];
//         for(int i=0;i<n;i++)
//         {
//             parent[i]=i;
//         }
//         sort(edges,edges+m,compare);
//         //kruskals to find minimum cost to build the road
//         Graph* output=new Graph[n-1];
//         output=Kruskals(edges,n,m,parent);
//         int road_cost=0;
//         for(int i=0;i<n-1;i++)
//         {
//             road_cost=road_cost+output[i].cost;
//         }
//         //dfs to find number of components
//         bool* visited=new bool[n];
//         for(int i=0;i<n;i++)
//         {
//             visited[i]=false;
//         }
//         int comp_count=0;
//         for(int i=0;i<n;i++)
//         {
//             if(!visited[i])
//             {
//                 DFS(arr,i,visited);
//                 comp_count++;
//             }
//         }
//         int main_ans=(comp_count*a)+road_cost;
//         cout<<"Case #"<<k+1<<": "<<main_ans<<" "<<comp_count<<endl;
//     }
// 	return 0;
// }
