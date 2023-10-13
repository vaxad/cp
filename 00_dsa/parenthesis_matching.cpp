#include<iostream>

using namespace std;

#define MAX_SIZE 1000

// Define the Stack class
class Stack{
    private:
        int top;
    public:
        char arr[MAX_SIZE];

        Stack(){
            top = -1;
        }

        bool isFull(){
            return top>=MAX_SIZE-1;
        }

        bool isEmpty(){
            return top<=-1;
        }

        void push(char data){
            if(isFull()){
                cout<<"Stack overflow\n";
                return;
            }
            arr[++top]=data;
        }

        char pop(){
            if(isEmpty()){
                cout<<"Stack underflow\n";
                return ' ';
            }
            return arr[top--];
        }

        char peek(){
            return isEmpty()?0:arr[top];
        }

        void print(){
            for(int i=top;i>-1;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

};

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int Precedence(char c){
    if(c == '*' || c == '/'){
        return 3;
    }else if(c == '+' || c == '-'){
        return 2;
    }else{
        return 1;
    }
}

bool match_parenthesis(char c2, char c1){
    return ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}'));
}

bool is_parenthesis_matching(string infix){
    Stack parenthesis;
    int i=0;
    while(infix[i]!='\0'){
        if(infix[i] == '(' || infix[i] == '{' || infix[i] == '['){
            parenthesis.push(infix[i]);
        }else if(infix[i] == ')' || infix[i] == '}' || infix[i] == ']'){
            if(parenthesis.isEmpty()){
                return false;
            }
            if(!match_parenthesis(infix[i],parenthesis.pop())){
                return false;
            }
        }
        i++;
    }
    return parenthesis.isEmpty();
}

int main(){
    string exp;
    cout<<"enter an expression: ";
    cin>>exp;
    cout<<"parenthesis is: "<<is_parenthesis_matching(exp)?"matching":"not matching";
    return 0;
}
