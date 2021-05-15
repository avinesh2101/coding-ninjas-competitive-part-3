#include<bits/stdc++.h>
using namespace std;
class trienode{
    public:
    trienode*right;//1
    trienode*left;//0
};
void insert(trienode*root,int pre_xor)
{
    trienode*curr = root;
    
    for(int i=31;i>=0;i--)
    {
        int b = (pre_xor>>i)&1;
        
        if(b == 0 )
        {
            if(!curr->left)
            {
                curr->left = new trienode();
            }
            
            curr = curr->left;
        }
        else{
            if(!curr->right)
            {
                curr->right = new trienode();
            }
            
            curr = curr->right;
        }
        
    }
    
}

int query(trienode*root , int pre_xor)
{//same as in max pair xor
    trienode*current= root;
    // we have to maximise pre_xor xor with already present elements od
//     tries
    int current_xor = 0;

    for(int i=31;i>=0;i--)
    {
        int b = (pre_xor>>i)&1;
        
        // Traverse Trie, first look for a 
        // prefix that has opposite bit 
        if(b == 0)
        {
           if (!current->right) //right node does not exist
                {
                    current = current->left;
                }
                else //right node exists
                {
                    current_xor += pow(2, i);
                    current = current->right;
                }
        }
        else{
           
                if (!current->left) //left node does not exits
                {
                    current = current->right;
                }
                else //left node exists
                {
                    current_xor += pow(2, i);
                    current = current->left;
                }
        }
    }
    return current_xor;
    
}

int max_xor_subarray(int*arr,int n)
{
	trienode *root = new trienode();
    // insert(root);    
    
    // Initialize answer and xor of current prefix 
    int ans = INT_MIN;
    int pre_xor = 0;
    
    for(int i=0;i<n;i++)
    {
        // update current prefix xor and insert it into Trie 
        pre_xor = pre_xor^arr[i]; 
        //     as 1 8 2 xor with 1 will give 8 2 xors value so
//               1 8 2 xor with 5 will give 1 8 2 5 xor value
        // we dont need to add every possible subarray in the trie
        insert(root, pre_xor); 
        
        // Query for current prefix xor in Trie and update 
        // result if required 
       ans = max(ans, query(root, pre_xor)); 
    }
    
    return ans;
}

int main() {
		int n;
    cin>>n;
    int*arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
//     step1.take value and new subarray xor will be added to trie
//     as 1 8 2 xor with 1 will give 8 2 xors value so we dont need to add every possible subarray in the trie
    
//     step2.the check the xor values of newly added with previous one present in trie and  and maintain a maximum
//     of all possible xor that will be our ans
	cout<<max_xor_subarray(arr,n)<<endl;
}