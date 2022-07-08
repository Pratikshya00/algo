#include<bits\stdc++.h>
using namespace std;
struct node{
	int info;
	node *link;
};
struct node *AddAfter(node *start,int data,int item)
{
	node *temp,*p;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			temp=(struct node *)malloc(sizeof(node));
			temp->info=data;
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	cout<<"item not present in the list\n";
	return start;
}
struct node *AddBefore(node *start,int data,int item){
	struct node *temp,*p;
	if(start==NULL){
		cout<<"List is empty\n";
		return start;
	}
	if(item==start->info)
	{
	temp=(struct node *)malloc(sizeof(node));
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
	}
	p=start;
	while(p->link!=NULL){
		if(p->link->info==item)
		{
			temp=(struct node *)malloc(sizeof(node));
			temp->info=data;
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	cout<<"item is not present in the list\n";
	return start;
}
struct node *AddAtBeg(node *start,int data)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
}
struct node *AddAtEnd(node *start,int data){
	node *temp,*p;
	temp=(node *)malloc(sizeof(node));
	temp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=temp;
	temp->link=NULL;
	return start;	
}
struct node *CreateList(node *start){
	int i,n,data;
	cout<<"Enter the number of nodes\n";
	cin>>n;
	start=NULL;
	if(n==0) return start;
	cout<<"Enter the element to be inserted\n";
	cin>>data;
	start=AddAtBeg(start,data);
	for(i=2;i<=n;i++){
		cout<<"Enter the number to be inserted\n";
		cin>>data;
		start=AddAtEnd(start,data);
	}
	return start;
}
struct node *Delete(node *start,int data)
{
	node *temp,*p;
	if(start==NULL){
		cout<<"List is empty\n";
		return start;
	}
	if(start->info==data)
	{
		temp=start;
		start=temp->link;
		free(temp);
		return start;
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data){
			temp=p->link;
			p->link=temp->link;
			free(temp);
			return start;	
		}
		p=p->link;
	}
	cout<<"Element is not found\n";
	return start;
}
void Display(node *start){
	node *p;
	if(start==NULL){
		cout<<"List is empty\n";
		return;
	}
	p=start;
	while(p!=NULL){
		cout<<p->info<<" ";
		p=p->link;
	}
	cout<<endl;
}
int main(){
	node *start=NULL;
	int data,choice,item;
	while(1){
		cout<<"1=Create List"<<endl;
		cout<<"2=Add at beginning"<<endl;
		cout<<"3=Add before node"<<endl;
		cout<<"4=Add after node"<<endl;
		cout<<"5=Add at end"<<endl;
		cout<<"6=Delete"<<endl;
		cout<<"7=Display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
	
		switch(choice){
			case 1:
				start=CreateList(start);
				break;
			
			case 2:
				cout<<"Enter the item to be inserted\n";
				cin>>item;
				start=AddAtBeg(start,item);
				break;
			case 3:
					cout<<"Enter the number to be inserted\n";
					cin>>data;
					cout<<"Enter the element before the number to be inserted\n";
					cin>>item;
					start=AddBefore(start,data,item);
					break;
				
			case 4:
					cout<<"Enter the number to be inserted\n";
					cin>>data;
					cout<<"Enter the element after the number to be inserted\n";
					cin>>item;
					start=AddAfter(start,data,item);
					break;	
				
			case 5:
				cout<<"Enter the item to be inserted\n";
				cin>>item;
				start=AddAtEnd(start,item);
				break;	
			
			case 6:
				cout<<"Enter the element to be deleted"<<endl;
				cin>>data;
				start=Delete(start,data);
				break;
			
			case 7:
					Display(start);
					break;	
		}
	}
	return 0;
      }
