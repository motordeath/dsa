//Traversing in array with the help of structures
#include <stdio.h>
#include<iostream>
using namespace std;
struct Array
{
	int A[50];
	int size;
	int length;
};
struct Array arr={{12,12,34,54,32},10,5};
void traverse()
{
    
    int i;
	for(i=0;i<arr.length;i++)
		printf("%d ",arr.A[i]);
		printf("\n");
}
void insert(int index, int value)
{
	if(index>=0&&index<=arr.length)
	{
		for(int i= arr.length;i>index;i--)
		{
			arr.A[i]= arr.A[i-1];
		}
		arr.A[index]=value;
		arr.length++;
	}
}
void del(int index)
{
	if(index>=0&&index<=arr.length)
	{
		for(int i=index;i<arr.length;i++)
		{
			arr.A[i]= arr.A[i+1];
		}
		//arr.A[index]=value;
		arr.length--;
	}
}
void update(int index, int value)
{
	arr.A[index]=value;
}
int search(int key)
{
	int i;
	for(i=0;i<arr.length;i++)
	if(key==arr.A[i])
	return i;
	return -1;
}
int main()
{
	//struct Array arr;
	int i;
    /*printf("Enter the value of length-----\n");
	scanf("%d",&arr.length);
    printf("Enter array elements-----\n");
    for(i=0;i<arr.length;i++)
        scanf("%d",&arr.A[i]);
    */
	traverse();
	cout<<"insert"<<endl;
	insert(2,15);
	traverse();
	cout<<"delete"<<endl;
	del(1);
	traverse();
	cout<<"update"<<endl;
	update(5,13);
	traverse();
    int key;
    cin>>key;
    i=search(key);
    cout<<i<<endl;
}
