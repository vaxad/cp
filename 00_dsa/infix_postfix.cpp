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
string infix_to_postfix(string infix){
    Stack output;
    Stack operators;
    char postfix[infix.length()];
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }else{
            if(Precedence(infix[i])>Precedence(operators.peek())){
                operators.push(infix[i]);
                i++;
            }else{
                postfix[j]=operators.pop();
                j++;
            }
        }
    }

    while(!operators.isEmpty()){
        postfix[j]=operators.pop();
        j++;
    }

    postfix[j]='\0';
    return postfix;
    
}

int main(){
    string exp;
    cout<<"enter an expression: ";
    cin>>exp;
    cout<<"postfix equivalent is: "<<infix_to_postfix(exp);
    return 0;
}
