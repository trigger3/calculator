/*jisuan.c*/

#include <stdio.h>
#include "stack.h"

// Achieve jisuan
int jisuan(char a,int num1, int num2)
{
	int res;

	switch(a)
	{
		case '+':
			res=num2+num1; break;
		case '-':
			res=num2-num1; break;
		case '*':
			res=num2*num1; break;
		case '/':
			res=num2/num1; break;
		default:
			printf("error\n"); 
			return 0;
			break;
	}

	return res;
}

/* jisuan the priority*/
int char_priority (char x)
{
	int priority;
	switch(x)
	{
		case '*':
		case '/':
			priority=1; break;
		case '+':
		case '-':
			priority=0;break;
		default:
			break;
	}
		
	return priority;
}

//when popping one char in charstack, two nums will be popped.
void pop_pro(stacknum *list_num, stackchar *list_char)
{
	int pop_num1,pop_num2,res;
	char pop_char1;
	pop_num1=pop_num_stack(list_num);//pop the first elem
	pop_num2=pop_num_stack(list_num);//pop the second elem
	pop_char1=pop_char_stack(list_char);//pop the top operator

	res=jisuan( pop_char1, pop_num1,  pop_num2);//calcu the res and push it into the numstack
	push_num_stack(list_num, res);
}

//bracket_proc()