#include <iostream>
using namespace std;
class trienode
{
public:
    int left_count, right_count;
    trienode *left;
    trienode *right;
    trienode()
    {
        left_count = 0;
        right_count = 0;
        left = NULL;  //left denotes 0
        right = NULL; //right denotes 1
    }
};
void insert(trienode *root, int element)
{
    for (int i = 31; i >= 0; i--)
    {
        int x = (element >> i) & 1;

        if (x) //if the current bit is 1
        {
            root->right_count++;
            if (root->right == NULL)
                root->right = new trienode();
            root = root->right;
        }
        else
        {
            root->left_count++;
            if (root->left == NULL)
                root->left = new trienode();
            root = root->left;
        }
    }
}
int query(trienode *root, int element, int k)
{
    if (root == NULL)
        return 0;
    int res = 0;
    for (int i = 31; i >= 0; i--)
    {
        bool current_bit_of_k = (k >> i) & 1;
        bool current_bit_of_element = (element >> i) & 1;
        if (current_bit_of_k)//if the current bit of k is 1
        {
            if (current_bit_of_element)//if current bit of element is 1
            {
                res += root->right_count;
                if (root->left == NULL)
                    return res;
                root = root->left;
            }

            else//if current bit of element is 0
            {
                res += root->left_count;
                if (root->right == NULL)
                    return res;
                root = root->right;
            }
        }
        else//if the current bit of k is zero
        {
            if (current_bit_of_element)//if current bit of element is 1
            {
                if (root->right == NULL)
                    return res;
                root = root->right;
            }
            else//if current bit of element is 0
            {
                if (root->left == NULL)
                    return res;
                root = root->left;
            }
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int temp, temp1, temp2 = 0; // will be using these three for storing current XOR
        // we will not be storing the inputs in the array
        trienode *root = new trienode();
        insert(root, 0);
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            temp1 = temp2 ^ temp;
            total += query(root, temp1, k);
            insert(root, temp1);
            temp2 = temp1;
        }
        cout << total << endl;
    }
    return 0;
}

// everything is fine just add the else statements in 
// query function and i think i am good to go
// #include <bits/stdc++.h>
// using namespace std;

// class trieNode{
//     public:
//  	trieNode*right;
//     trieNode*left;
//     int leaf_below = 0;
    
// };

// void insert(trieNode*root,int pre_xor)
// {
//     trieNode*curr = root;
//     for(int i=31;i>=0;i++)
//     {
//         int b = (pre_xor>>i)&i;
        
//         if(b == 0)
//         {
//             if(curr->left)
//             {
//           		 curr->leaf_below = curr->leaf_below+1;
//             	 curr = curr->left;
//             }
//             else{
//                 curr->left = new trieNode();
//                 curr = curr->left;
//             }
             
//         }
//         else{
//             if(curr->right)
//             {
//                 curr->leaf_below = curr->leaf_below +1;
//                curr = curr->right;
//             }
//             else{
//                  curr->right = new trieNode();
//                 curr = curr->right;
//             }
            
//         }
//     }
// }


// int query(trieNode*root,int pre_xor,int k)
// {
//     trieNode*curr = root;
//     int ans = 0;
//     for(int i=31;i>=0;i++)
//     {
//         int bp = (pre_xor>>i)&i;
//         int bk = (k>>i)&i;
        
//         if(bp == 1 && bk == 1)
//         {
//          	  if(curr->right)
//               {
//                   ans = curr->right->leaf_below;
//                   curr = curr->left;
//               }
//         }
//         else if(bp == 1 && bk == 0)
//         {
//             if(curr->right)
//             {curr=curr->right;}
//         }
//         else if(bp == 0 && bk == 1)
//         {
//             if(curr->left)
//             {
//                 ans = curr->left->leaf_below;
//                 curr=curr->right;
//             }
            
//         }
//         else if(bp == 0 && bk == 0)
//         {
//             if(curr->left)
//             {
//                 curr = curr->left;
//             }
//         }
//     }
    
//     return ans;
// }

// int helper(int*arr,int n,int k)
// {
//   	trieNode *root = new trieNode();
//     int ans = 0;
//     int pre_xor = 0;
//      for(int i=0;i<n;i++)
//     {
//         pre_xor = pre_xor^arr[i]; 
//         insert(root, pre_xor); 
         
//         ans+= query(root,pre_xor,k);
//     }
    
//     return ans;
// }

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
        
//         int k;
//         cin>>k;
//         int*arr = new int[n];
        
//         for(int i=0;i<n;i++)
//         {
//             cin>>arr[i];
//         }
        
//         cout<<helper(arr,n,k)<<endl;
        
//     }
//     return 0;
// }
