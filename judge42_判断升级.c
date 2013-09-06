#include<stdio.h>
#include "head.h"

/*求一个点各个方向上的最大分数*/
int judge_b_count(char (*arr)[N], int a, int b)
{
	int i=0,j=0,k,k1=0,k2=0,k3=0,count1=0;
	int str[6]={0,0,30,70,90,150};
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
			{
				if( WIDE(i,j) && (arr[i][j] == '\0') )
					k2++;
				break;
			}
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
			{
				if( WIDE(i,j) && (arr[i][j] == '\0') )
					k3++;
				break;
			}
		}
		if( (k2 > 0) && (k3 > 0) )
			count1 += str[k1-1] + 20;
		else
			count1 += str[k1-1] - 20;
	}

	arr[a][b]='\0';
	return count1;
}

int judge_w_count(char (*arr)[N], int a, int b)
{
	int i=0,j=0,k,k1=0,k2=0,k3=0,count1=0;
	int str[6]={0,0,30,70,90,150};
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
			{
				if( WIDE(i,j) && (arr[i][j] == '\0') )
					k2++;
				break;
			}
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
			{
				if( WIDE(i,j) && (arr[i][j] == '\0') )
					k3++;
				break;
			}
		}
		if( (k2 > 0) && (k3 > 0) )
			count1 += str[k1-1] + 20;
		else
			count1 += str[k1-1] - 20;
	}

	arr[a][b]='\0';
	return count1;
}
