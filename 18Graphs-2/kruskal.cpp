/*Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 wc
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5*/
// -------------------------------My approach ------------------------------
// doubt - how get parent is working ????
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct edges{
    int src;
    int dest;
    int weight;
};

bool custom(struct edges v1,struct edges v2)
{
    return (v1.weight<v2.weight);
}

int get_parent(int current_vertex, int *parent)// in parent array we are storing index of its parent and if it is same return it
{				//	eg     0   1  2  3  4  5
//     					  -----------------
//     					  |0 |0 |0 |3 |4 |4| <- these are the index of their parent stored in parent array 
//     					  -----------------
	if (current_vertex == parent[current_vertex])
	{
		return current_vertex;
	}
	return get_parent(parent[current_vertex], parent);
}

bool union_find_algo(int n,int v1,int v2,int*parent)
{
//     if v1 and v2 is from same component then return false else true
//     how do we check component for this we are going to make an array which have a parent for each component
//     and we are going to campare their parents if parents are same then they are from same component i.e. return false
//     else return true
    int first_vertex_parent = get_parent(v1, parent);
	int second_vertex_parent = get_parent(v2, parent);
		if (first_vertex_parent != second_vertex_parent)
		{
			parent[first_vertex_parent] = second_vertex_parent;
            return true;
		}
    
    return false;
  
}

int main() {
    
    int n,e;
    cin>>n>>e;
    
    edges*arr = new edges[e];
    for(int i=0;i<e;i++)
    {
        cin>>arr[i].src>>arr[i].dest>>arr[i].weight;
    
    }
    
    sort(arr,arr+e,custom);//sort to get min weight edges first
    
  
    edges*ans = new edges[n-1];
       int*parent=new int[n]; //used for union find algo
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
	
    int count=0;
    int i=0;
    int j=0;//
    
    while(count<n-1 && i<e)
    {
        if(union_find_algo(n,arr[i].src,arr[i].dest,parent))
        {
            count++;
            ans[j].src=min(arr[i].src,arr[i].dest);
            ans[j].dest=max(arr[i].src,arr[i].dest);
            ans[j].weight=arr[i].weight;
            j++;
        }
        
        i++;
    }
    
    

    for(int i=0;i<n-1;i++)
    {
        cout<<ans[i].src<<" "<<ans[i].dest<<" "<<ans[i].weight;
        cout<<endl;
    
    }
    
}







// ------------------------------------------------------
// #include<iostream>
// #include<algorithm>
// using namespace std;
// struct structure
// {
// 	int first_vertex;
// 	int second_vertex;
// 	int weight;
// };

// int get_parent(int current_vertex, int *parent)
// {
// 	if (current_vertex == parent[current_vertex])
// 	{
// 		return current_vertex;
// 	}
// 	return get_parent(parent[current_vertex], parent);
// }
// structure* get_MST(structure* arr, int e, int v)
// {
// 	structure* output = new structure[v - 1];
// 	int* parent = new int[v];
// 	for (int i = 0; i < v; i++)
// 	{
// 		parent[i] = i;
// 	}
// 	int count = 0, i = 0;
// 	while (count < v - 1 && i<e)
// 	{
// 		structure current_edge = arr[i];
// 		int first_vertex_parent = get_parent(current_edge.first_vertex, parent);
// 		int second_vertex_parent = get_parent(current_edge.second_vertex, parent);
// 		if (first_vertex_parent != second_vertex_parent)
// 		{
// 			output[count] = current_edge;
// 			count++;
// 			parent[first_vertex_parent] = second_vertex_parent;
// 		}
// 		i++;
// 	}
// 	return output;
// }
// bool sorter(structure a, structure b)
// {
// 	if (a.weight < b.weight)
// 	{
// 		return true;
// 	}
// 	return false;
// }
// int main()
// {
// 	int v, e;
// 	cin >> v >> e;
// 	structure* arr = new structure[e];
// 	for (int i = 0; i < e; i++)
// 	{
// 		cin >> arr[i].first_vertex >> arr[i].second_vertex >> arr[i].weight;
// 	}
// 	sort(arr, arr + e, sorter);
// 	structure* output = get_MST(arr, e, v);
// 	for (int i = 0; i < v - 1; i++)
// 	{
// 		if (output[i].first_vertex < output[i].second_vertex)
// 			cout << output[i].first_vertex << " " << output[i].second_vertex << " " << output[i].weight << endl;
// 		else
// 			cout << output[i].second_vertex << " " << output[i].first_vertex << " " << output[i].weight << endl;
// 	}
// }