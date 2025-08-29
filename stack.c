#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}sn;
sn *head=NULL,*top=NULL;

sn* createnode(int d){
    
    sn* nw=(sn*)malloc(sizeof(sn));
    nw->data=d;
    nw->next=NULL;
    return nw;
}

void push(){
    
    int data;
    scanf("%d",&data);
    if(top==NULL)
    head=top=createnode(data);
    else{
        top->next=createnode(data);
        top=top->next;
    }
}

void pop(){
    if(top==NULL)
    printf("underflow\n");
    else if(head->next==NULL){
        sn *temp=top;
        printf("ELEMENT POPED:%d\n",temp->data);
        head=top=NULL;
        free(temp);
    }
    else{
        sn *prev=NULL,*ptr=head;
        while(ptr->next!=NULL){
            prev=ptr;
            ptr=ptr->next;
        }
        printf("ELEMENT POPED:%d\n",ptr->data);
        prev->next=NULL;
        top=prev;
        free(ptr);
    }
}

void  display(){
	sn *ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        printf("%d ",ptr->data);
    }
    printf("\n");
}
int main() {
    
    int c;
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    
    while(1){
        printf("Enter option:");
        scanf("%d",&c);
        if(c==1)
        push();
        else if(c==2)
        pop();
        else if(c==3)
        display();
        else if(c==4)
        break;
        else
        printf("ENTER VALID OPTION\n");
    }

}
