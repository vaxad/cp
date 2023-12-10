#include<stdio.h>
#include<conio.h>

int queue[5];
int rear=-1;
int front=-1;

void push(int data){
    if((rear+1)%5!=front){
        rear = (rear+1)%5;
        queue[rear]=data;
        if(front==-1)front = 0;
    }else{
        printf("queue overflow\n");
    }
}

void print(){
    for(int i=front;i!=rear;i=(i+1)%5){
        printf("%d, ",queue[i]);
    }
    printf("%d \n",queue[rear]);
}

void pop(){
    if(front==rear){
        front=-2;
        rear=-1;
    }else
        if(front==-1)
        printf("queue underflow\n");
        else
        front = (front+1)%5;
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
    while(1){
        printf("f%d, r%d\n",front,rear);
        printf("1 to insert\n2 to pop\n3 to print\n");
        int num;
        scanf("%d",&data);
        if(data==-1)break;
        switch (data)
        {
        case 1:
            printf(" enter data");
            scanf("%d",&num);
            push(num);
            break;
        
        case 2:
            pop();
            break;
        
        case 3:
            print();
            break;

        default:
            break;
        }
    }
}