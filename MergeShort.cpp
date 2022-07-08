#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ar[N];
void Merge(int left,int right,int mid)
{
	int left_size=mid-left+1;
	int Left[left_size+1];
	int right_size=right-mid;
	int Right[right_size+1];
	
	for(int i=0;i<left_size;i++)
		Left[i]=ar[i+left];
	
	for(int i=0;i<right_size;i++)
		Right[i]=ar[i+mid+1];
		
	Left[left_size]=Right[right_size]=INT_MAX;
	int left_index=0;
	int right_index=0;
	for(int i=left;i<=right;i++)
	{
		if(Left[left_index]<=Right[right_index])
		{
			ar[i]=Left[left_index];
			left_index++;	
		}
		else{
			ar[i]=Right[right_index];
			right_index++;
		}
	}		
}
void MergeSort(int left,int right)
{
	int mid=(left+right)/2;
	if(left==right)
		return;
	MergeSort(left,mid);
	MergeSort(mid+1,right);
	Merge(left,right,mid);	
}
int main()
{
	int n;
	cout<<"Enter number of elements\n";
	cin>>n;
	cout<<"Enter the elements:\n";
	for(int i=0;i<n;i++)
		cin>>ar[i];
	MergeSort(0,n-1);
	cout<<"Sorted array is :"<<endl;
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";	
}
