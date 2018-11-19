#include "deal_file.h"
#include "des.h"
#include <stdio.h>
#include <string.h>
int enc(char *file_1, char *file_2)
{
	FILE *fp = fopen(file_1, "rb");
	if (fp == NULL)
	{
		perror("");
		return -1;
	}
	FILE *fq = fopen(file_2, "wb");
	if (fq == NULL)
	{
		perror("");
		return -1;
	}
	char buf[1024 * 4] = "";
	char tmp[4 * 1024] = "";
	int ret = 0;
	int len = 0;
	while (1)
	{
		ret=fread(buf, 1, sizeof(buf), fp);
		if (ret < 4 * 1024)
		{
			DesEnc(buf, ret, tmp, &len);
			fwrite(tmp, 1, len, fq);
			break;
		}
		DesEnc_raw(buf, ret, tmp, &len);
		fwrite(tmp, 1, len, fq);
	}
	fclose(fp);
	fclose(fq);
	return 0;
}
int des(char *file_1, char *file_2)
{
	FILE *fp = fopen(file_1, "rb");
	if (fp == NULL)
	{
		perror("");
		return -1;
	}
	FILE *fq = fopen(file_2, "wb");
	if (fq == NULL)
	{
		perror("");
		return -1;
	}	
	char buf[1024 * 4] = "";
	char tmp[4 * 1024] = "";
	int ret = 0;
	int len = 0;
	while (1)
	{
		ret = fread(buf, 1, sizeof(buf), fp);
		if (ret < 4 * 1024)
		{
			DesDec(buf, ret, tmp, &len);
			fwrite(tmp, 1, len, fq);
			break;
		}
		DesDec_raw(buf, ret, tmp, &len);
		fwrite(tmp, 1, len, fq);
	}
	fclose(fp);
	fclose(fq);
	return 0;
}