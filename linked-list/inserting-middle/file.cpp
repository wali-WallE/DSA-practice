#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    int value;
    int pos;

    Node* START = NULL;
    Node* TEMP;

    cout << "Enter -1 to stop inserting.\n";

    while(true){

    cout << "enter data: " << endl;
    cin >> value;

    if (value == -1) break;

    cout << "enter pos to enter node at " << endl;
    cin >> pos;

    Node* newNode = new Node;
    newNode->next = NULL;
    newNode->data = value;

    if( pos == 0){
        newNode->next = START;
        START = newNode;
    }
    else{
    TEMP = START;
    for(int i = 0; i < pos-1 && TEMP!= NULL; i++){
        TEMP = TEMP->next;
    }

    if(TEMP == NULL){
        cout << "invalid value entered";
        return 0;
        continue;
    }

    newNode->next = TEMP->next;
    TEMP->next = newNode;
    }
    TEMP = START;
    cout << "list : ";
    while(TEMP != NULL){
        cout << TEMP->data << "-> ";
        TEMP = TEMP->next;
    }
    cout << "NULL" << endl;
    }
    return 0;


}