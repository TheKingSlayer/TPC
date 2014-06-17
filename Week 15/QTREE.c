#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _tNode tNode;
struct _tNode
{
	int		nodeValue;
	int*	ptrToEdge;
	tNode*	next;
};

typedef struct _tParentNode tParentNode;
struct _tParentNode
{
	// For the adjacency list
	tNode*	next;
	// For the last node of the adj. list
	tNode*	lastNode;
};

// an array to store the edge weight at index i
int			edgeArray[10002];
// A tParentNode array.
tParentNode adjListArray[10002];
tNode*		nodePool;
int			poolCounter;
char		FLAG;
int			endNode;
int			Maximum;
char		nodesVisited[10002];

void maxPathTillNow(int startNode, int maxWtTillNow)
{
		tNode*	nextNode;
		int		wtOfCurrEdge;
		int		nodeVal;
		int		biggerWt;

	// FLAG will be set only when the end node is reached.
	if(FLAG) return;

	if(startNode==endNode)
	{
		FLAG=1;
		Maximum = maxWtTillNow;
		return;
	}

	// traverse all the nodes of adjListArray[startNode]
	// keep track of maxWtTillNow
	nextNode = adjListArray[startNode].next;
	while(nextNode)
	{
		nodeVal			= nextNode->nodeValue;
		
		// if this node is not yet visited
		if(!nodesVisited[nodeVal])
		{
			// mark as visited
			nodesVisited[nodeVal]	= 1;
			wtOfCurrEdge			= *(nextNode->ptrToEdge);
			biggerWt				= wtOfCurrEdge>maxWtTillNow?wtOfCurrEdge:maxWtTillNow;
			maxPathTillNow(nodeVal,biggerWt);
		}
		nextNode = nextNode->next;
	}
	return;
}



int main()
{
	int T, numNodes, a, b, wt, i;
	tNode* nodeA,* nodeB;
	char input[7];

	nodePool	= (tNode*)malloc(sizeof(tNode)*20002);
	poolCounter = 0;

	scanf("%d",&T);

	while(T--)
	{
		memset(nodePool,0,sizeof(tNode)*20002);
		memset(adjListArray,0,sizeof(tParentNode)*10002);
		
		scanf("%d",&numNodes);
		numNodes;

		poolCounter = 0;
		for(i=1;i<numNodes;i++)
		{	
			scanf("%d %d %d",&a,&b,&wt);

			// store the weight of ith edge at edgeArray[i]
			edgeArray[i] = wt;

			nodeA = &(nodePool[poolCounter++]);
			nodeB = &(nodePool[poolCounter++]);

			nodeA->nodeValue = a;
			nodeB->nodeValue = b;

			nodeA->ptrToEdge = &(edgeArray[i]);
			nodeB->ptrToEdge = &(edgeArray[i]);

			// store the nodeA in list of adjListArray[b]
			// store the nodeB in list of adjListArray[a]

			if(adjListArray[a].next == NULL)
			{
				// First entry
				adjListArray[a].next		= nodeB;
			}
			else
			{
				(adjListArray[a].lastNode)->next = nodeB;
			}
			adjListArray[a].lastNode	= nodeB;

			if(adjListArray[b].next==NULL)
			{
				adjListArray[b].next = nodeA;
			}
			else
			{
				(adjListArray[b].lastNode)->next = nodeA;
			}
			adjListArray[b].lastNode = nodeA;
		}

		while(1)
		{
			
			scanf("%s",input);
			// Change a b(change cost of a edge to b)
			if(input[0]=='C')
			{
				scanf("%d %d",&a,&b);
				edgeArray[a]=b;
			}
			// Query max wt of path b/w a and b
			else if(input[0]=='Q')
			{
				// reset nodesVisited only in case of query
				memset(nodesVisited,0,sizeof(char)*10002);

				scanf("%d %d",&a,&b);
				FLAG		= 0;
				endNode		= b;
				Maximum		= -1;

				nodesVisited[a] = 1;

				maxPathTillNow(a,0);
				printf("%d\n",Maximum);
			}
			else if(input[0]=='D')
			{
				break;
			}
		}
	}
	return 0;
}
