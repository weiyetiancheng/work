#include<stdio.h>
#include "head.h"

/*求一个点各个方向上的最大分数*/
int judge_b_count(char (*arr)[N], int a, int b)
{
	int i=0,j=0,k,k1=0,count1=0,count2=0;
	int str[5]={0,50,250,1200,10000};
	struct direction p[4]={{-1,1},{0,1},{1,1},{1,0}};

	arr[a][b]=BLACK;

	for(k=0;k<4;k++)
	{
		k1=0;
		i=a;
		j=b;
		while( 1 )
		{
			if( WIDE(i,j) && (arr[i][j] == BLACK) )
			{
				k1++;
				i += p[k].x;
				j += p[k].y;
			}
			else
				break;
		}

		i=a;
		j=b;
		while( 1 )
		{
			if( WIDE(i,j) && (arr[i][j] == BLACK) )
			{
				k1++;
				i -= p[k].x;
				j -= p[k].y;
			}
			else
				break;
		}
		count1 = str[k1-2];
		if( count1 > count2 )
			count2=count1;
	}

	arr[a][b]='\0';
	return count2;
}

int judge_w_count(char (*arr)[N], int a, int b)
{
	int i=0,j=0,k,k1=0,count1=0,count2=0;
	int str[5]={0,50,250,1200,10000};
	struct direction p[4]={{-1,1},{0,1},{1,1},{1,0}};
	arr[a][b]=WIGHT;
	for(k=0;k<4;k++)
	{
		k1=0;
		i=a;
		j=b;
		while( 1 )
		{
			if( WIDE(i,j) && (arr[i][j] == WIGHT) )
			{
				k1++;
				i += p[k].x;
				j += p[k].y;
			}
			else
				break;
		}

		i=a;
		j=b;
		while( 1 )
		{
			if( WIDE(i,j) && (arr[i][j] == WIGHT) )
			{
				k1++;
				i -= p[k].x;
				j -= p[k].y;
			}
			else
				break;
		}
		count1 = str[k1-2];
		if( count1 > count2 )
			count2=count1;
	}

	arr[a][b]='\0';
	return count2;
}
