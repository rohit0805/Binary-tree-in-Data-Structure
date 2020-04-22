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
void levelorder(struct node *root){
	if(root==NULL){
		return ;
	}
	queue<struct node*> q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		cout<<root->data<<" ";
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
	cout<<endl;
}
void insertion(struct node *root,int data){
	if(root==NULL){
		return;
	}
	queue<struct node*> q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		if(root->left==NULL){
			root->left=create(data);
			return;
		}
		else{
			q.push(root->left);
		}
		if(root->right==NULL){
			root->right=create(data);
			return;
		}
		else{
			q.push(root->right);
		}
	}
}
int main(){
	struct node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->right=create(5);
	root->right->right=create(7);
	cout<<"Before insertion"<<endl;
	levelorder(root);
	cout<<"After insertion"<<endl;
	insertion(root,6);
	levelorder(root);
	return 0;
}
