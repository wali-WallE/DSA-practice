#include <iostream>
using namespace std;

const int max_size = 100;

class Cyber{
int matrix[6][6];

    public:    
    int size;
    int Arr[max_size];

    Cyber(){
    for(int i = 0; i< 6; i++){
        for(int j = 0; j< 6; j++){
            matrix[i][j] = 0;
            }
        }
    }

    void addNetwork(int u, int v){
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void BFS(int start){
        int queue[100];
        bool visited[6] = {false};
        int front = 0;
        int rear = 0;

        queue[rear] = start;
        visited[start] = true;
        rear++;

        while( front != rear){
            int curr = queue[front];
            front++;

            cout << curr << " " << endl;
            
            for(int i = 0; i < 6; i++){
                if(matrix[curr][i] == 1 && visited[i] == false){
                    visited[i] = true;
                    queue[rear] = i;
                    rear++;
                }
            }       
        }
    }
};

int main(){
    Cyber c;

    c.addNetwork(0,1);
    c.addNetwork(0,2);
    c.addNetwork(1,3);
    c.addNetwork(1,4);
    c.addNetwork(2,5);

    cout << "HACKER DETECTED AT SERVER 0!" << endl;

    c.BFS(0);
}