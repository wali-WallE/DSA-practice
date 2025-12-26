#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main (){
    Node* START = NULL;
    Node* TEMP;
    int pos;
    Node* n1 = new Node{10, NULL};
    Node* n2 = new Node{20, NULL};
    Node* n3 = new Node{30, NULL};
    Node* n4 = new Node{40, NULL};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    START = n1;

    cout << "enter positon u want to delete ";
    cin >> pos;

    if( START == NULL ){
        cout << "empty list nothing to be deleted";
        return 0;
    }
    else if(pos == 0){
        TEMP = START;
        START = START->next;
    }
    else{
        TEMP = START;
        for(int i = 0; i < pos - 1 && TEMP!= NULL; i++){
            TEMP = TEMP->next;
        }
        Node* del = TEMP->next;
        cout << "deleting node at " << pos << ": " << del->data << endl;
        TEMP->next = del->next; 
    }

    TEMP=START;
    cout << "List : ";
    while (TEMP != NULL){
        cout << TEMP->data << "-> ";
        TEMP = TEMP->next;
    }
    cout << "NULL" << endl;

    return 0;
}