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
	xb *p=NULL;

	srandom( time(0) );
	p=(xb *)malloc(sizeof(xb));
	if( p == NULL )
	{
		return -1;
	}
	p->i=0;
	p->j=0;

	/*一个读到一个坐标，一个输出一个坐标*/
	while(1)
	{
		read_pipe(p1,pch1,pch2);
		arr[*pch1+1-'A'][*pch2+1-'A']=BLACK;
		board(arr);
		printf("黑方输入：%c %c\n",*pch1,*pch2);
		if( judge_b(arr,*pch1+1-'A',*pch2+1-'A') )
		{
			printf("黑方输入：%c %c 黑方胜利\n",*pch1,*pch2);
			return 1;
		}
		
		check_all(arr,p);
		arr[p->i-'A'+1][p->j-'A'+1]=WIGHT;
		write_pipe(q2,p->i,p->j);
		board(arr);
		printf("白方输入：%c %c\n",p->i,p->j);
		if( judge_w(arr,p->i+1-'A',p->j+1-'A') )
		{
			printf("白方输入：%c %c 白方胜利\n",p->i,p->j);
			return 1;
		}
	}
	return 0;
}
