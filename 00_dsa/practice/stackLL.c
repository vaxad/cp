#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)(malloc(sizeof(struct node)));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printLL(struct node* head){
    while(head->next!=NULL){
        printf("%d, ",head->next->data);
        head = head->next;
    }
    printf("\n");
}

struct node* createStackLL(){
    struct node* head = (struct node*)(malloc(sizeof(struct node)));
    head->next=NULL;
    int data;
    while(1){
        printf("enter data to be inserted in linked list (-1 to end creation): \n");
        scanf("%d",&data);
        if(data==-1)break;
        struct node* newNode = createNode(data);
        newNode->next = head->next;
        head->next = newNode;
    }
    return head;
}

void push(struct node* head, int data){
    struct node* newNode = createNode(data);
    newNode->next = head->next;
    head->next = newNode;
}

void pop(struct node* head){
    head->next = head->next->next;
}

void main(){
    struct node* h1 = createStackLL();
    int data;
    printf("insert data to be pushed: ");
    printLL(h1);
    scanf("%d",&data);
    push(h1,data);
    printLL(h1);
    pop(h1);
    printLL(h1);

}
