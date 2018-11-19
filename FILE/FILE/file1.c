#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h>
void creat_file()
{
	FILE *fp = fopen("四则运算.txt", "w");
	if (fp == NULL)
	{
		perror("");
	}
	int a = 0;
	int b = 0;
	char ch = 0;
	char num[] = { '+', '-', '*', '/' };
	char buf[1024] = "";
	for (int i = 0; i < 10; i++)
	{
		a = rand();
		b = rand();
		while (b == 0)
			b = rand();
		ch = num[rand() % 4];
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%d%c%d=\n", a, ch, b);
		fputs(buf, fp);
	}
	fclose(fp);
}
int val_file(int a, int b, char ch)
{
	switch (ch)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a*b;
	case '/':
		return a / b;
	}
}
void cal_file()
{
	FILE *fp;
	FILE * fq;
	fp = fopen("四则运算.txt", "r");
	if (fp == NULL)
		perror("");
	fq = fopen("四则运算结果.txt", "w");
	if (fq == NULL)
		perror("");
	char buf[128] = "";
	int a = 0;
	int b = 0;
	char ch = 0;
	int val = 0;
	while (1)
	{
		memset(buf, 0, sizeof(buf));
		char *p = NULL;
		p=fgets(buf, sizeof(buf), fp);
		if (p == NULL)
			break;
		sscanf(buf, "%d%c%d=\n", &a, &ch, &b);
		val = val_file(a, b, ch);
		fprintf(fq, "%d%c%d=%d\n", a, ch, b, val);

	}
	fclose(fp);
	fclose(fq);
}

int main(int argc,char *argv[])
{
	 
	creat_file();

	cal_file();


	system("pause");
	return 0;
}


