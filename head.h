#ifndef __HEAD_H__
#define __ HEAD_H__
#ifdef __cplusplus
extern "C" {
#endif

#include<time.h>
#include<stdlib.h>

struct step
{
	char row;
	char col;
};

typedef struct step STEP;

struct xiabiao
{
	char i;
	char j;
};

typedef struct xiabiao xb;

struct direction
{
	int x;
	int y;
};

#define N 17
#define BLACK '1'
#define WIGHT '2'
#define WIDE(a,b) ( a>=1&&a<=15&&b>=1&&b<=15 )

void board(char (*arr)[N]);
void cmp_chose(char (*arr)[N], STEP *P);
int judge_w(char (*arr)[N], int a,int b);
int judge_b(char (*arr)[N], int a, int b);
void check_all( char (*arr)[N], xb *p);
int judge_b_count(char (*arr)[N], int a, int b);
int judge_w_count(char (*arr)[N], int a, int b);
void man_chose(char (*arr)[N], STEP *p);

#ifdef __cplusplus
}
#endif
#endif /* __HEAD_H__ */
