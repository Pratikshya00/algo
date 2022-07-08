#include<bits/stdc++.h>
using namespace std;
struct node{
	int info;
	node *left;
	node *right;
};
struct node *GetNewNode(int data){
	node *NewNode=new node();
	NewNode->info=data;
	NewNode->left=NULL;
	NewNode->right=NULL;
		return NewNode;
}
struct node *Insert(node *root,int data){
	if(root==NULL)
		root=GetNewNode(data);
	else if(data<root->info)
		root->left=Insert(root->left,data);
	else if(data>root->info)
		root->right=Insert(root->right,data);
	else
		cout<<"Duplicate Key\n";
	return root;				
}
void LevelOrderTraversal(node *root){
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *current=q.front();
		cout<<current->info<<" ";
		if(current->left!=NULL)
			q.push(current->left);
		if(current->right!=NULL)
			q.push(current->right);	
		q.pop();	
	}
	cout<<endl;
}
int FindMax(node *root){
	if(root==NULL){
		cout<<"Tree is Empty\n";
		return 0;
		}
		node *current=root;
		while(current->right!=NULL)
			current=current->right;
		cout<<"Maximum Number is "<<current->info<<endl;	
		
}
void FindMin(node *root){
	if(root==NULL){
		cout<<"Tree is empty\n";
		return;
	}
	node *current=root;
	while(current->left!=NULL)
			current=current->left;
	cout<<"Minumn value is "<<current->info<<endl;		
	}
struct node *Search(node *root,int data){
	if(root==NULL){
		cout<<"Not found\n";
		return NULL;
	}
	else if(data<root->left->info)
		return Search(root->left,data);
	else if(data>root->right->info)
		return Search(root->right,data);
	else 
	return root;	
}
node *findmaxad(node *root)
{
	while(root->right!=NULL)
	root=root->right;
	return root;
}
node *deletenode(node *root,int data)
{
	node *temp;
	if(root==NULL)
		return NULL;
	
	else if(data>root->info)
		root->right=deletenode(root->right,data);
		
	else if(data<root->info)
		root->left=deletenode(root->left,data);	
		
	else
	{
		//CASE 1: 2 CHILDREN
		if(root->right&&root->right)
		{
			temp=findmaxad(root->left);
			root->info=temp->info;
			root->left=deletenode(root->left,root->info);
		}
		//CASE 2: 1 CHILDREN
		else if(root->left==NULL)
		{
			temp=root;
			root=root->right;
			delete temp;		
		}
		else if(root->right==NULL)
		{
			temp=root;
			root=root->left;
			delete temp;
		}
		//CASE 3: NO CHiLDREN
		else
		{
			delete root;
			root=NULL;
		}
	}	
	return root;
}

int main()
{
	node *root;
	root=NULL;
	int data,choice;
	while(1){
		cout<<"1=Insert Value\n";
		cout<<"2=Level Order Traversal\n";
		cout<<"3=Find Maxmum\n";
		cout<<"4=Find Minimum\n";
		cout<<"5=Search\n";
		cout<<"6=Delete\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the data to be inserted\n";
				cin>>data;
				root=Insert(root,data);
				break;
				
			case 2:
				LevelOrderTraversal(root);
				break;
			
			case 3:
				FindMax(root);
				break;	
			
			case 4:
					FindMin(root);
					break;
			
			case 5:
					cout<<"Enter the number to be searched\n";
					cin>>data;
					root=Search(root,data);
					if(root==NULL)
						cout<<"Number is not present\n";
					else
						cout<<"Number is presnt\n";	
						break;
			
			case 6:
				cout<<"Enter the number to be deleted\n";
				cin>>data;
				root=deletenode(root,data);
				break;						
		}	
	}
	return 0;
}
