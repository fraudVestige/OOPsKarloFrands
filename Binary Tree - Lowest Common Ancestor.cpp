// Lowest Common Ancestor
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* lchild;
		Node* rchild;
		Node(int d){
			data=d;
			lchild=NULL;
			rchild=NULL;
		}
};

Node* InputTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	Node* newNode= new Node(d);
	newNode->lchild=InputTree();
	newNode->rchild=InputTree();
	return newNode;
}


void leveltraverseBFS(Node* root){
	if(root==NULL)
		return;
	queue<pair<Node*,int> > q;
	q.push(make_pair(root,1));
	int level=1;
	while(!q.empty()){
		pair<Node*,int> p=q.front();
		q.pop();
		Node* n=p.first;
		int l=p.second;
		
		if(l!=level){
			cout<<endl;
			level=l;
		}
		cout<<n->data<<" ";
		
		if(n->lchild)
			q.push(make_pair(n->lchild,l+1));
		if(n->rchild)
			q.push(make_pair(n->rchild,l+1));
		
		
	}
}


//The only condition for a node to be an ancestor is that one of a & b should be present in its leftsubtree and other in right subtree
Node* commonAncestor(Node* root,int a,int b){
	if(root==NULL)
		return NULL;
	if((root->data== a) || (root->data==b)){
		return root;
	}
	Node* lchild=commonAncestor(root->lchild,a,b);
	Node* rchild=commonAncestor(root->rchild,a,b);
	if((lchild!= NULL) && (rchild!=NULL)){ //this means that : one of a & b is present in its leftsubtree and other in right subtree
		return root; 
	}
	if(lchild==NULL)
		return rchild;
	return lchild;
}




int main(){
	Node* root=InputTree(); //Input: 20 8 4 -1 -1 12 10 -1 -1 14 -1 -1 22 -1 -1
	cout<<"Tree: \n";
	leveltraverseBFS(root);
	cout<<"\n\n";
	
	int a=14 ,b=12 ;
	cout<<"Common ancestor of "<<a<<" & "<<b<<" are: ";
	Node* ancestor=commonAncestor(root,a,b);
	cout<<ancestor->data<<endl;
	
	
}
