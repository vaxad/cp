#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* next;
};

struct node *postfix, *operator;
struct node* createNode(char data){
    struct node* newNode = (struct node*)(malloc(sizeof(struct node)));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printLL(struct node* head){
    while(head->next!=NULL){
        printf("%d",head->next->data);
        head = head->next;
    }
    printf("\n");
}

struct node* createStackLL(){
    struct node* head = (struct node*)(malloc(sizeof(struct node)));
    head->next=NULL;
    char data;
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

void push(struct node* head, char data){
    struct node* newNode = createNode(data);
    newNode->next = head->next;
    head->next = newNode;
}

char pop(struct node* head){
    if(head->next==NULL)return '\0';
    char c = head->next->data;
    head->next = head->next->next;
    return c;
}

char peek(struct node* head){
    return head->next?head->next->data:'0';
}

int precedence(char c){
    switch(c){
        case '+': return 1;
        case '-': return 1;
        case '/': return 2;
        case '*': return 2;
        case '%': return 2;
        default : 0;
    }
}
int isDigit(char c){
    return ((c>='0'&&c<='9')||(c>='a'&&c<='b')||(c>='A'&&c<='Z'))?1:0;
}
//(a+b)*e-5/3+4*2
//ab+* (+
//abe* 
void infixToPostfix( char str[] ){
    int i=0;
    char c;
    postfix = createNode('\0');
    operator = createNode('\0');
    while(str[i]!='\0'){
        c=str[i];
        if(isDigit(c)){
            push(postfix,c);
        }else{
            if(precedence(c)&&precedence(peek(operator))){
                if(precedence(c)<precedence(peek(operator)))
                    while(precedence(peek(operator)))
                else
                    push(operator,c);
            }else
                push(operator,c);
        }

        i++;
    }
}

void main(){
    char str[100];
    printf("enter string : ");
    gets(str);
    infixToPostfix(str);
}
