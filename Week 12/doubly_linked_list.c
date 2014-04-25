#include<stdio.h>
#include<stdlib.h>

struct _node
{
	int				data;
	struct _node	*addr;
};
typedef struct _node node;

node* XOR(node* a, node* b)
{
	return (node*)((unsigned int)a^(unsigned int)b);
}

void traverseForward(node* head)
{
		node* prevAddr	=	NULL;
		node* nextAddr	=	NULL;
		node* currNode	=	NULL;

	if(head==NULL)
	{
		printf("Empty list!\n");
		return;
	}

	currNode = head;

	while(currNode != NULL)
	{
		printf("%d ",currNode->data);
		nextAddr	= XOR(prevAddr,currNode->addr);
		prevAddr	= currNode;
		currNode	= nextAddr;
	}
}

void traverseReverse(node* tail)
{
		node* prevAddr	=	NULL;
		node* nextAddr	=	NULL;
		node* currNode	=	NULL;

	if(tail==NULL)
	{
		printf("Empty list!\n");
		return;
	}

	currNode = tail;

	while(currNode != NULL)
	{
		printf("%d ",currNode->data);

		prevAddr	= XOR(nextAddr,currNode->addr);
		nextAddr	= currNode;
		currNode	= prevAddr;
	}
}



node* insertAtStart(node** head,int data)
{
		node* temp = NULL;

	temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->addr = XOR(NULL,*head);

	if(*head!=NULL)
	{
		(*head)->addr = XOR(temp,XOR((*head)->addr,NULL));
	}

	*head = temp;
	return *head;
}

void deleteFirst(node** head)
{
		node* nextNode = NULL;

	if(*head==NULL) return;
	nextNode = XOR(NULL,(*head)->addr);
	if(nextNode == NULL)
	{
		*head = NULL;
		return;
	}

	nextNode->addr = XOR(nextNode->addr,(*head));
	*head = nextNode;

}

int main()
{
	fn();
	node* list = NULL;
	insertAtStart(&list,2);
	insertAtStart(&list,3);
	insertAtStart(&list,4);
	insertAtStart(&list,5);

	traverseForward(list);
	deleteFirst(&list);
	traverseForward(list);
	return 0;
}
