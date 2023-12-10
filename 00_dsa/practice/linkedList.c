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

struct node* createLL(){
    struct node* head = (struct node*)(malloc(sizeof(struct node)));
    struct node* temp = head;
    int data;
    while(1){
        printf("enter data to be inserted in linked list (-1 to end creation): \n");
        scanf("%d",&data);
        if(data==-1)break;
        struct node* newNode = createNode(data);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void printLL(struct node* head){
    while(head->next!=NULL){
        printf("%d, ",head->next->data);
        head = head->next;
    }
    printf("\n");
}

void insertAtTail(struct node* head, int data){
    struct node* newNode = createNode(data);
    while(head->next!=NULL)head=head->next;
    head->next = newNode;
}

void insertAtHead(struct node* head, int data){
    struct node* newNode = createNode(data);
    newNode->next = head->next;
    head->next = newNode;
}

struct node* searchLL(struct node* head, int data){
    struct node* newNode = createNode(data);
    while(head->next!=NULL){
        if(head->next->data==data){
            printf("data found at %d",head->next);
            break;
        }
        head = head->next;
    }
    return head->next;
}

void insertDataAfter(struct node* head, int data, int after){
    struct node* newNode = createNode(data);
    while(head->next!=NULL){
        head = head->next;
        if(head->data==after){
            break;
        }
    }
    newNode->next = head->next;
    head->next = newNode;
}

void insertDataBefore(struct node* head, int data, int before){
    struct node* newNode = createNode(data);
    while(head->next!=NULL){
        if(head->next->data==before){
            break;
        }
        head = head->next;
    }
    newNode->next = head->next;
    head->next = newNode;
}

void removeNode(struct node* head, int data){
    struct node* newNode = createNode(data);
    while(head->next!=NULL){
        if(head->next->data==data){
            printf("data found at %d\n",head->next);
            break;
        }
        head = head->next;
    }
    head->next = head->next->next;
}

void main(){
    struct node* h1 = createLL();
    int data;
    printf("insert data to be inserted at Last: ");
    printLL(h1);
    scanf("%d",&data);
    insertAtTail(h1,data);
    printLL(h1);
    insertAtHead(h1,data);
    printLL(h1);
    searchLL(h1,25);
    insertDataAfter(h1,87,25);
    printLL(h1);
    insertDataBefore(h1,55,87);
    printLL(h1);
    removeNode(h1,25);
    printLL(h1);
}
