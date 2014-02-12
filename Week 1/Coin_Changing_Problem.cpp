#include<stdio.h>

// Using memoization
int memArray[1000][1000];

int Count(int * arr, int num, int sum)
{
	if(memArray[num][sum]!=-1) return memArray[num][sum];
	else
	{
		if(sum==0) 
		{
			memArray[num][sum]=1;
			return memArray[num][sum];
		}
		
		else if(num<=0 && sum>=1) return 0;
		else if(sum<0) return 0;

		else
		{
			int including		= Count(arr,num,sum-arr[num-1]);
			int excluding		= Count(arr,num-1,sum);
			memArray[num][sum]	= including + excluding;

			return memArray[num][sum];
		}
	}
}

int main()
{
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
			memArray[i][j]=-1;

	int arr[]={1,2,5,10,20,50,100};
	int sum = 100;
	printf("%d",Count(arr,sizeof(arr)/sizeof(int),sum));
	return 0;
}
