#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
     Node(int value){
        data = value;
        left = right = NULL;
    }
};

class insertion{
public:

    Node* insert(Node* root, int value){
        if(root == NULL){
            return new Node(value);
        }
        else if(value < root->data){
            root->left = insert(root->left,value);
        }
        else if(value > root->data){
            root->right = insert(root->right,value);
        }
        return root;
    }

    void inOrder(Node* root){
        if(root != NULL){
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }
};

int main(){
    insertion inst;
    Node* root = NULL;

    root = inst.insert(root,50);
    root = inst.insert(root,30);
    root = inst.insert(root,70);
    root = inst.insert(root,20);
    root = inst.insert(root,40);
    root = inst.insert(root,60);
    root = inst.insert(root,80);

    inst.inOrder(root);
}