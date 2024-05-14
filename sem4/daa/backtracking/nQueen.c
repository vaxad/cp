#include<stdio.h>
#include<stdbool.h>

void printBoard(int board[100][100], int n){
    printf("BOARD:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[100][100], int n, int r, int c){
    for(int i=0;i<r;i++){
        if(board[i][c])return false;
    }
    for(int i=r, j=c;i>=0&&j>=0;i--, j--){
        if(board[i][j])return false;
    }
    for(int i=r, j=c;i<n&&j>=0;i++, j--){
        if(board[i][j])return false;
    }
    return true;
}

bool nQueen(int board[100][100], int n, int row){
    if(row>=n)return true;

    for(int c=0;c<n;c++){
        if(isSafe(board, n,row,c)){
            board[row][c]=1;
            if(nQueen(board,n, row+1)){
                return true;
            }else{
                board[row][c]=0;
            }
        }
    }
    return false;
}

int main(){
    int n, board[100][100];
    printf("N-QUEEN PROBLEM:\n");
    printf("enter number of queens: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }
    printBoard(board, n);
    nQueen(board,n,0);
    printBoard(board, n);
    return 0;
}