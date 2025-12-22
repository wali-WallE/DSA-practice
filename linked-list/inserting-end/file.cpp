#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    int value;
    Node* START = NULL;

    cout << "enter data to store at end : ";
    cin >> value;

    Node* newNode = new Node;
    newNode->next = NULL;
    newNode->data = value;

    Node* TEMP;

    if (START == NULL){
        START = newNode;
    }
    else {
        TEMP = START;
        while(TEMP->next != NULL){
            TEMP = TEMP->next;
        }
        TEMP->next = newNode;
    }

    TEMP = START;
    cout <<"list: ";
    while(TEMP != NULL){
        cout << TEMP->data << "-> ";
        TEMP = TEMP->next;
    }
    cout << "NULL" << endl;

    return 0;
}
