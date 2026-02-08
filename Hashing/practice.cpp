#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10 

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, vector<int> &table) {
    int index = hashFunction(key);

    int originalIndex = index;
    
    while (table[index] != -1) {
        index = (index + 1) % SIZE; 
        
        if (index == originalIndex) {
            cout << "Table is full!" << endl;
            return;
        }
    }

    table[index] = key;
    cout << "Inserted " << key << " at index " << index << endl;
}

int main() {
    vector<int> hashTable(SIZE, -1);

    insert(42, hashTable); 
    insert(12, hashTable); 
    insert(55, hashTable); 
    
    return 0;
}