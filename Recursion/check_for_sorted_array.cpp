#include <iostream>

bool sorted(int *a, int n)
{
	if(n==1)
		return true;
	else
	{
		bool as=(a[n-1]<a[n-2])?false:sorted(a,n-1);
		std::cout<<as<<std::endl;
		return as;
	}
}
int main()
{
	int aa[] = {1,2,4,4};
	std::cout<<sorted(aa,4);
	return 0;
}
