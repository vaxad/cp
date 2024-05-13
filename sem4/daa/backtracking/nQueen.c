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
    for(int i=0;i<c;i++){
        if(board[r][i])return false;
    }
    for(int i=r, j=c;i>=0&&j>=0;i--, j--){
        if(board[i][j])return false;
    }
    for(int i=r, j=c;i<n&&j>=0;i++, j--){
        if(board[i][j])return false;
    }
    return true;
}

bool nQueen(int board[100][100], int n, int col){
    if(col>=n)return true;

    for(int r=0;r<n;r++){
        if(isSafe(board, n,r,col)){
            board[r][col]=1;
            if(nQueen(board,n, col+1)){
                return true;
            }else{
                board[r][col]=0;
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