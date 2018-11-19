#include "menu.h"
void help()
{
	printf("*******************************\n");
	printf("1 加密文件\n");
	printf("2 解密文件\n");
	printf("3 退出程序\n");
	printf("*******************************\n");
}
void enc_file()
{
	char file_1[128] = "";
	char file_2[128] = "";
	printf("请输入要加密的文件名\n");
	scanf("%s", file_1);
	printf("请输入加密后的文件名\n");
	scanf("%s", file_2);
	int val=enc(file_1, file_2);
	if (val == 0)
	{
		printf("加密成功\n");
	}
	else
		printf("加密失败\n");
}
void des_file()
{
	char file_1[128] = "";
	char file_2[128] = "";
	printf("请输入要解密的文件名\n");
	scanf("%s", file_1);
	printf("请输入解密后的文件名\n");
	scanf("%s", file_2);
	int val = des(file_1, file_2);
	if (val == 0)
	{
		printf("解密成功\n");
	}
	else
		printf("解密失败\n");
}
void my_exit()
{
	exit(0);
}