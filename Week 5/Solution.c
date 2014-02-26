#include<stdio.h>
#include<string.h>

int primes[] = {2,3,5,7,11};
typedef long long LL;

int main()
{
	LL a;
	double	 ans1=0;
	double*  p;

	char	input[8];
	int     t,len,i,shifts = 0,ans2=0;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		ans1	= 0;
		a		= 0;
		len		= 0;
		shifts	= 0;
		ans2	= 0;
		p		= &ans1;

		gets(input);
		len = strlen(input);
		for(i=0;i<len;i++)
		{
			a = input[i];
			a = a<<shifts;
			shifts = shifts+8;
			(*(LL*)p) = (*(LL*)p)|a;
			a = 0;
		}
		a=0;
		while(1)
		{
			ans1 = ans1 * (double)primes[((ans2++)+1)%5];
			a = ans1;
			if((double)a == ans1)
			{
				printf("%.1f %d\n",ans1,ans2);
				break;
			}
			if(ans2==500)
			{
				printf("%.1f %d\n",ans1,ans2);
				break;
			}
		}
	}
}

