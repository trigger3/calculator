/* main.c*/
#ifndef STACK_H_
#define STACK_H_

#define MAXSIZE 100
typedef struct numstack
{
	int elem[MAXSIZE];
	int top;
}stacknum;
stacknum list_num;

typedef struct charstack
{
	char elem[MAXSIZE];
	int top;
}stackchar;
stackchar list_char;



extern int jisuan(char a,int num1, int num2);

extern void init_num_stack( stacknum *list_num);
extern void init_char_stack( stackchar *list_char);
extern void push_num_stack(stacknum *list_num, int  x);
extern void push_char_stack(stackchar *list_char, char  x);
extern int pop_num_stack(stacknum *list_num);
extern char pop_char_stack(stackchar *list_char);
extern int char_priority (char x);
void pop_pro(stacknum *list_num, stackchar *list_char);

#endif




