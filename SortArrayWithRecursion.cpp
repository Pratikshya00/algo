#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> &v,int temp){
	if(v.size()==0||v[v.size()-1]<=temp){
		v.push_back(temp);
		return;
	}
	int val=v[v.size()-1];
	v.pop_back();
	insert(v,temp);
	v.push_back(val);	
}
void Sort(vector<int> &v){
	if(v.size()<=1)
		return;
	int temp=v[v.size()-1];
	v.pop_back();
	Sort(v);
	insert(v,temp);
}
int main(){
	vector<int> v;
	int n;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	Sort(v);
	cout<<"Sorted array is:"<<endl;
	for(auto val:v)
		cout<<val<<" ";
	return 0;
}
