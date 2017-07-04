#include <queue>
#include <vector>
#include <iostream>
using namespace std;
//default is max_heap so, No special class(operator()) struct operator <
struct MIN_HEAP
{
	bool operator()(int a, int b)
	{
		return a>b;
	}
};
int main()
{
	int a;
	unsigned int K,count=0;
	cin>>K;
	//priority_queue<int> pq;
	priority_queue<int,vector<int>,MIN_HEAP> pq;
	while(cin>>a)
	{
		if(++count>K)
		{
			//if(pq.top() > a)
			if(pq.top() < a)//largest K numbers
			{
				pq.pop();
				pq.push(a);
			}
		}
		else
		{
			pq.push(a);
		}
	}
	while(K>0)
	{
		cout<<pq.top()<<'\t';
		K--;
		pq.pop();
	}
}
