#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node (int val){
        right = left = NULL;
        data = val;
    } 
};

class BESTST{
public:

    void insertNode(Node* &root, int data){
        if(root == NULL){
            root = new Node(data);
        }
        else if(data < root->data){
            insertNode(root->left, data);
        }
        else if(data > root->data){
            insertNode(root->right, data);
        }
    }

    void inOrder(Node* root){

        if(root == NULL){
            return; 
        }
        inOrder(root->left);
        cout << root->data << " -> ";
        inOrder(root->right);
    }

    bool searchVal(Node* root, int data){
        Node* curr = root;
        while(curr != NULL){
            if(curr->data == data){
                cout << "Value found: " << data << endl;
                return true;
            }
            else if(curr->data > data){ 
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        cout << "Value " << data << " NOT found." << endl;
        return false;
    }

    Node* findMin(Node* root){
        if(root == NULL) return NULL;
        Node* min = root;
        while(min->left != NULL){
            min = min->left;
        }
        cout << "Minimum value is: " << min->data << endl; 
        return min;
    }

    void deleteBst(Node* &root, int data){
        if(root == NULL){
            return;
        }
        else if(data < root->data){
            deleteBst(root->left, data);
        }
        else if(data > root->data){
            deleteBst(root->right, data);
        }
        else{
            
            if(root->left == NULL){
                Node* temp = root;
                root = root->right; 
                delete temp;        
            }
            else if(root->right == NULL){
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else{
                Node* temp = root->right;

                while(temp->left != NULL){
                    temp = temp->left;
                }
                root->data = temp->data; 
                deleteBst(root->right, temp->data); 
            }
            cout << "Deleted " << data << endl;
        }
    }
};


int main(){
    BESTST b;
    Node* root = NULL;
    
    b.insertNode(root, 10);
    b.insertNode(root, 20);
    b.insertNode(root, 30);
    b.insertNode(root, 40);
    b.insertNode(root, 50);
    b.insertNode(root, 60);

    b.inOrder(root);

    b.searchVal(root,20);
    b.searchVal(root,80);
    b.findMin(root);

    b.deleteBst(root,10);
    b.inOrder(root);
}