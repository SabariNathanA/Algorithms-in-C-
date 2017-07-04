#include <iostream>


void merge(int *a, int left,int mid, int right)
{
	std::cout<<left<<" "<<mid<<" "<<right<<std::endl;
	int b[(right - left)+1];
	int biter = 0;
	int ileft=left;
	int kmid = mid+1;
	while(ileft<=mid && kmid<=right)
	{
		if(a[ileft]<a[kmid])
		{
			std::cout<<a[ileft]<<"is less than"<<a[kmid]<<std::endl;
			b[biter++] = a[ileft++];
		}
		else
			b[biter++] = a[kmid++];
	}
	while(ileft<=mid)
		b[biter++] = a[ileft++];
	
	while(kmid<=right)
		b[biter++] = a[kmid++];
	
	biter=0;
	while(left<=right)
	{
		a[left] = b[biter++];
		std::cout<<left<<"-";
		std::cout<<a[left++]<<',';
	}
	std::cout<<std::endl;
}


void mergesort(int *a,int left, int right)
{
	if(left<right)
	{
		int mid = ( left + right )/2 ;
	
		mergesort(a,left,mid);
		
		for(int i=mid+1;i<=right;i++)
			std::cout<<a[i]<<" ";
		mergesort(a,mid+1,right);
		
		std::cout<<std::endl<<"before merge"<<std::endl;
		for(int i=mid+1;i<=right;i++)
			std::cout<<a[i]<<" ";
		merge(a,left,mid,right);
		std::cout<<std::endl<<"after merge"<<std::endl;
		for(int i=left;i<=right;i++)
			std::cout<<a[i]<<" ";
	}
}

int main()
{
	int a[] = {2,11,1,34,23};
	mergesort(a,0,4);
	for(int i=0;i<5;i++)
		std::cout<<a[i]<<std::endl;
	
}
