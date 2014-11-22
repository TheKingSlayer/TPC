//JSR
#include<stdio.h>
#include<string.h>

void start				(char* pStr);
void palin				(char* pStr);
int	 type				(char* pStr, int pLeft,int pRight);
void print_even			(char* pLeftPart);
void print_odd			(char* pLeftPart);
void increment_string	(char* pString, int lastNdx);
void str_rev			(char* pStr);

int STRLEN;
int	ALLNINE;

int main()
{
	int		T;
	char	str[1000003];

	scanf("%d",&T);
	getchar();
	while(T--)
	{
		ALLNINE	= 0;
		gets(str);
		start(str);
	}
	return 0;
}

void start(char* pStr)
{
		int initLen, strPos;
	initLen = strlen(pStr);
	strPos = 0;
	while( (*pStr) == '0')
	{
		strPos++;
		pStr++;
	}
	if(strPos >= initLen)
	{
		printf("1\n");
		return;
	}
	palin(pStr);
}

void palin	(char* pStr)
{
		int	len, midndx, left, right, status;

	len		= strlen(pStr);
	STRLEN	= len;
	// Even
	if(len%2==0)
	{
		right	= len/2;
		left	= right-1;
		status	= type(pStr,left,right);

		// left>right
		if(status==1)
		{
			pStr[right]='\0';
			print_even(pStr);
		}
		else
		{
			increment_string(pStr,left);
			if(ALLNINE)
			{
				memset(pStr,'0',sizeof(char)*STRLEN);

				pStr[STRLEN+1]='\0';
				pStr[0]='1';
				pStr[STRLEN]='1';
				printf("%s\n",pStr);
			}
			else
			{
				pStr[right]	= '\0';
				print_even(pStr);
			}
		}
	}
	else
	// Odd
	{
		midndx	= len/2;
		left	= midndx-1;
		right	= midndx+1;
		status	= type(pStr,left,right);

		if(status==1)
		{
			pStr[right]='\0';
			print_odd(pStr);
		}
		else
		{
			increment_string(pStr,midndx);
			if(ALLNINE)
			{
				memset(pStr,'0',sizeof(char)*STRLEN);
				pStr[STRLEN+1]='\0';
				pStr[0]='1';
				pStr[STRLEN]='1';
				printf("%s\n",pStr);
			}
			else
			{
				pStr[right]='\0';
				print_odd(pStr);
			}
		}
	}
}

// return 0 if palindrome
// return 1 if right > left
// return -1 if left>right
int type(char* pStr, int pLeft,int pRight)
{
		
	for(;pLeft>-1;pLeft--, pRight++)
	{
		if(pStr[pLeft] > pStr[pRight])
		{
			return 1;
		}
		else if(pStr[pLeft] < pStr[pRight])
		{
			return -1;
		}
	}
	return 0;
}

void print_even(char* pLeftPart)
{
	printf("%s",pLeftPart);
	str_rev(pLeftPart);
	printf("%s\n",pLeftPart);
}

void print_odd(char* pLeftPart)
{
	printf("%s",pLeftPart);
	str_rev(pLeftPart);
	printf("%s\n",pLeftPart+1);
}


void increment_string(char* pString, int lastNdx)
{
	if(lastNdx==0)
	{
		if(pString[0]=='9')
		{
			pString[0] = '0';
			ALLNINE = 1;
			return;
		}
		// increment the char
		pString[0]++;
		return;
	}
	else
	{
		if(pString[lastNdx]=='9')
		{

			pString[lastNdx]='0';
			increment_string(pString,--lastNdx);
		}
		else
		{
			pString[lastNdx]++;
		}
	}
}

void str_rev (char* pStr)
{
		int len,left,right;
		char temp;

	len = strlen(pStr);
	if(len==0) return;
	if(len%2==0)
	{
		right	= len/2;
		left	= right-1;
	}
	else
	{
		left	= len/2 ;
		right	= left+1;
		left--;
	}

	for(;left>-1;left--, right++)
	{
		temp		= pStr[left];
		pStr[left]	= pStr[right];
		pStr[right]	= temp;
	}
}