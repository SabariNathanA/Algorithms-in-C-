#include <iostream>

void kadine(int *a,unsigned int end)
{
	int sum = 0,max=-100;
	unsigned int startINdex = 0;
	unsigned int endIndex;
	unsigned int j=0;
	while(j<end)
	{
		sum+=a[j];
		std::cout<<sum<<std::endl;
		if(sum>max)
		{
			max=sum;
			endIndex=j;
		}
		else if(sum<=0)
		{
			sum=0;
			startINdex = j+1;
		}
		j++;
	}
	std::cout<<max<<" between "<<startINdex<<" to "<<endIndex;
}
int main()
{
	int a[]={60,-64,92,-55,80};
	kadine(a,5);
}
