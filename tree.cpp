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
void deletedeep(struct node *root,struct node* dnode){
	queue<struct node*> q;
	q.push(root);
	struct node *temp;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp==dnode){
			temp=NULL;
			delete(dnode);
			return;
		}
		if(temp->right){
			if(temp->right==dnode){
				temp->right=NULL;
				delete(dnode);
				return;
			}
			else{
				q.push(temp->right);
			}
		}
		if(temp->left){
			if(temp->left==dnode){
				temp->left=NULL;
				delete(dnode);
				return;
			}
			else{
				q.push(temp->left);
			}
		}
	}
}
struct node* deletion(struct node *root,int data){
	if(root==NULL)
		return NULL;
	if(root->left==NULL && root->right==NULL){
		if(root->data==data)
			return NULL;
		else
			return root;
	}
	queue<struct node*> q;
	q.push(root);
	struct node *remp,*temp,*keynode=NULL;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp->data==data){
			keynode=temp;
		}
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	if(keynode!=NULL){
		int x=temp->data;
		deletedeep(root,temp);
		keynode->data=x;
	}
	return root;
}
int main(){
	struct node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->right=create(5);
	root->right->left=create(6);
	root->right->right=create(7);
	cout<<"Before deletion"<<endl;
	levelorder(root);
	cout<<"After deletion"<<endl;
	root=deletion(root,3);
	levelorder(root);
	return 0;
}
