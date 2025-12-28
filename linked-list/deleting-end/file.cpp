#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* START = NULL;
    Node* TEMP;
    Node* n1 = new Node{10, NULL};
    Node* n2 = new Node{20, NULL};
    Node* n3 = new Node{30, NULL};
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    START= n1;

    if(START == NULL){
        cout << "list is empty cant delete" << endl;
        return 0;
    }
    else if( START->next==NULL){
        cout << "deleting only node : " << START->data << endl;
        // delete START;
        START = NULL;
    }
    else{
        TEMP = START;
        while(TEMP->next->next!=NULL){
            TEMP = TEMP->next;
        }
        Node* last = TEMP->next;
        cout << "deleting last node : " << last->data << endl;
        TEMP->next = NULL;
        // delete last;  
    }


    TEMP = START;
    cout << "list :";
    while(TEMP != NULL){
        cout << TEMP->data << "-> ";
        TEMP = TEMP->next;
    }
    cout << "NULL" << endl;

    return 0;
}