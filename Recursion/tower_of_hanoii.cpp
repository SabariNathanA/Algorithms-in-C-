#include <iostream>
#include <string>
void toh(std::string from,std::string aux,std::string to,unsigned int n)
{
	if(n==1)
		std::cout<<n<<" from "<<from<<" to "<<to<<std::endl;
	else
	{
		toh(from,to,aux,n-1); //Move n-1 disks to aux stack
		std::cout<<(n)<<" from "<<from<<" to "<<to<<std::endl;// Move the nth disc to final stack
		toh(aux,from,to,n-1); //move n-1 from aux stack to final stack
	}
	return;
}
int main()
{
	std::string s1 = "A";
	std::string s2 = "B";
	std::string s3 = "C";
	toh(s1,s2,s3,3);
	return 0;
}
