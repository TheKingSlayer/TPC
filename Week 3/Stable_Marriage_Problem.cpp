#include<stdio.h>

int N;
int**	arr=NULL;
// index of men is the index of the man; and the value is his wife
int*	men = NULL;
// index of women is the index of the woman; and the value is her husband
int*	women = NULL;

void StableMarriage(int** arr,int N)
{
	int i,j,topstack,currMan,prefMan,prefWoman,currHusband,guyGotMarried=0;

	int* mStack = NULL;
	mStack = new int[N];

	for(i=0;i<N;i++)
		mStack[i]=i;

	// topstack indicates the current unmarried man
	topstack = N-1;

	while(topstack>-1)
	{
		guyGotMarried = 0;

		// currman is the current man under consideration
		currMan = mStack[topstack--];

		// check the preference of currMan in arr[currman]
		for(i=0;i<N;i++)
		{
			prefWoman = arr[currMan][i];

			// woman is unmarried; marry both
			if(women[prefWoman-N]==-1)
			{
				women[prefWoman-N] = currMan;
				men[currMan]     = prefWoman;
				guyGotMarried = 1;
				break;
			}
			// woman is married
			else
			{
				// current husband of the preferred woman
				currHusband = women[prefWoman-N];

				// loop ove preferences of the woman
				for(j=0;j<N;j++)
				{
					// if currHusband comes first, then he is preferred so do nothing
					// else if currMan comes first, marry prefWoman to currMan and currHusband is unmarried
					if(arr[prefWoman][j] == currHusband)
					{
						guyGotMarried = 0;
						break;
					}
					else if(arr[prefWoman][j] == currMan)
					{
						// add currHusband to the top of umarried men stack
						mStack[++topstack]	= currHusband;
						// currHusband has no wife now
						men[currHusband]	= -1;
						// marry currMan and prefWoman
						men[currMan]		= prefWoman;
						women[prefWoman-N]	= currMan;
						guyGotMarried		= 1;
						break;
					}
				}
			}
			// since the man got married. Do not check his prefernces now.
			if(guyGotMarried==1) break;
		}
	}
}

int main()
{
	int i,j;
	scanf("%d",&N);

	arr = new int*[N*2];
	men = new int[N];
	women = new int[N];

	for(i=0;i<N;i++)
	{
		men[i] = -1;
		women[i]=-1;
	}

	for(i=0;i<N*2;i++)
	{
		arr[i] = new int[N];
		for(j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	StableMarriage(arr,N);
	printf("Final Marriages:\tGIRL\tBOY\n");

	for(i=0;i<N;i++)
	{
		printf("%d\t%d\n",i+N,women[i]);
	}

	return 0;
}
