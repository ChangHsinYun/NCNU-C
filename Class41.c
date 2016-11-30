#include <stdio.h>
#include <stdlib.h>
//void printQueen(int *, int);
void printQueen(int *board, int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(board[(i+1)*(n+2)+j+1]=='Q') {
                printf("Q ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
void queen (int * board, int n, int row, int * sol) {//board=棋盤的每個格子 n=棋盤邊格子數 row=列 sol=幾組解
    int i, j, k, puton;//puton=現在要擺的位置
    int dir[]={n+1,n+2,n+3};//dir=方位(左下、正下、右下)
    if(row==n){    //當皇后放到第n列時
        printQueen(board, n);//印出棋盤
        (*sol)++;
        return;
    }
    for(i=0;i<n;i++) {
        //test if column can put a Queen
        puton=(row+1)*(n+2)+i+1;//
        if(board[puton]==0) {
            //這個位置不會被上面的皇后吃到
            board[puton]='Q';//放上皇后
            //set up control field
            for(j=0;j<3;j++) {
                for(k=puton+dir[j];board[k]>=0;k+=dir[j]){//k+=dir[j]-->k=k+dir[j]
                    board[k]++;
                }
            }
            //recusive to put row+1 Queen
            queen(board, n, row+1, sol);
            //remove queen and control field
            board[puton]=0;
            for(j=0;j<3;j++) {//還原
                for(k=puton+dir[j];board[k]>=0;k+=dir[j]){//k+=dir[j]-->k=k+dir[j]
                    board[k]--;
                }
            }
        }
    }
}
/*void printQueen(int *board, int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0;j<n;j++) {
            if(board[(i+1)*(n+2)+j+1]=='Q') {
                printf("Q ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}*/
void init(int *board, int n) {
    int i;
    for(i=0;i<(n+2)*(n+2);i++) {
        board[i]=0;             //在棋盤格中放零
    }
    //將邊框設為-1
    for(i=0;i<n+2;i++) {// 0~n+1
        //上邊
        board[i]=-1;
        //下邊
        board[(n+1)*(n+2)+i]=-1;
        //左邊
        board[i*(n+2)]=-1;
        //右邊
        board[i*(n+2)+n+1]=-1;
    }
}
int main() {
    int n, sol;
    int *board;//棋盤
    scanf("%d", &n);
    board=(int *)malloc((n+2)*(n+2)*sizeof(int));//(n+2)*(n+2)=棋盤+邊框
    init(board, n);
    sol=0;
    queen(board, n, 0, &sol);
    printf("%d solutions\n", sol);
}