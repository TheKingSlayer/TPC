#include<stdio.h>

int Arr[10002][7];

// [0] is left of n node
// [1] is right of n node
// [2] is parent of n node
// [3] is the length of left path
// [4] is the length of right path 
// [5] is the max length(out of left/right)
// [6] is the left length + right length

int n;
int max(int a,int b);

#define MAX(a,b) max((a),(b))

int max(int a,int b)
{
	return a>b?a:b;
}
int MaxPathLengthofNode(int node);

int FillLeftandRightpathLen()
{
	int i=1;
	int maxat;
	int rootNode;
	int maximum=0;
	for(i=1;i<=n;i++)
	{
		MaxPathLengthofNode(i);
		if(Arr[i][6]>maximum) maximum = Arr[i][6];
	}
	return maximum;
}

int MaxPathLengthofNode(int node)
{
	if(Arr[node][5]==-1)
	{
		int leftLength=0;
		int rightLength=0;

		if(Arr[node][3]==-1) 
		{
			// no left node
			if(Arr[node][0]==0)
			{
				Arr[node][3] = 0;
			}
			// left node exists
			else
			{
				Arr[node][3] = 1 + MaxPathLengthofNode(Arr[node][0]);
			}
		}
		leftLength = Arr[node][3];

		if(Arr[node][4]==-1) 
		{
			// no left node
			if(Arr[node][1]==0)
			{
				Arr[node][4] = 0;
			}
			// left node exists
			else
			{
				Arr[node][4] = 1 + MaxPathLengthofNode(Arr[node][1]);
			}
		}
		rightLength = Arr[node][4];
		Arr[node][5] = leftLength>rightLength?leftLength:rightLength;
	}
	Arr[node][6] = Arr[node][3] + Arr[node][4];
	return Arr[node][5];
}

int main()
{
	int i,t;
	scanf("%d",&n);
	t=n;
	int a,b;

	for(i=0;i<=n;i++)
	{
		Arr[i][3] = -1;
		Arr[i][4] = -1;
		Arr[i][5] = -1;
		Arr[i][6] = -1;
	}

	while(--t)
	{
		scanf("%d %d",&a,&b);
		// if left child is 0(not assigned), set as b
		if(Arr[a][0] == 0 ) Arr[a][0] = b;
		// else right child is b
		else Arr[a][1] =b;
		// set parent as a
		Arr[b][2] = a;
	}
	printf("%d",FillLeftandRightpathLen());

	return 0;
}
