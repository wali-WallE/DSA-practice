#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


struct Node {
    string data;
    Node* left;
    Node* right;
    Node(string value){
        data = value;
        left = right = NULL;
    }
};

Node* buildTree(vector<string>&pre, vector<string>&post, int preStart, int preEnd, int postStart, int postEnd){
    if (preStart > preEnd){
        return NULL;
    }

    Node* root = new Node(pre[preStart]);

    if(preStart == preEnd){
        return root;
    }

    string leftRoot = pre[preStart + 1];
    int leftIndex = postStart;

    while(post[leftIndex] != leftRoot){
        leftIndex++;
    }
    
    int leftSize = leftIndex - postStart + 1;

    root->left = buildTree(pre, post, preStart+1, preStart+ leftSize, postStart, leftIndex);
    root->right = buildTree(pre, post, preStart+leftSize + 1, preEnd, leftIndex + 1, postEnd-1);

    return root;
}

void LevelOrder(Node* root){
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main(){
    vector<string> preOrder = {"A","B","C"};
    vector<string> postOrder = {"B","C","A"};    

    Node* root = buildTree(preOrder, postOrder, 0, preOrder.size()-1, 0, postOrder.size()-1);
    LevelOrder(root);
}