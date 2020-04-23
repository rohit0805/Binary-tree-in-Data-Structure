#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
struct node *create(int data){
	struct node *newnode=new node;
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}
void inorder(struct node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(struct node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node *root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void instack(struct node *root){
	if(root==NULL)
		return;
	stack<struct node*> s;
	do{
		while(root){
			s.push(root);
			root=root->left;
		}
		if(root==NULL){
			root=s.top();
			s.pop();
			cout<<root->data<<" ";
			root=root->right;
		}
	}
	while(!s.empty() || root!=NULL);
}
void prestack(struct node *root){
	if(root==NULL)
		return;
	stack<struct node*> s;
	s.push(root);
	while(!s.empty()){
		root=s.top();
		s.pop();
		cout<<root->data<<" ";
		if(root->right)
			s.push(root->right);
		if(root->left)
			s.push(root->left);
	}
}
void poststacktwo(struct node *root){
	if(root==NULL)
		return;
	stack<struct node*> s1,s2;
	s1.push(root);
	while(!s1.empty()){
		root=s1.top();
		s1.pop();
		s2.push(root);
		if(root->left)
			s1.push(root->left);
		if(root->right)
			s1.push(root->right);
	}
	while(!s2.empty()){
		root=s2.top();
		s2.pop();
		cout<<root->data<<" ";
	}
}
void poststackone(struct node *root){
	if(root==NULL)
		return ;
	stack<struct node*> s;
	do{
		while(root){
			if(root->right)
				s.push(root->right);
			s.push(root);
			root=root->left;
		}
		root=s.top();
		s.pop();
		if(!s.empty() && root->right && s.top()==root->right){
			s.pop();
			s.push(root);
			root=root->right;
		}
		else{
			cout<<root->data<<" ";
			root=NULL;
		}
	}
	while(!s.empty());

}
int main(){
	struct node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->right=create(5);
	root->right->left=create(6);
	root->right->right=create(7);
	cout<<"Recursive Inorder traversal"<<endl;
	inorder(root);
	cout<<"\nInordor traversal using Stack"<<endl;
	instack(root);

	cout<<endl;
	
	cout<<"\nRecursive Preorder traversal"<<endl;
	preorder(root);
	cout<<"\nPreordor traversal using Stack"<<endl;
	prestack(root);
	
	cout<<endl;

	cout<<"\nRecursive Postorder traversal"<<endl;
	postorder(root);
	cout<<"\nPostordor traversal using two Stack"<<endl;
	poststacktwo(root);
	cout<<"\nPostorder traversal using one Stack"<<endl;
	poststackone(root);
	return 0;
}
