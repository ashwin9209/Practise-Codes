#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int main()
{
	FILE *fp;
	char *buff = (char*) malloc (1024);

	fp = fopen ("inputData.txt", "r");
	if(fp == NULL)
		return -1;

	fgets(buff, 50, fp);

	while(*buff != '\0')
	{
		cout<<*buff;
		buff++;
	}

	return 0;


}