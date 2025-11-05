#include<iostream>
using namespace std;
struct{
	int A[50];
	int length;
	int size;
}arr;
void insert (auto a[],int index,int value){
	if(index>=0&&index<=arr.length){
		
		for(int i=arr.length;i>index;i--)
		a[i]=a[i-1];
		arr.A[index]=value;
		arr.length++;;
	}
}
int main(){
	//struct.arr((10,20,23,34,54),10,5);
	for(int i=0;i<=10;i++)
	{
		arr.A[i]=i;
	}
	for(int i=0;i<=10;i++)
	{
		cout<<arr.A[i]<<" ";
			}
	
	cout<<endl;
	insert(arr.A,5,11);
	for(int i=0;i<=11;i++)
	{
		cout<<arr.A[i]<<" ";
			}
}
