#include <stdio.h>
#include <stdlib.h>

struct _tNode
{
	long time;
	int hobs;
};

typedef struct _tNode Node;

int TimeToDigHole;
int LastTime;
int HobArray[101][101];

Node Arr[101];

int NodeMax(const void* a, const void* b)
{
	Node A;
	Node B;
	A = *(Node*)a;
	B = *(Node*)b;

	if(A.time>B.time) return 1;
	else if(A.time==B.time) return 0;
	else return -1;
}

int MAX(const void* a, const void* b)
{
	int A,B;
	A = *(int*)a;
	B = *(int*)b;

	if(A>B) return 1;
	else if (A==B) return 0;
	else return -1;
}

// return the index where the current node is added
int AllocateHole(int index)
{
	// if the element at index 'index' already has 2 hobbits; save the hobbit in next index
	if(Arr[index].hobs==2)
	{
		index +=1;
	}

	Arr[index].hobs += 1;
	LastTime = Arr[index].time;

	// increment the time only in case a hobbit is added for the first time
	if(Arr[index].hobs ==1)
		Arr[index].time += TimeToDigHole;

	return index;
}

int main()
{
	int T,N,M,K;
	int row=0,col=0;
	int i;
	int addedAtIndex	= 0;

	scanf("%d",&T);
	while(T--)
	{
		LastTime		= 0;
		addedAtIndex	= 0;
		row				= 0;
		col				= 0;

		memset(Arr,0,sizeof(Node)*101);

		scanf("%d %d %d %d",&N,&M,&K,&TimeToDigHole);

		for(row=0;row<N;row++)
		{
			for(col=0;col<M;col++)
			{
				scanf("%d",&(HobArray[col][row]));
			}
		}

		for(col=0;col<M;col++)
		{
			qsort(HobArray[col],row,sizeof(int),MAX);
		}

		for(i=0;i<col;i++)
		{
			Arr[i].time = HobArray[i][0];
		}

		// sort the Arr so that now it contains the nodes stored in the sorted order.
		qsort(Arr,col,sizeof(Node),NodeMax);
		
		while(K)
		{
			addedAtIndex = AllocateHole(addedAtIndex);
			// sort
			qsort(Arr,col,sizeof(Node),NodeMax);
			K--;
		}
		
		printf("%d\n",LastTime);

	}
	return 0;
}