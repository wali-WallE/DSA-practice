#include <iostream>
#include <string>
using namespace std;

const int max_size = 100;

class Heap{
private:
int Arr[max_size];
int size;

public:

    Heap(){
        size = 0;
    }

    void bubbleUp(int index){
        while(index >0){
            int parent = (index-1)/2;
            if(Arr[index] > Arr[parent]){
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
        int largest = index;

        if(left <size && Arr[left] > Arr[largest]){
            largest = left;
        }
        if(right < size && Arr[right] > Arr[largest]){
            largest = right;
        }
        if(largest != index){
            swap(Arr[index], Arr[largest]);
            index  = largest;
        }else{
            break;
            }
        }
    }

    void insert(int index){
        Arr[size] = index;
        bubbleUp(size);
        size++;
    }

    void removeMax(){
        int maxDeleted = Arr[0];
        Arr[0] = Arr[size-1];
        size = size-1;
        bubbleDown();
    }

    void display(){
        
        for(int i = 0; i < size; i++){
            cout << Arr[i] << "-> " ;
        }
        cout << endl;
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
