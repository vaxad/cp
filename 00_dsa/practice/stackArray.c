#include<stdio.h>
#include<conio.h>

int stack[100];
int head=0;

void push(int data){
    if(head<100)
    stack[head++]=data;
    else
    printf("stack overflow\n");
}

void print(){
    for(int i=0;i<head;i++){
        printf("%d, ",stack[i]);
    }
    printf("\n");
}

void pop(){
    if(head<0)
    printf("stack underflow\n");
    else
    head--;
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