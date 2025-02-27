#include <iostream> 
#include <queue> 
using namespace std; 
//new one
  
/* A binary tree node has key, pointer to left child 
and a pointer to right child */
struct Node { 
    int key; 
    struct Node* left, *right; 
}; 
  
/* function to create a new node of tree and r 
   eturns pointer */
struct Node* newNode(int key) 
{ 
    //Your code here
    Node* node = new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}; 
  
/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp) 
{ 
    if (!temp) 
        return; 
  
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 
  
/*function to insert element in binary tree */
void insert(struct Node* temp, int key) 
{ 
  
    // Do level order traversal until we find 
    // an empty place.  
    
    //Your code here
    if(temp==NULL){
        temp = newNode(key);
        return;
    }
    queue<Node*>q;
    q.push(temp);
    while(!q.empty()){
        if(q.front()->left==NULL){
            q.front()->left = newNode(key);
            return;
        }
        if(q.front()->left){
            q.push(q.front()->left);
        }
        if(q.front()->right==NULL){
            q.front()->right = newNode(key);
            return;
        }
        if(q.front()->right){
            q.push(q.front()->right);
        }
        q.pop();
    }
    
} 
  
// Driver code 
int main() 
{ 
    struct Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    cout << "Inorder traversal before insertion:"; 
    inorder(root); 
  
    int key = 12; 
    insert(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 
  
    return 0; 
} 