#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<string>&board,int row, int col, int n)
{
    for(int j=0;j<n;j++)
    {
        if(board[row][j]=='Q')
        {
            return false;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
    }
    for(int i=row,j=col; i>=0&&j>=0; i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    for(int i=row,j=col; i>=0&&j<n; i--,j++)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}

void nQueen(vector<string>&board,int row,int n, vector<vector<string>>&ans)
{

    if(row==n)
    {
        ans.push_back({board});
        return;
    }

    for(int j=0; j<n; j++)
    {
       if(issafe(board,row,j,n))
       {
           board[row][j]='Q';
           nQueen(board,row+1,n,ans);
           board[row][j]='.';
       }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<string>board(n,string(n,'.'));
    vector<vector<string>>ans;
    nQueen(board,0,n,ans);
    int p=ans.size();
    for(int i=0; i<p; i++)
    {
        int k=ans[i].size();
        for(int j=0; j<k; j++)
        {
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
}
/// time complexity : O(n!)

/*
intput: 4

output:
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/
