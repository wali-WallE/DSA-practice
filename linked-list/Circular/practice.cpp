#include <iostream>
#include <string>
using namespace std;

struct Node{
    Node* next;
    int PlayerId;
    string name;
    int health;
};

class Agent{
public:
    Node* START = NULL;
    Node* current = NULL;
    void JoinGame(int PlayerId, string name, int health){
        Node* newNode = new Node;
        newNode->PlayerId = PlayerId;
        newNode->name = name;
        newNode->health = health;

        if(START == NULL){
            START = newNode;
            newNode->next = START;
            current = newNode;
        }
        else{
            Node* temp = START;
            do{
                temp= temp->next;
            }while(temp->next != START);

            temp->next = newNode;
            newNode->next = START;
            current = newNode;
        }
    }

    void endTurn(Node* START){
        if(current == START){
            current = START->next;
        }
        else{
            current = current->next;
            cout << "Pointer moved to next player!";
        }
    }

    void eliminatePlayer(int PlayerId){
        Node* temp = NULL;
        Node* curr = NULL;
        Node* prev = NULL;
        if(START == NULL){
            cout << "no current players in game!" << endl;
        }
        else if(START->PlayerId == PlayerId){            
            if(START->next == START){
                START = NULL;
                current = NULL;
            }else{
                Node* temp = START;
                while(temp->next != START){
                    temp = temp->next;
                }
                START = START->next;
                temp->next = START;
            }

        }
        else{
            curr = START;
            do{
            if(curr->PlayerId == PlayerId){
                prev->next = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
            }while(curr!= START);
            }
            cout << "Player " << PlayerId << " eliminated." << endl;
        }
    
    void display(){
        if(START == NULL){
            cout << "No current players to display!";
        }
        else{
            Node* temp = START;
            do{
                cout << "PLayer Name: " << temp->name << " - PLayer Id: " << temp->PlayerId << " - Health: " << temp->health << endl;
                temp = temp->next; 
            }while(temp != START);
        }
    }
};

int main(){
    Agent A;

    A.JoinGame(101, "Reyna", 78);
    A.JoinGame(102, "Tejo", 89);
    A.JoinGame(103, "Waylay", 43);

    A.display();

    A.eliminatePlayer(102);
}

