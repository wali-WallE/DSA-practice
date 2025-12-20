#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* START =NULL;

    int value;
    cout << "enter value: ";
    cin >> value;


    Node* newNode = new Node;
    newNode->data = value;
    
    if(START == NULL){
        newNode->next = NULL;
    }
    else{
        newNode->next = START;
    }

    START = newNode;

    return 0;
}
