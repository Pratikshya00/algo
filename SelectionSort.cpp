#include<iostream>
#define MAX 100
using namespace std;
int main()
{
	int arr[]={1,7,9,2,3,0,16,654,98},n=9;
	for(int i=0;i<n-1;i++)
	{
		int MinValue=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[MinValue])
			{
			MinValue=j;
			}	
		}
		if(i!=MinValue)
			swap(arr[MinValue],arr[i]);
	}
	for(auto value:arr)
		cout<<value<<" ";
	return 0;
}
