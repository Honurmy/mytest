#include "menu.h"
void help()
{
	printf("*******************************\n");
	printf("1 �����ļ�\n");
	printf("2 �����ļ�\n");
	printf("3 �˳�����\n");
	printf("*******************************\n");
}
void enc_file()
{
	char file_1[128] = "";
	char file_2[128] = "";
	printf("������Ҫ���ܵ��ļ���\n");
	scanf("%s", file_1);
	printf("��������ܺ���ļ���\n");
	scanf("%s", file_2);
	int val=enc(file_1, file_2);
	if (val == 0)
	{
		printf("���ܳɹ�\n");
	}
	else
		printf("����ʧ��\n");
}
void des_file()
{
	char file_1[128] = "";
	char file_2[128] = "";
	printf("������Ҫ���ܵ��ļ���\n");
	scanf("%s", file_1);
	printf("��������ܺ���ļ���\n");
	scanf("%s", file_2);
	int val = des(file_1, file_2);
	if (val == 0)
	{
		printf("���ܳɹ�\n");
	}
	else
		printf("����ʧ��\n");
}
void my_exit()
{
	exit(0);
}