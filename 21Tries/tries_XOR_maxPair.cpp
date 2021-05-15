#include<iostream>
using namespace std;

class trieNode{
public:
    trieNode *left;//0
    trieNode *right;//1
};
void insert(int value,trieNode*head)
{
    trieNode *curr = head;
    for(int i=31;i>=0;i--)
    {
        int bit = (value>>i)&1;
        if(bit == 0)
        { 
            if(!curr->left)
            {
                 curr->left = new trieNode();
            }
            curr = curr->left;

        }
        else{

            if(!curr->right)
            {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }

}

int get_max_xor(trieNode*head,int arr[],int n)
{
    int max_xor = INT_MIN;
 for (int i = 0; i < n; i++)
    {
        trieNode *current = head;
        int current_xor = 0;

        for (int j = 31; j >= 0; j--)
        {
            int bit = (arr[i] >> j) & 1;
            if (bit == 0)
            {
                    if (!current->right) //right node does not exist
                    {
                        current = current->left;
                    }
                    else //right node exists
                    {
                        current_xor += pow(2, j);
                        current = current->right;
                    }
            }
            else
            {
                if (!current->left) //left node does not exits
                {
                    current = current->right;
                }
                else //left node exists
                {
                    current_xor += pow(2, j);
                    current = current->left;
                }
            }
        }
        //now i have my current answer stored in current_xor.
        //i have to compare it with max_xor.
        if (max_xor < current_xor)
        {
            max_xor = current_xor;
        }
    }
    return max_xor;


}
int main()
{
    int arr[]={1,2,3,4,5,7};
    int n = sizeof(arr )/sizeof(int);
    trieNode*head = new trieNode();
    for(int i=0;i<n;i++)
    {
        insert(arr[i],head);
    }
    cout<<get_max_xor(head,arr,n);
}
