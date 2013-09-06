#include<stdio.h>
#include "head.h"


int judge_b(char (*arr)[N], int a, int b)
{
	int i=0,j=0,k,k1=0,k2=0,ma=1;
	struct direction p[4]={{-1,1},{0,1},{1,1},{1,0}};

	for(k=0;k<4;k++)
	{
		k1=0;
		k2=0;
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
				k2++;
				i -= p[k].x;
				j -= p[k].y;
			}
			else
				break;
		}
		if( (k1+k2) == 6 )/*两次查看重复了一次*/
			return 1;
	}
	return 0;
}

int judge_w(char (*arr)[N], int a, int b)
{
	int i=0,j=0,k,k1=0,k2=0,ma=1;
	struct direction p[4]={{-1,1},{0,1},{1,1},{1,0}};

	for(k=0;k<4;k++)
	{
		k1=0;
		k2=0;
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
				k2++;
				i -= p[k].x;
				j -= p[k].y;
			}
			else
				break;
		}
		if( (k1+k2) == 6 )/*两次查看重复了一次*/
			return 1;
	}
	return 0;
}
