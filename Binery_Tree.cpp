#include <iostream>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }   
};




// Function to build a binary tree from preorder traversal
static int curr = -1;
node* buildTree(vector<int> preorder){
    curr++;
    if(preorder[curr] == -1){
        return NULL;
    }
    node* root = new node(preorder[curr]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}



// Preorder traversal of the binary tree
void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}





// levelorder traversal of the binary tree
void levelorder(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}




int main(){
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node* root = buildTree(preorder);
    return 0;
}