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
    else{
    TEMP = START;
    START= START->next;
    cout << "deleting the data of : " << TEMP->data <<endl;
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