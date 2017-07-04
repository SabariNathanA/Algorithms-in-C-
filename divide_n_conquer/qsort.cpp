#include <iostream>

int pivot (int *a, int left,int right)
{
	return (left+right)/2;
}
void swap(int *a, int from, int to)
{
	int temp = a[from];
	a[from] = a[to];
	a[to] = temp;
}
int partition(int *a, int left, int right)
{
	int index_of_pivot=pivot(a,left,right);
	swap(a,left,index_of_pivot);
	int i=left+1,j=left+1;
	while (j<=right)
	{
		if(a[left]>a[j])
		{
			swap(a,i,j);
			i++;
		}
		j++;
	}
	std::cout<<"inpart"<<i<<std::endl;
	swap(a,left,(i-1));
	return (i-1);
}

void qusort(int *a, int left, int right)
{
	if(left<right)
	{
		int index_of_partition;
		std::cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<std::endl;
		std::flush(std::cout);
		
		index_of_partition = partition(a,left,right);
		std::cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<std::endl;
		std::flush(std::cout);
		std::cout<<"inqusort"<<index_of_partition<<std::endl;
		
		qusort(a,left,index_of_partition);
		std::cout<<"after left"<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<std::endl;
		std::flush(std::cout);
		qusort(a,index_of_partition+1,right);
	}
	return;
}

int main()
{
	int a[] = {32,4,1,54,43};
	
	qusort(a,0,4);
	std::cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<std::endl;
	return 0;
}
