#include<stdio.h>
#include<conio.h>

int queue[100];
int rear=-1;
int front=-1;

void push(int data){
    if(rear==-1)front++;
    if(rear<100)
    queue[++rear]=data;
    else
    printf("queue overflow\n");
}


void print(){
    for(int i=front;i<=rear;i++){
        printf("%d, ",queue[i]);
    }
    printf("\n");
}

void pop(){
    if(front==rear){
        front=-2;
        rear=-1;
    }
    if(front>rear)
    printf("queue underflow\n");
    else
    front++;
}

void main(){
    int data;
    while(1){
        printf("enter number to be inserted and -1 to quit: \n");
        scanf("%d",&data);
        if(data==-1)break;
        push(data);
    }
    print();
    pop();
    print();
}