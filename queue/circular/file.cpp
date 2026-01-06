#include <iostream>
using namespace std;

#define SIZE 5 

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if ((rear + 1) % SIZE == front) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        return false;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is Full! Can't insert " << element << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            
            rear = (rear + 1) % SIZE;
            
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Nothing to delete." << endl;
        } else {
            cout << "Deleted " << items[front] << endl;
            
            if (front == rear) {
                front = -1;
                rear = -1;
            } 

            else {
                front = (front + 1) % SIZE;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        
        cout << "Queue Elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            
            if (i == rear) break;
            
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    q.display();

    q.dequeue();
    q.dequeue();
    
    q.display();

    q.enqueue(60); 
    q.enqueue(70); 

    q.display();

    return 0;
}