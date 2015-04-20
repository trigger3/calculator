#include <stdio.h>
#include "stack.h"


/*init, push,  pop in from the stack*/
void init_num_stack( stacknum *list_num)
{
	list_num->top=-1;

}

void init_char_stack( stackchar *list_char)
{
	list_char->top=-1;
}

//push the elem int num_Stack
void push_num_stack(stacknum *list_num, int  x)
{
	if(list_num->top >MAXSIZE-1)
		printf("the numstack if full\n");

	else
	{
		list_num->top ++;
		list_num->elem[list_num->top]=x;
	}
}


void push_char_stack(stackchar *list_char, char  x)
{
	if(list_char->top >MAXSIZE-1)
		printf("The charstack is full\n");

	else
	{
		list_char->top ++;
		list_char->elem[list_char->top]=x;
	}
}

//pop the elem in num_stack
int pop_num_stack(stacknum *list_num)
{
	int pop_num;
	if (list_num->top<0)
		printf("the numstack is empty\n");
	else
	{
		pop_num=list_num->elem[list_num->top];
		list_num->top--;
		return pop_num;
	}
}

char pop_char_stack(stackchar *list_char)
{
	char pop_char;
	if (list_char->top<0)
		printf("the charstack is empty\n");
	else
	{
		pop_char=list_char->elem[list_char->top];
		list_char->top--;
		return pop_char;
	}
}



