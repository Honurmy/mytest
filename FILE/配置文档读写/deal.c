#include "deal.h"
#include <stdio.h>
#include <string.h>
#define PATHNAME "cfg.ini"
#include <sys/types.h>
#include <sys/stat.h>
void filter(char *str)
{
	char *start = str;
	char *end = str + strlen(str) - 1;

	while ((*start == ' ' || *start == '\r' || *start == '\t') && *start != 0)
		start++;

	while ((*end == ' ' || *end == '\r' || *end == '\t') && end > start)
		end--;
	int n = end - start + 1;
	//printf("%d\n",n);
	strncpy(str, start, n);
	str[n] = 0;
}

int deal_write_file(char *key, char *val)
{
	
	struct stat s;
	int ret=stat(PATHNAME, &s);
	//char buf[128] = "";
	if (ret != 0)
	{
		FILE *fp = fopen(PATHNAME, "w");
		if (fp == NULL)
		{
			perror("");
			return -1;
		}
		//memset(buf, 0, sizeof(buf));
		//sprintf(buf, "%s = %s\n", key, val);
		fprintf(fp, "%s = %s\n", key, val);
		//fputs(buf, fp);
		fclose(fp);
	}
	else
	{
		int flag=0;
		char tmp_buf[256] = "";
		char tmp_key[128] = "";
		char tmp[256] = "";
		char *str = (char*)malloc(s.st_size + 128);
		memset(str, 0, s.st_size + 128);
		FILE *fp = fopen(PATHNAME, "r");
		if (fp == NULL)
		{
			perror("");
			return -1;
		}
		while (1)
		{
			memset(tmp_buf, 0, sizeof(tmp_buf));
			char *p=fgets(tmp_buf, sizeof(tmp_buf), fp);
			if (p == NULL)
				break;
			sscanf(tmp_buf, "%[^=]", tmp_key);
			filter(tmp_key);
			if (strcmp(key, tmp_key) == 0)
			{
				flag = 1;
				sprintf(tmp, "%s = %s\n", key,val);
				strcat(str, tmp);
			}
			else
			{
				strcat(str, tmp_buf);
			}
		}
		if (flag == 0)
		{
			memset(tmp_buf, 0, sizeof(tmp_buf));
			sprintf(tmp_buf, "%s = %s\n", key, val);
			strcat(str, tmp_buf);
		}
		fclose(fp);
		fp = fopen(PATHNAME, "w");
		if (fp == NULL)
		{
			perror("");
			return -1;
		}
		fputs(str, fp);
		fclose(fp);
		return 0;
	}
	
}
int deal_read_file(char *key)
{
	char tmp_buf[256] = "";
	char tmp_key[128] = "";
	FILE *fp = fopen(PATHNAME, "r");
	if (fp == NULL)
	{
		perror("");
		return -1;
	}
	while (1)
	{
		char *p = fgets(tmp_buf, sizeof(tmp_buf), fp);
		
		if (p == NULL)
			return -1;
		sscanf(tmp_buf, "%[^=]", tmp_key);
		filter(tmp_key);
		if (strcmp(tmp_key, key) == 0)
		{
			printf("%s\n", tmp_buf);
			fclose(fp);
			return 0;
		}

	}
}