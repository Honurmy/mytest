#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

typedef struct _dict
{
	char *key;
	char *content;
}DICT;
int count_line()
{
	FILE *fp = fopen("dict.txt", "r");
	if (fp == NULL)
		perror("");
	int i = 0;
	char buf[1024] = "";
	while (1)
	{
		char *p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
			break;
		p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
			break;
		i++;
	}
	fclose(fp);
	return i;
}
//#a\n \t\r
void filter(char *buf)
{
	int n = strlen(buf)-1;
	while(buf[n] == ' ' || buf[n] == '\t' || buf[n] == '\r' || buf[n] == '\n')
		n--;
	buf[n + 1] = 0;
}
void file_init(DICT **p,int len)
{
	DICT *tmp = NULL;
	tmp = (DICT*)malloc(sizeof(DICT)*len);
	FILE *fp = fopen("dict.txt", "r");
	if (fp == NULL)
		perror("");
	
	char buf[1024] = "";
	int i = 0;
	while (1)
	{
		char *p=fgets(buf, sizeof(buf), fp);
		if (p == NULL)
			break;
		filter(buf);
		tmp[i].key = (char*)malloc(strlen(buf + 1) + 1);
		strcpy(tmp[i].key, buf + 1);
		memset(buf, 0, sizeof(buf));

		p=fgets(buf, sizeof(buf), fp);
		if (p == NULL)
			break;	
		tmp[i].content = (char*)malloc(strlen(buf + 6) + 1);
		strcpy(tmp[i].content, buf + 6);
		memset(buf, 0, sizeof(buf));
		i++;

	}

	*p = tmp;
	fclose(fp);
	
}
int find_key(char *cmd, DICT *p, int len, char *content)
{
	for (int i = 0; i < len; i++)
	{
		if (strcmp(cmd, p[i].key) == 0)
		{
			strcpy(content, p[i].content);
			return 1;
		}
	}
	return 0;
}
int main()
{
	
	DICT *p = NULL;
	int len = count_line();
	//printf("%d\n", len);
	file_init(&p,len);
	char cmd[256] = "";
	char content[256] = "";
	while (1)
	{
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strlen(cmd)-1] = 0;
		int ret = find_key(cmd, p, len, content);
		if (ret == 0)
		{
			printf("没有找到此单词的翻译\n");
		}
		else
			printf("单词翻译:%s\n", content);
	}

	system("pause");
	return 0;
}


