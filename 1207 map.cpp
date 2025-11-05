#include<bits/stdc++.h>
using namespace std;
int func()
{
	vector<int> v={1,2,3,4,3,21,3,1,2,4};
	map<int,int> m;
	for(auto a:v)
	{
		m[a]++;
	}
	for(auto p:m)//for each p in m
	{	
		for(auto q:m)
		{
			if(p.second==q.second)
				return 0;
		}
		
	}
	return 1;
}
int main()
{
	cout<<func();
}
