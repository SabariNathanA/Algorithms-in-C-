#include <iostream>
#include <algorithm>

void minKsubarray(int *a,int k,int end)
{
	 int check[k];
	 int checkcount=0;
	 std::fill_n(check,k,0);
	 int i=0,j=0;
	 int minstart=0,minend=0,minlength = end;
	 while(j<end)
	 {
		 while((j<end)&&(checkcount<k))
		 {
			 if(check[a[j]-1]==0)
				checkcount+=1;
			check[a[j++]-1]+=1;
//			std::cout<<"here "<<checkcount<<std::endl;
		}
		minend = j-1;
		while(checkcount==k)
		{
//			std::cout<<"here inside check for dup"<<std::endl;
			check[a[i]-1] -= 1;
			if(check[a[i]-1]==0)
			{
				checkcount-=1;
				minstart = i;
			}
			i++;
		}
		if(minlength> minend-minstart +1)
			minlength = minend-minstart +1;
	}
	std::cout<<minlength<<" between "<<minstart<<" and "<<minend<<std::endl;;
}
int main()
{
	int a[] = {1,1,1,2,2,3,1};
	minKsubarray(a,3,7);
	return 0;
}
