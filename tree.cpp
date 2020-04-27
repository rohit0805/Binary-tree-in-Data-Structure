#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

struct node* create(int data){
	struct node *newnode=new node;
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}
void printnode(struct node *root,int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printnode(root->left,k-1);
	printnode(root->right,k-1);
}
void lefty(struct node *root,int level,int &max_level){
	if(root==NULL){
		return ;
	}
	if(level>max_level){
		cout<<root->data<<" ";
		max_level=level;
	}
	lefty(root->left,level+1,max_level);
	lefty(root->right,level+1,max_level);
}

void leftview(struct node *root){
	int max_level=0;
	lefty(root,1,max_level);
}
void righty(struct node *root,int level,int &max_level){
	if(root==NULL)
		return;
	if(level>max_level){
		cout<<root->data<<" ";
		max_level=level;
	}
	righty(root->right,level+1,max_level);
	righty(root->left,level+1,max_level);
}
void rightview(struct node *root){
	int max_level=0;
	righty(root,1,max_level);
}
void topview(struct node *root,map<int,pair<int,int>> &hash,int hor,int height){
	if(root==NULL)
		return;
	if(hash.find(hor)==hash.end()){
		hash[hor]=make_pair(root->data,height);
	}
	else{
		pair<int,int>p=(hash.find(hor))->second;
		if(p.second>height){
			hash[hor]=make_pair(root->data,height);
		}
	}
	topview(root->left,hash,hor-1,height+1);
	topview(root->right,hash,hor+1,height+1);
}
void bottomview(struct node *root,map<int,pair<int,int>> &hash,int hor,int height){
	if(root==NULL)
		return;
	if(hash.find(hor)==hash.end()){
		hash[hor]=make_pair(root->data,height);
	}
	else{
		pair<int,int>p=(hash.find(hor))->second;
		if(height>p.second){
			hash[hor]=make_pair(root->data,height);
		}
	}
	bottomview(root->left,hash,hor-1,height+1);
	bottomview(root->right,hash,hor+1,height+1);
}
int main(){
	struct node *root=create(20);
	root->left=create(8);
	root->right=create(22);
	root->left->left=create(4);
	root->left->right=create(12);
	root->left->right->left=create(10);
	//root->left->right->right=create(14);
	cout<<"Left view of a tree: ";
	leftview(root);
	cout<<endl;
	cout<<"Right view of a tree: ";
	rightview(root);
	cout<<"\nTop view of a tree: ";
	map<int,pair<int,int>> hash,has;
	topview(root,hash,0,1);
	for(auto i:hash){
		cout<<(i.second).first<<" ";
	}
	cout<<"\nBottom view of a tree: ";
	bottomview(root,has,0,1);
	for(auto i:has){
		cout<<(i.second).first<<" ";
	}
	return 0;
}