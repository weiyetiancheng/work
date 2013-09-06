#include<stdio.h>
#include "head.h"


void board(char (*arr)[N])
{
	int i,j;

	arr[0][0]=' ';
	arr[0][N-1]=' ';
	arr[N-1][0]=' ';
	arr[N-1][N-1]=' ';

	for( i=1,j=0;i<N-1;i++)
		arr[i][j]='A'+i-1;
	for( i=0,j=1;j<N-1;j++)
		arr[i][j]='A'+j-1;
	for( i=N-1,j=1;j<N-1;j++)
		arr[i][j]='A'+j-1;
	for( i=1,j=N-1;i<N-1;i++)
		arr[i][j]='A'+i-1;

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if( arr[i][j] == '\0' )
				printf("%2c",'.');
			else if( arr[i][j] == BLACK)
				printf("%2c",'#');
			else if( arr[i][j]== WIGHT )
				printf("%2c",'O');
			else
				printf("%2c",arr[i][j]);
		}
		putchar('\n');
	}
}
