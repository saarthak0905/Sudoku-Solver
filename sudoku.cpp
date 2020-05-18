#include <iostream>
#include <cmath>
using namespace std;
const int D = 9 ;
void printBoard(int board[D][D], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";

        }
        cout<<endl;
    }
}
bool canPlace(int board[D][D], int n, int row, int col, int cnum )
{
    if(board[row][col] !=0)
    {
        return 0;
    }
    int rootn = sqrt(n);
    for(int i=0;i<n;i++)
    {
        if(board[row][i]==cnum) return false;
        if(board[i][col]==cnum) return false;

    }
    int rowStart = row - row%3;
    int colStart = col - col%3;
    for(int x=rowStart;x<rowStart + rootn; x++)
    {
        for(int y = colStart; y< colStart + rootn; y++)
        {
            if(board[x][y] == cnum)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokuSolver(int board[D][D], int n, int row, int col)
{
    if(row==n)
    {
        return true;
    }
    if(col==n)
    {
        return sudokuSolver(board, n, row + 1, 0);

    }
    if(board[row][col] != 0)
    {
        return sudokuSolver(board, n, row, col + 1);
    }
    for(int cnum = 1; cnum<=n; cnum++)
    {
        if(canPlace(board, n, row, col, cnum))
        {
            board[row][col] = cnum;
            bool ans = sudokuSolver(board, n, row, col + 1);
            if(ans)
            {
                return true;

            }
            board[row][col] = 0;

        }
    }
    return false;
}
int main()
{

    int board[D][D] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    int n; cin>>n;
    bool ans = sudokuSolver(board, n, 0, 0);
    if(ans)
    {
        printBoard(board, n);
    }
    else
        cout<<"Couldn't find solution";

}
