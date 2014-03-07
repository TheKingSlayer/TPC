#include<stdio.h>

typedef unsigned long long ULL;

ULL memArray[46];

ULL Total(int YEARS, int BRANCHES)
{
	ULL year=0;
	ULL maxBranches = 0;
	ULL branchNum = 0;
	ULL subYear = 0;
	ULL subTotal = 0;
	ULL ans = 0;

	for(year=2;year<=YEARS;year++)
	{
		maxBranches		= year-1;
		subYear			= year-1;
		subTotal		= 0;
		for(branchNum=1; branchNum<= maxBranches && branchNum<= BRANCHES ; branchNum++)
		{
			subTotal += memArray[subYear--];
		}
		memArray[year] = year+subTotal;

		if(memArray[year]>1234567890) 
			return memArray[year];
	}
	return memArray[YEARS];
}

int main()
{
	ULL years;
	ULL branches;
	ULL ans;
	scanf("%llu %llu",&years,&branches);
	while(years)
	{
		years--;
		switch(branches)
		{
			case 0:
				{
					if(years>=1234567891)
						ans = 1234567891;
					else
						ans = years;
					break;
				}
			case 1:
				{
					if(years>=49690)
						ans = 1234572895;
					else
					{
						ans = (years)*(years+1);
						ans = ans>>1;
					}
					break;
				}
			default:
				{
					memArray[0] = 0;
					memArray[1] = 1;
					ans = Total(years,branches);
					break;
				}
		}
		printf("%llu\n",ans);
		scanf("%llu %llu",&years,&branches);
	}
	return 0;
}
