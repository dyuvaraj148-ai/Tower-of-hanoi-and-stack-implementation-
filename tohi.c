#include <stdio.h>
#include <math.h>

#define MAX 64
typedef struct stack{
    int arr[MAX];
    int top;
}st;

void push(st *rod,int n){
    if(rod->top==MAX-1)
    return;
    rod->arr[++rod->top]=n;
}

int  pop(st *rod ){
    if(rod->top==-1)
    return -1;
    return rod->arr[rod->top--];
}

int peek(st *rod) {
    if (rod->top == -1) return -1;
    return rod->arr[rod->top];
}

void movedisk(char from, char to, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, from, to);
}

void moveBetweenPoles(st *s,st *d,char a,char b){
    int p1=peek(s);
    int p2=peek(d);
    if(p1==-1 && p2==-1)
    return;
    if(p1==-1){
        int val=pop(d);
        push(s,val);
        movedisk(b,a,val);
    }
    else if(p2==-1){
        int val=pop(s);
        push(d,val);
        movedisk(a,b,val);
    }
    else if(p1<p2){
        int val=pop(s);
        push(d,val);
        movedisk(a,b,val);
    }
    else if(p1>p2){
        int val=pop(d);
        push(s,val);
        movedisk(b,a,val);
    }

}

int main(){

    int n;
    scanf("%d",&n);
    st s,d,e;
    s.top=d.top=e.top=-1;
    char from='A',to='B',ex='C';
    if(n%2==0){
        char t=to;
        to=ex;
        ex=t;
    }
    int i,tot=((int)pow(2,n))-1;
     for(i=n;i>0;i--){
        push(&s,i);
     }
     for(i = 1; i <= tot; i++) {
        if (i % 3 == 1)
            moveBetweenPoles(&s, &d, from, to);
        else if (i % 3 == 2)
            moveBetweenPoles(&s, &e, from, ex);
        else if (i % 3 == 0)
            moveBetweenPoles(&e, &d, ex,to);
    }

}

