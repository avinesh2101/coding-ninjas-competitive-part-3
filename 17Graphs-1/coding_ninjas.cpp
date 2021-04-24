// checking in all 8 direction feels dumb instead of that i would do this ......
bool find_remaining(vector<vector<char>> &board, int n, int m,string cn,bool**visited,int i,int j )
{
    //base case
    if(cn.length()==0)
    {
        return true;
    }
    if(i<0 || j<0 || i>=n || j>=m)
    {
        return false;
    }
    
    // visited[i][j]=true;
    bool ans=false;
    
//     now we have to check in all 8 possible  directions
//      check within limit and if the element is the element that we need and is not visited yet then we do recursion 
//         othewise we go and look in diferent direction and do the same
        
//      upper
    if((i-1>=0&&j-1>=0) && (board[i-1][j-1] ==cn[0]) && !visited[i-1][j-1])
    {
        visited[i-1][j-1]=true;
        ans=find_remaining(board,n,m,cn.substr(1),visited,i-1,j-1);
        if(ans)
        {
            return true;
        }
        visited[i-1][j-1]=false;
    }
    
     if((i-1>=0) && (board[i-1][j] ==cn[0]) && !visited[i-1][j])
    {
         visited[i-1][j]=true;
         ans=find_remaining(board,n,m,cn.substr(1),visited,i-1,j);
        if(ans)
        {
            return true;
        }visited[i-1][j]=false;
    }
    
     if( (i-1>=0&&j+1<m)  && (board[i-1][j+1] ==cn[0]) && !visited[i-1][j+1])
    {
         visited[i-1][j+1]=true;
         ans=find_remaining(board,n,m,cn.substr(1),visited,i-1,j+1);
        if(ans)
        {
            return true;
        }visited[i-1][j+1]=false;
    }
//     middle
     if( (j-1>=0)   && (board[i][j-1] ==cn[0]) && !visited[i][j-1])
    {
         visited[i][j-1]=true;
         ans=find_remaining(board,n,m,cn.substr(1),visited,i,j-1);
        if(ans)
        {
            return true;
        }visited[i][j-1]=false;
    }
    
     if( (j+1<m)   && board[i][j+1] ==cn[0] && !visited[i][j+1])
    {
         visited[i][j+1]=true;
          ans=find_remaining(board,n,m,cn.substr(1),visited,i,j+1);
        if(ans)
        {
            return true;
        }
         visited[i][j+1]=false;
        
    }
//     lower
     if((i+1<n&&j-1>=0)   && board[i+1][j-1] ==cn[0] && !visited[i+1][j-1])
    {
         visited[i+1][j-1]=true;
         ans=find_remaining(board,n,m,cn.substr(1),visited,i+1,j-1);
        if(ans)
        {
            return true;
        }
         visited[i+1][j-1]=false;
    }
    
     if((i+1<n)  && board[i+1][j] ==cn[0]  && !visited[i+1][j])
    {
         visited[i+1][j]=true;
         ans=find_remaining(board,n,m,cn.substr(1),visited,i+1,j);
        if(ans)
        {
            return true;
        }visited[i+1][j]=false;
    }
    
     if((i+1<n&&j+1<m)   && board[i+1][j+1] ==cn[0] && !visited[i+1][j+1])
    {
         visited[i+1][j+1]=true;
         ans=find_remaining(board,n,m,cn.substr(1),visited,i+1,j+1);
        if(ans)
        {
            return true;
        }
         visited[i+1][j+1]=false;
    }
        return false;
}


bool hasPath(vector<vector<char>> &board, int n, int m) {
    
    string cn ="CODINGNINJA";
    bool**visited = new bool*[n];
    for(int i=0;i<n;i++)
     {
         visited[i]=new bool[m];
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
     }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='C')
            {
                visited[i][j] = true;
                               
                if(find_remaining(board,n,m,"ODINGNINJA",visited,i,j) )
                {
                    return true;
                }
                visited[i][j] = false;
            }
            
        }
    }
    
    return false;
}