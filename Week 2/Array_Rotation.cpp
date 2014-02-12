#include<iostream>
#include<string>
#include<string.h>


char* Rotate(char* pOriginalArr, int pNumElements, int pLength)
{
	if(pNumElements>pLength)
	{
		pNumElements %= pLength;
	}

	if(pNumElements == pLength || pNumElements ==0)
	{
		return pOriginalArr;
	}
	else
	{
		char* tempArr = new char[pNumElements+1];
		tempArr[pNumElements]='\0';
		memcpy(tempArr,pOriginalArr,sizeof(char)*pNumElements);
		memmove(pOriginalArr,pOriginalArr+pNumElements,sizeof(char)*(pLength-pNumElements));
		memcpy(pOriginalArr+pLength-pNumElements,tempArr,sizeof(char)*pNumElements);
		delete tempArr;
		return pOriginalArr;
	}
}

void Print(char* pArray)
{
	printf("%s",pArray);
}

int main()
{
	// since there is no specification on the upper bound of the length of the array;
	// taking the input in a string.

		int digitsToReverse;
		std::string input;
		char* rotatedString = NULL;
		char* originalString = NULL;

	std::cin>>input;
	scanf("%d",&digitsToReverse);

	originalString	= new char[strlen(input.c_str())+1];
	strcpy(originalString,input.c_str());

	rotatedString	= Rotate(originalString,digitsToReverse,strlen(originalString));
	Print(rotatedString);
	return 0;
}
