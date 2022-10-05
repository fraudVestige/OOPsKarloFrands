#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node*right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter Data = "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1) return NULL;

    cout<<"Enter data to insert in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data to insert in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

node* buildTree2(node* root){
    cout<<"Enter num = "<<endl;
    int data;
    cin>>data;
    newRoot = new node(data);

    if(data == -1) return NULL;

    cout<<"Enter num to insert in left of "<<data<<endl;
    root->left = buildTree2(newRoot->left);

    cout<<"Enter num to insert in right of "<<data<<endl;
    root->right = buildTree2(newRoot->right);

    return newRoot;

}

void levelOrderTraversal(node* root){

    cout<<"Level Order Traversal"<<endl;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp ->left) q.push(temp->left);
            if(temp ->right) q.push(temp->right);
        }

    }

}

int heightOfTree(node* root){
    if(root == NULL) return 0;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight+1, rightHeight+1);
}

void printGivenLevel(node* root, int level){
    if(root == NULL) return;
    if(level == 1) cout<<root->data<<" ";
    else{
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

void reverseOrderTraversal(node* root){
    int h = heightOfTree(root);
    int i;
    for(i=h ; i>=1 ; i--){
        printGivenLevel(root, i);
    }
}

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

node* buildTreeFromLevelOrder(int arr[], int i, int n){
    node* root = NULL;
    if(i<n){
        root = new node(arr[i]);
        root->left = buildTreeFromLevelOrder(arr, 2*i + 1, n);
        root->right = buildTreeFromLevelOrder(arr, 2*i + 2, n);
    }
    return root;
}

int main(){
    node* root = NULL;

    //root = buildTree(root);

    // cout<<"Level order traversal : ";
    // levelOrderTraversal(root);

    // cout<<"Reverse level order traversal : ";
    // reverseOrderTraversal(root);

    // cout<<"Inorder traversal : ";
    // inorder(root);

    // cout<<"Preorder traversal : ";
    // preorder(root);

    // cout<<"Postorder traversal : ";
    // postorder(root);

    // cout<<"Height of tree : " << heightOfTree(root);
    // heightOfTree(root);

    int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    root = buildTreeFromLevelOrder(arr, 0, n);
    levelOrderTraversal(root);


    return 0;
}
