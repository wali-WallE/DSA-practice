#include <iostream>
#include <string> // Need this for swap sometimes, or <algorithm>
#include <algorithm> // For swap
using namespace std;

const int max_size = 100;

class Heap{
private:
    int Arr[max_size]; // The class owns this.
    int size;          // The class owns this.

public:

    Heap(){
        size = 0;
    }

    void bubbleUp(int index){
        while(index > 0){
            int parent = (index-1)/2;
            if(Arr[index] < Arr[parent]){
                swap(Arr[index], Arr[parent]);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    void bubbleDown(){
        int index = 0; 
        while(true){
            int left = index*2 + 1;
            int right = index*2 + 2;
            int smallest = index;

            if(left < size && Arr[left] < Arr[smallest]){
                smallest = left;
            }

            if(right < size && Arr[right] < Arr[smallest]){
                smallest = right;
            }
            
            if(smallest != index){
                swap(Arr[index], Arr[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

    void insert(int val){
        if (size >= max_size) {
            cout << "Heap Full" << endl;
            return;
        }
        Arr[size] = val; 
        bubbleUp(size);  
        size++;          
    }

    void removeMax(){
        if (size == 0) return;
        
        int maxDeleted = Arr[0];
        Arr[0] = Arr[size-1];
        size = size-1;       
        bubbleDown();        
    }

    void display(){
        for(int i = 0; i < size; i++){
            cout << Arr[i] << " -> " ;
        }
        cout << "END" << endl;
    }
};

int main(){
    Heap h;

    h.insert(5);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);

    h.display();

    h.removeMax();
    h.display();
}