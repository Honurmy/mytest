#include "menu.h"
#include "deal.h"
#include <stdio.h>
#include <string.h>

void help()
{
	printf("******************\n");
	printf("1 д�������ļ�\n");
	printf("2 ��ȡ�����ļ�\n");
	printf("3 �˳���д����\n");
	printf("******************\n");
}
void write_file()
{
	char key[128] = "";
	char val[128] = "";
	printf("������Ҫд���keyֵ:\n");
	scanf("%s", key);
	printf("������Ҫд���valֵ:\n");
	scanf("%s", val);
	int ret = deal_write_file(key, val);
	if (ret == 0)
	{
		printf("д��ɹ�\n");
	}
	else
	{
		printf("д��ʧ��\n");
	}
}
void read_file()
{
	char key[128] = "";
	char val[128] = "";
	printf("������Ҫ��ȡ��keyֵ:\n");
	scanf("%s", key);
	int ret = deal_read_file(key);
	if (ret == 0)
	{
		printf("��ȡ�ɹ�\n");
		//printf("key=[%s] val=[%s]\n", key, val);
	}
	else
	{
		printf("��ȡʧ��\n");
	}
}
void my_exit()
{
	exit(0);
}