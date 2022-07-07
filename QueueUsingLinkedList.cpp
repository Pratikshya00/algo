#include<bits/stdc++.h>
using namespace std;
struct node{
	int info;
	node *link;
}*front=NULL,*rear=NULL;
bool isEmpty(){
	if(front==NULL)
		return true;
	else return false;	
}
void push(int item){
	node *temp;
	temp=new node();
	temp->info=item;
	temp->link=NULL;
	if(front==NULL)
		front=temp;
	else
		rear->link=temp;
		rear=temp;		
}
int pop(){
	node *temp;
	int item;
	if(isEmpty()){
		cout<<"underflow\n";
		exit(1);
	}
	temp=front;
	item=temp->info;
	front=front->link;
	delete temp;
	return item;
}
void Display(){
	node *ptr;
	ptr=front;
	if(isEmpty()){
		cout<<"Queue is empty\n";
		return;
	}
	cout<<"Queue is:";
	while(ptr!=NULL){
		cout<<ptr->info<<" ";
		ptr=ptr->link;
	}
}
int main(){
	int choice,item;
	while(1){
		cout<<"1=Push\n";
		cout<<"2=Pop\n";
		cout<<"3=Display\n";
		cout<<"4=Qui1\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the item to be inserted\n";
				cin>>item;
				push(item);
				break;
				
			case 2:
				cout<<"Poped item is "<<pop()<<endl;
				break;
				
			case 3:
				Display();
				cout<<endl;
				break;
			case 4:
				exit(1);
				break;
			default:
				cout<<"Wrong choice\n";				
		}
	}
	return 0;
}
