#include<iostream>
using namespace std;

class BST {
    int data;
    BST *left,*right;
    public: 
    BST() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    BST(int val){
        data = val;
        left = right = NULL;
    }
    BST *Insert(BST *root,int val) {
        if(root == NULL) {
            return new BST(val);
        }
        if(val > root->data){
            root->right  = Insert(root->right,val);
        } else {
            root->left = Insert(root->left,val);
        }
        return root;
    }
    void Inorder(BST *root){
        if(!root){
            return;
        }
        Inorder(root->left);
        cout<<root->data<<" -> ";
        Inorder(root->right);
    }
    BST *search(BST *root,int key){
        if(root == NULL || root->data == key)
        return root;
        if(root->data < key) {
            return search(root->right,key);
        } 
        
            return search(root->left,key);
    }

    BST *inOrderSuccessor(BST *root){
        BST *temp = root;
        while(temp && temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    BST *deleteNode(BST *root,int key){
        if(root == NULL)
        return root;
        if(key<root->data){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->data){
            root->right = deleteNode(root->right,key);
        }
        else {
            if(root->left == NULL && root->right == NULL)
            return NULL;

            else if (root->left == NULL){
                BST *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL){
                BST *temp = root->left;
                free(root);
                return temp;
            }

            BST *temp = inOrderSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
        return root;
    }
};

int main(){
    BST tree,*root = NULL;
    cout<<"Enter root element : ";
    int t;
    cin>>t;
    root = tree.Insert(root,t);
    l:
    cout<<"Enter 1 : Insert an element\nEnter 2 : Inorder Print\nEnter 3 : Search key\nEnter 4 : Delete element\nEnter any key : exit\nInput : ";
    int n;
    cin>>n;
    switch(n){
        case 1:{
            int x;
            cin>>x;
            tree.Insert(root,x);
            break;
        }
        case 2: {
            tree.Inorder(root);
            break;
        }
        case 3 : {
            int key;
            cout<<endl<<"Enter the key you want to search : ";
            cin>>key;
            BST *t = tree.search(root,key);
            cout<<"Tree with given key as root -: \n";
            if(t == NULL){
                cout<<"Element not found in the tree"<<endl<<endl;
                break;
            }
            tree.Inorder(t);
            cout<<endl;
            break;
        }
        case 4 : {
            int key;
            cout<<endl<<"Enter the key you want to delete : ";
            cin>>key;
            root = tree.deleteNode(root,key);
            tree.Inorder(root);
            break;
        }
        default : {
            goto X;
            break;
        }
    }
    goto l;
    X:
    return 0;
}