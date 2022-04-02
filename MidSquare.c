#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
void intermediate_odd(long long,int);
int count_digit(long long, int);
int main()
{
	int a[20];
	long long seed;
	int digit;
	int n;
	int i,j;
	long long p;
	int count;
	int divisor;


	printf("Enter a number to generate the random number: ");
	scanf("%lld",&seed);
	p=seed;
	digit=0;
	digit=count_digit(p,digit);
	count=digit;

	if(digit%2!=0)
	{
		printf("\nThe mid square multipicate method cannot be applied as the number of digit of seed is %d(odd)",digit);
	}

	else
	{
		printf("\n How many random number you want to generate: ");
		scanf("%d",&n);

		printf("\nThe random numbers are:\n");

		for(i=0;i<n;i++)
		{
			seed=seed*seed;
			p=seed;
			digit=0;
			digit=count_digit(p,digit);
			digit=ceil(digit/4.0);


			for(j=0;j<digit;j++)
			{
				seed=seed/10;
			}


			divisor=pow(10,count);
			seed=seed%divisor;
			a[i]=seed;
			printf("%lld\t",seed);

			digit=0;
			p=seed;
			digit=count_digit(p,digit);

			if(digit%2!=0)
			{
				intermediate_odd(seed,digit);
				exit(0);
			}
		}
	}

	getch();
	return(0);
}


int count_digit(long long seed,int digit)
{
	long long p;
	p=seed;
	while(p!=0)
	{
		p=p/10;
		digit++;
	}
	return digit;
}

void intermediate_odd(long long seed, int digit)
{
	printf("\nThe intermediate seed %d has odd length %d and therefore mid square method cannot be applied from here",seed,digit);
}
