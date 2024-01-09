#include<stdio.h>
#include<conio.h>

int queue[100];
int rear=-1;
int front=-1;

void push(int data){
    if(rear==-1)front++; //empty
    if((rear+1)!=front&&!(rear==99&&front==0))
    rear = (rear+1)%100;
    queue[rear]=data;
    else
    printf("queue overflow\n");
}


void print(){
    for(int i=front;i!=rear;i=(i+1)%100){
        printf("%d, ",queue[i]);
    }
    printf("%d",queue[rear]);
    printf("\n");
}

void pop(){
    if(front==rear){
        front=-1;
        rear=-1;
        return;
    }
    // if(front)
    // printf("queue underflow\n");
    // else
    front=(front+1)%100;
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