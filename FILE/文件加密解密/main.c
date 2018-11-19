#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	


int main()
{
	int cmd;
	while (1)
	{
		system("cls");
		help();
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1:
			enc_file();
			break;
		case 2:
			des_file();
			break;
		case 3:
			my_exit();
			break;
		default:
			printf("输入有误，请重新输入！！\n");
		}
		_sleep(3000);
	}

	system("pause");
	return 0;
}


