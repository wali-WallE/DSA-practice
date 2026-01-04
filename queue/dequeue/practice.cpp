#include <iostream>
#include <string>
using namespace std;

struct Player{
    int ID;
    string rank;
    int waittime;
};

const int size = 100;

class Game{
private:
Player Queue[size];
int front,rear;

public:
    Game(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (front == (rear + 1)%size);
    }

    bool isEmpty(){
        return (front == -1);
    }

    void joinLobby(int ID, string rank, int waittime){
        if(isFull()){
            cout << "cannot join the game queue full" << endl;
            return;
        }
        if(isEmpty()){
            rear = front = 0;
        }
        else{
            rear++;
        }
        Queue[rear].ID = ID;
        Queue[rear].rank = rank;
        Queue[rear].waittime = waittime;
        cout << "PLAYER ID: " << ID << " Joined." <<endl;
    }

    void assignMatch(){
        if(isEmpty()){
            cout << "No players to team up with." <<endl;
        }
        else{
            for(int i = 0; i < rear; i++){
                Queue[i] = Queue[i+1];
            }
            rear = rear-1;
            if(rear < 0){
                front = -1;
                rear = -1;
            }
        }
        cout << "Matched Assigned!" << endl;
    }

    void kickPlayer(int ID){
        if(isEmpty()){
            cout << "Queue is Empty!" << endl;
        }
        else{
        int foundIndex = -1;

        for(int i = 0; i <= rear; i++){
            if(Queue[i].ID == ID){
                foundIndex = i;
                break;
            }
        }
        if(foundIndex != -1){
            for(int j = foundIndex; j < rear; j++){
                Queue[j] = Queue[j+1];
            }
            rear--;
            if(rear < 0){
                    front = -1;
                    rear = -1;
                }
            cout << "Player ID: " << ID << " Kicked out!" << endl;
        }

        else{
            cout << "Player ID not found!" << endl;
            }
        }
    }
    void display(){
        if(isEmpty()){
            cout << "No players available!" << endl;
        }
        else{
            for(int i = front; i <= rear; i++){
                cout << "Player ID : " << Queue[i].ID << " - Rank : " << Queue[i].rank << " - Waiting  Time : " << Queue[i].waittime << "s"<<endl;
        }
    }
    }
};

int main(){
    Game g;

    g.joinLobby(101, "Diamond" , 21);
    g.joinLobby(102, "Platinum" , 12);
    g.joinLobby(103, "Iron", 3);
    g.joinLobby(104, "Gold" , 17);

    g.display();

    g.assignMatch();
    g.kickPlayer(104);
    g.display();
}
