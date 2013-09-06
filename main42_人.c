#include<stdio.h>
#include "head.h"

int main(void)
{
	int i,j;
	char ch1,ch2;
	char *pch1=&ch1;
	char *pch2=&ch2;
	char *p1="white.pipe";
	char *q2="black.pipe";
	char arr[N][N]={0};
	STEP *p=NULL;


	//arr[N/2][N/2]=BLACK;
	//srandom( time(0) );
	p=(STEP *)malloc(sizeof(STEP));
	if( p == NULL )
	{
		return -1;
	}

	while(1)
	{
		man_chose(arr,p);
		arr[p->row+1-'A'][p->col+1-'A']=WIGHT;
		board(arr);
		printf("白方输入：%c %c\n",p->row,p->col);
		write_pipe(p1,p->row,p->col);
		if( judge_w(arr,p->row+1-'A',p->col+1-'A') )
		{
			//printf("白方输入：%d %d 白方胜利\n",p->row+1-'A',p->col+1-'A');
			printf("白方输入：%c %c 白方胜利\n",p->row,p->col);
			return 1;
		}

		read_pipe(q2,pch1,pch2);
		arr[*pch1-'A'+1][*pch2-'A'+1]=BLACK;
		board(arr);
		printf("黑方输入：%c %c\n",*pch1,*pch2);
		if( judge_b(arr,*pch1-'A'+1,*pch2-'A'+1) )
		{
			//printf("黑方输入：%d %d 白方胜利\n",*pch1+1-'A',*pch2+1-'A');
			printf("黑方输入：%c %c 黑方胜利\n",*pch1,*pch2);
			return 1;
		}

	}
	return 0;
}
