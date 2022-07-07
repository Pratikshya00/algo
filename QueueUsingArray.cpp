#include<bits/stdc++.h>
using namespace std;
#define MAX 10
int queue_arr[MAX];
int rear=-1;
int front=-1;
bool isFull(){
	if(rear==MAX-1)
		return true;
	else return false;	
}
bool isEmpty(){
	if(front==-1||front==rear+1)
		return true;
	else return false;	
}
void push(int item){
	if(isFull()){
		cout<<"Overflow\n";
		return;
	}
	if(front==-1)
		front=0;
	rear=rear+1;
	queue_arr[rear]=item;
}
int pop(){
	if(isEmpty()){
		cout<<"Underflow\n";
		exit(1);
	}
	int item=queue_arr[front];
	front=front+1;
	return item;
}
void Display(){
	if(isEmpty()){
		cout<<"Underflow\n";
		exit(1);
	}
	cout<<"Queue is :\n";
	for(int i=front;i<=rear;i++)
		cout<<queue_arr[i];
	cout<<endl<<endl;	
}
int main()
{
	int choice,item;
	while(1){
		cout<<"1=Push\n";
		cout<<"2=Pop\n";
		cout<<"3=Display\n";
		cout<<"4=Quie\n";
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
