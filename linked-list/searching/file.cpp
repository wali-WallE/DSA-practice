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
    Node* n4 = new Node{40, NULL};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    START = n1;

    int pos = 0;
    int key;
    cout  << "enter data to be found : " << endl;
    cin >> key;
    bool found = false;

    if(START == NULL){
        cout << "there is no list ";
        return 0;
    }
    TEMP = START;
    while(TEMP != NULL){
        if(TEMP->data == key){
            found = true;
            cout << "the data "<< key << " is found at " << pos << endl;
            break;
        }
    TEMP = TEMP->next;
    pos++;
    }
    if(!found){
        cout << "data is not found.";
    }
    return 0;
}