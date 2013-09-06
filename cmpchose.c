#include<stdio.h>
#include "head.h"

void cmp_chose(char (*arr)[N], STEP *p)
{
	int m,n;
	do
	{
		m=1+random()%(N-2);
		n=1+random()%(N-2);

	}while( arr[m][n] );
	p->row=m+('A'-1);
	p->col=n+('A'-1);
}

void man_chose(char (*arr)[N], STEP *p)
{
	char ch1,ch2,ch;
	printf("请输入坐标(AA):\n");
	do
	{
	ch1=getchar();
	ch2=getchar();
	while( (ch=getchar()) != '\n' );
	}while( (WIDE(ch1-'A'+1,ch2-'A'+1)==0) && (arr[ch1-'A'+1][ch2-'A'+1] !='\0') );
	p->row=ch1;
	p->col=ch2;
}

/*管道写入  name 管道文件名*/
void  write_pipe(char *name, char ch1, char ch2)
{
	FILE *f1=NULL;
	int ma=ch1-'A'+1;
	
	f1=fopen(name,"a");
	if( f1 == NULL )
	{
		printf(" file 1 open failed \n");
		exit(0);
	}
	fputc(ch2,f1);
	fprintf(f1,"%d\n",ma);
	fclose(f1);
	f1=NULL;
}

/*管道读出*/
void read_pipe(char *name,char *ch1, char *ch2)
{
	FILE *f2=NULL;

	f2=fopen(name,"r");
	if( f2 == NULL )
	{
		printf("file 2 open failed \n");
		exit(0);
	}
	*ch2=fgetc(f2);
	ch1=fgets(ch1,3,f2);
	*ch1=atoi(ch1)+'A'-1;
	fclose(f2);
	f2=NULL;
}
