#include<stdio.h>
#include "head.h"

/*检查出分数最高的那个点*/
void check_all( char (*arr)[N], xb *p)
{
	int i,j,k=0,countb=0,countw=0,count1=0,count2=0;
	for(i=1;i<=(N-2);i++)
	{
		for(j=1;j<=(N-2);j++)
		{
			if( arr[i][j] == '\0' )
			{
				k++;
				countb=judge_b_count(arr,i,j);
				countw=judge_w_count(arr,i,j);
				count1=countb>countw?countb:countw;
				if( k >= (N-2)*(N-2) )
				{
					p->i=N/2-1+'A';
					p->j=N/2-1+'A';
					break;
				}
				if( count2 < count1 )
				{
					count2=count1;
					p->i=i-1+'A';
					p->j=j-1+'A';
				}
			}
		}
	}
}
