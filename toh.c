#include<stdio.h>
void toh(char s,char d,char i,int n){
    if(n==1){
        printf("move 1 from %c to %c\n",s,d);
        return;
    }
    toh(s,i,d,n-1);
    printf("move %d from %c to %c\n",n,s,d);
    toh(i,d,s,n-1);
}
int  main() {
    int n;
    scanf("%d",&n);
    toh('A','B','C',n);
}
    
