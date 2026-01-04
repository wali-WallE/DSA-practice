#include <iostream>
#include <string>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int VideoID;
    string Title;
    double Duration;
};

class Player{
public:

    Node* START = NULL;
    Node* curr = NULL;
    
    void addVideo(string Title, int VideoID, double Duration){
        Node* temp = START;
        Node* newNode = new Node;
        newNode->Title = Title;
        newNode->VideoID = VideoID;
        newNode->Duration = Duration;
        newNode->next = NULL;
        if(START == NULL){
            START = newNode;
            newNode->prev = NULL;
            curr = newNode;
        }
        else if(START->next == NULL){
            START->next = newNode;
            newNode->prev = START;
            curr = newNode;
        }
        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            curr = newNode;
        }
        cout << "New video with " << VideoID << " was added." << endl;
    }

    void playNext(){
        if(START == NULL){
            cout << "No videos availble to play." << endl;
        }
        else if(curr->next ==NULL){
            cout << "End of playlist" << endl;
        }
        else{
            curr = curr->next;
            cout << "Now playing " << curr->Title << endl;
        }
    }

    void playPrev(){
        if(START == NULL){
            cout << "No videos availble to play." << endl;
        }
        else if(curr->prev == NULL){
            cout << "This is the first video." << endl;
        }
        else{
            curr = curr->prev;
            cout << "Now playing " << curr->Title << endl;
        }
    }

    void deleteVideo(){
        if(START == NULL){
            cout << "No videos availble to play." << endl;
        }
        else if(curr == START){
            START = START->next;
            if(START != NULL){
                START->prev = NULL;
            }
            curr = START;
        }
        else if(curr->next == NULL){
            curr->prev->next = NULL;
            curr = curr->prev;
        }
        else{            
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr = curr->next;
        }
    }

    void displayReverse(){
        Node* temp = START; 
        while(temp->next != NULL){
            temp = temp->next;
        }
        while (temp != NULL){
            cout << "Title : " << temp->Title << " - VideoID : " << temp->VideoID << " - Duration : " << temp->Duration << "minutes"<< endl;
            temp = temp->prev;
        }
    }
};


int main(){
    Player p;
    p.addVideo("Avengers(Endgame)", 101, 140.2);
    p.addVideo("Avatar", 102, 90.8);
    p.addVideo("Harry Potter", 103, 50.1);
    p.addVideo("Hunger Games", 104, 38.9);

    p.displayReverse();
    p.playNext();
    p.deleteVideo();
    p.playPrev();
    p.displayReverse();
}
