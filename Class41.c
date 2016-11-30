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
void queen (int * board, int n, int row, int * sol) {//board=�ѽL���C�Ӯ�l n=�ѽL���l�� row=�C sol=�X�ո�
    int i, j, k, puton;//puton=�{�b�n�\����m
    int dir[]={n+1,n+2,n+3};//dir=���(���U�B���U�B�k�U)
    if(row==n){    //��ӦZ����n�C��
        printQueen(board, n);//�L�X�ѽL
        (*sol)++;
        return;
    }
    for(i=0;i<n;i++) {
        //test if column can put a Queen
        puton=(row+1)*(n+2)+i+1;//
        if(board[puton]==0) {
            //�o�Ӧ�m���|�Q�W�����ӦZ�Y��
            board[puton]='Q';//��W�ӦZ
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
            for(j=0;j<3;j++) {//�٭�
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
        board[i]=0;             //�b�ѽL�椤��s
    }
    //�N��س]��-1
    for(i=0;i<n+2;i++) {// 0~n+1
        //�W��
        board[i]=-1;
        //�U��
        board[(n+1)*(n+2)+i]=-1;
        //����
        board[i*(n+2)]=-1;
        //�k��
        board[i*(n+2)+n+1]=-1;
    }
}
int main() {
    int n, sol;
    int *board;//�ѽL
    scanf("%d", &n);
    board=(int *)malloc((n+2)*(n+2)*sizeof(int));//(n+2)*(n+2)=�ѽL+���
    init(board, n);
    sol=0;
    queen(board, n, 0, &sol);
    printf("%d solutions\n", sol);
}