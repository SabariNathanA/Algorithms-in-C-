#include <iostream>

void minlen(int *a,unsigned int end,int max)
{	
	int sum = 0;
	unsigned int startINdex = 0;
	unsigned int endIndex;
	unsigned int j=0;
	unsigned  int minlength = end,minstart=0,minend=0;
	while(j<end)
	{
		while((sum<max) && (j<end))
		{
			sum+=a[j++];
			if(sum<=0)
			{
				sum=0;
				startINdex = j;
			}
//			std::cout<<sum<<"\t"<<startINdex<<std::endl;
		}
		endIndex=j-1;
		while((sum>=max) && (startINdex<=endIndex ))
		{
			if(minlength > (endIndex-startINdex)+1){
				minstart = startINdex;minend = endIndex;
				minlength = (endIndex-startINdex)+1;//std::cout<<minlength<<std::endl;}
			sum = sum-a[startINdex++];
//			std::cout<<"\t"<<sum<<"minlen"<<minlength<<"starrt"<<startINdex<<" end"<<endIndex<<std::endl;
		}
	}
	
	std::cout<<" "<<minlength<<" from "<<minstart<<" to "<<minend<<std::endl;
}
int main()
{
	int a[]={60,-64,92,-55,80};
	minlen(a,5,100);
}
