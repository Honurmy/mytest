#include "menu.h"
#include "deal.h"
#include <stdio.h>
#include <string.h>

void help()
{
	printf("******************\n");
	printf("1 写入配置文件\n");
	printf("2 读取配置文件\n");
	printf("3 退出读写程序\n");
	printf("******************\n");
}
void write_file()
{
	char key[128] = "";
	char val[128] = "";
	printf("请输入要写入的key值:\n");
	scanf("%s", key);
	printf("请输入要写入的val值:\n");
	scanf("%s", val);
	int ret = deal_write_file(key, val);
	if (ret == 0)
	{
		printf("写入成功\n");
	}
	else
	{
		printf("写入失败\n");
	}
}
void read_file()
{
	char key[128] = "";
	char val[128] = "";
	printf("请输入要读取的key值:\n");
	scanf("%s", key);
	int ret = deal_read_file(key);
	if (ret == 0)
	{
		printf("读取成功\n");
		//printf("key=[%s] val=[%s]\n", key, val);
	}
	else
	{
		printf("读取失败\n");
	}
}
void my_exit()
{
	exit(0);
}