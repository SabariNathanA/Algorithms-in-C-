#include<iostream>
class fib
{
	unsigned int number_to_find;
	public:
	fib (unsigned int a)
	{
		this->number_to_find = a;
	}
	unsigned int fibo_rec(unsigned int input)
	{
		if(input == 0)
			return 0;
		else if(input == 1)
			return 1;
		else 
			return (fibo_rec(input-1) + fibo_rec(input-2));
	}
	unsigned int fibo_dp(unsigned int input)
	{
		int *a = new int(input);
		if (input>2)
		{
			*a = 0;
			*(a+1) = 1;
		}
		std::cout<<std::endl<<*(a)<<"\t"<<*(a+1)<<"\t";
		unsigned int iter = 2;
		while(iter <= input)
		{
			*(a+iter) = (*(a+iter-2))+(*(a+iter-1));
			std::cout<<*(a+iter)<<"-"<<iter<<"\t";
			iter = iter+1;
		}
		return *(a+iter-1);
	}
};
int main()
{
	const unsigned int a_const = 5; //const cast works only with pointers
	fib *f = new fib(a_const);
	unsigned int result = f->fibo_rec(6);
	std::cout<<result<<"\t";
	result = f->fibo_dp(7);
	std::cout<<result<<"\t";
	f = 0;
	delete f;
	return 0;
}
