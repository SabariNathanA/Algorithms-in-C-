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
	swap(a,left,(i-1));
	return (i-1);
}

int findrank(int *a,int left,int right,int needed_rank)
{
	int index_of_partition = partition(a,left,right);
	if(needed_rank == (right-index_of_partition+1))
	{
		return a[index_of_partition];
	}
	else if(needed_rank < (right-index_of_partition+1))
	{
		return findrank(a,index_of_partition+1,right,needed_rank);
	}
	else
	{
		return findrank(a,left,index_of_partition-1,(needed_rank-right+index_of_partition-1));
	}
}

int main()
{
	int a[] = {32,4,1,54,43};
	
	std::cout<<findrank(a,0,4,1)<<std::endl<<findrank(a,0,4,2)<<std::endl<<findrank(a,0,4,3)<<std::endl<<findrank(a,0,4,4)<<std::endl;
	return 0;
}

