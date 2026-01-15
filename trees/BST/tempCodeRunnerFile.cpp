#include <iostream>
#include <string>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;

    Node (int val){
        left = right = NULL;
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
        }else{
            cout << "value already exists cannot add another same value." << endl;
        }
    }

    void inOrder(Node* &root){
        if(root == NULL){
            cout << "No tree to display the order!" << endl;
        }else{
            inOrder(root->left);
            cout << root->data << " -> " <<endl;
            inOrder(root->right);
        }
    }

    bool searchVal(Node* &root, int data){
        
        Node* curr = root;
        while(curr != NULL){
            if(root == NULL){
                cout << "No values exist. " << endl;
            }
            else if(curr->data == data){
                cout << "value found!" << endl;
                return true;
            }
            else if(curr->data > data){
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        return false;
    }

    Node* findMin(Node* &root){
        Node* min = root;
        while(min->left != NULL){
            min = min->left;
        }
        cout << "Minimum value is : " << min->data << endl; 
        return min;
    }

    void deleteBst(Node* &root, int data){
        if(root == NULL){
            cout << "No values to delete" << endl;
        }
        else if(data < root->data){
            deleteBst(root->left, data);
        }
        else if(data> root->data){
            deleteBst(root->right, data);
        }else{
            if(root->left == NULL && root->right == NULL){
                root = NULL;
            }
            else if(root->left == NULL){
                root = root->right;
            }
            else if(root->right == NULL){
                root = root->left;
            }
            else{
                Node* temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                root->data = temp->data;
                deleteBst(root->right , temp->data);
            }
        }

        cout << "Value " << data << " deleted from tree" << endl;
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