#include <iostream>
#include <stdio.h>
char aaa[5]={'0'};
void kary(int sizearr,int k)
{
	if(sizearr<1){
		for(int i=0;i<5;i++)
			std::cout<<aaa[i];
		std::cout<<std::endl;
		
		return;
	}
	for(int j=0;j<k;j++){
		aaa[sizearr-1] = '0' + j;
		kary(sizearr-1,k);
	}
	return;
}

int main()
{
		
		kary(5,3);
	return 0;
}
