#include <bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    trieNode*child [26];
    int weight;
    bool isEnd;
//     constructor
    trieNode()
    {
        weight = 0;
        for(int i=0;i<26;i++)
        {
            child[i] = NULL;
        }
    }
};

void insert(string s,int weight,trieNode*root)
{
    //recursive
//     if(s.empty())
//     {
//         return;
//     }
//     int index = s[0] - 'a';
    
//     trieNode*son;
//     if(root->child[index])
//     {
//         son = root->child[index]; 
//     }
//     else
//     {
//         son = new trieNode();
//         root->child[index] = son;
//     }
    
//     if(root->weight<weight)
//     {
//         root->weight = weight;
        
//     }
//     insert(s.substr(1),weight,son);
    
    //----------iterative------------
    trieNode*curr = root;
    for(int i=0;i<s.length();i++)
    {
        int index = s[i]-'a';       
        if(curr->weight < weight)
        {
            curr->weight = weight;
        }
        if(curr->child[index] == NULL)
        {
            curr->child[index] = new trieNode();
            curr->child[index]->weight = weight;
            curr = curr->child[index];            
        }
        else
        {
            curr->weight = max(weight,curr->weight);
            curr = curr->child[index];
        }
        
   }
    curr->isEnd =true;//no use in this qus
}

int helper(string query,trieNode*root)
{
    trieNode*curr = root;
    int i=0;
    for(i=0;i<query.length();i++)
    {
        int index = query[i]-'a';
        if(curr->child[index]!=NULL)
        {
            curr = curr->child[index];
        }
        else{
            return -1;
        }
        
    }
    
    if(i==query.length())
    {
        return curr->weight;
    }
}

struct s{
    int weight;
    string s;
};

int main()
{
    int n,q;
    cin>>n>>q;
    trieNode*root = new trieNode();
    s*db_entry = new s[n];
    for(int i=0;i<n;i++)
    {
        cin>>db_entry[i].s>>db_entry[i].weight;
        insert(db_entry[i].s,db_entry[i].weight,root);        
    }
    
    for(int i=0;i<q;i++)
    {
        string query;
        cin>>query;
        cout<<helper(query,root)<<endl;
    }   
    return 0;
}
