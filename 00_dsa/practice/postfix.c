#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node* next;
};

struct node *prefix, *operator, *postfix;
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
    // printf("%c: %d\n ",data,&head);
    struct node* newNode = createNode(data);
    newNode->next = head->next;
    head->next = newNode;
}

char pop(struct node* head){
    char c = head->next?head->next->data:'0';
    head->next = head->next?head->next->next:NULL;
    return c;
}

char peek(struct node* head){
    return head->next?head->next->data:'0';
}

int isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/')?1:0;
}

int precedence(char c){
    // printf("%c\n",c);
    if(!isOperator(c))return -1;
    switch(c){
        case '+': return 1;
        case '-': return 1;
        case '/': return 2;
        case '*': return 2;
        case '%': return 2;
        default : return 0;
    }
}

int isDigit(char c){
    return ((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))?1:0;
}

struct node * evaluation;


int operate(char c, int n1, int n2){
    switch(c){
        case '+': return n1+n2;
        case '-': return n1-n2;
        case '*': return n1*n2;
        case '/': return n1/n2;
        case '%': return n1%n2;
        default: return 0;
    }
}

int evaluatePostfix(char str[]){
    evaluation = createNode('\0');
    int i=0;
    while(str[i]!='\0'){
        char c = str[i];
        if(isDigit(c)){
            push(evaluation, c-'0'); 
        }else{
            push(evaluation,operate(c,pop(evaluation),pop(evaluation)));
        }
        i++;
    }
    pop(evaluation);
}


//(a+b)*e-5/3+4*2
//ab+* (+
//abe* 
void infixToPrefix( char str[] ){
    int i=0;
    char c;
    char strPrefix[strlen(str)];
    char strPostfix[strlen(str)];
    prefix = createNode('\0');
    operator = createNode('\0');
    postfix = createNode('\0');
    while(str[i]!='\0'){
        c=str[i];
        // printf("%c",str[i]);
        if(isDigit(c)){
            push(prefix,c);
        }else if(c=='('||c==')'){
            if(c=='('){
                push(operator,c);
            }else{
                while(peek(operator)!='('&&operator->next!=NULL){
                    push(prefix,pop(operator));
                }
                if(peek(operator)!='('&&operator->next!=NULL){
                    printf("invalid expression\n");
                    exit(1);
                }
                pop(operator);
            }
        }else{
            while(precedence(c)<=precedence(peek(operator))){
                // printf("%c, %c \t",c,peek(operator));
                push(prefix,pop(operator));
            }
            push(operator,c);
        }
        i++;
    }
    while(operator->next!=NULL){
        push(prefix,pop(operator));
    }
    i=0;
    while(prefix->next!=NULL){
        strPrefix[i]=peek(prefix);
        pop(prefix);
        i++;
    }
    strPrefix[i]='\0';
    i--;
    int j=0;
    while(i>=0){
        strPostfix[j]=strPrefix[i];
        j++;
        i--;
    }
    strPostfix[j]='\0';
    printf("\npostfix:%s\tprefix:%s",strPostfix,strPrefix);
    printf("evaluation : %d", evaluatePostfix(strPostfix));
}

void main(){
    char str[100];
    printf("enter string : ");
    gets(str);
    infixToPrefix(str);
}
