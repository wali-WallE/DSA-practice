#include <iostream>
using namespace std;

const int SIZE =5;

class stackPrac{
public: 

    void insertStack(int stack[], int &top, int data){
        if(top == SIZE-1){
            cout << "stack overflow cant add anything!!" << endl;
        }
        else{
            stack[++top] = data;
            cout << data << " pushed into stack" << endl;
        }
    }

    void deleteStack(int stack[], int &top){
        if(top == -1){
            cout << "the stack is empty! nothing deleted";
        }
        else{
            cout << stack[top--] << " deleted" <<endl;
        }
    }

    void display(int stack[], int top){
        if(top == -1){
            cout << "the stack is empty! nothing deleted";
        }
        else{
            cout << "stack elements : " << endl;
            for(int i = top ; i >= 0; i--){
                cout << stack[i] << "," << endl;
            }
        }        
    }
};


int main(){
    stackPrac sp;
    int stack[SIZE];
    int  top = -1;
    sp.insertStack(stack, top, 10);
    sp.insertStack(stack, top, 20);
    sp.insertStack(stack, top, 30);

    sp.display(stack, top);

    sp.deleteStack(stack, top);

    sp.display(stack, top);

    return 0;
}