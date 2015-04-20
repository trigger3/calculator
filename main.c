/***********************************
* Auther:	lihui
* 	@2015.4.17
* email		lh4683@163.com
************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define MAXLENGTH 200

int main() 
{
	int i=0;
	int num;
	int priority_top,priority_elem;
	
	char formul[MAXLENGTH];

	printf("please input the formulor\n");
	scanf("%s",formul);

	init_num_stack(&list_num);//init the stack
	init_char_stack(&list_char);

	while(formul[i]!='\0')//scan the string
	{	
		if (formul[i]>='0'&&formul[i]<='9')// find the num and push it in numstack.
		{
			num=formul[i]-'0';

			while(formul[i+1]>='0'&&formul[i+1]<='9')
			{
				num=num*10+formul[i+1];
				i++;
			}
			i++;
			push_num_stack(&list_num,num);
		}
		else//operator  find the charstack.
		{
		
			if (list_char.top==-1)
			{
				push_char_stack(&list_char,formul[i]);
			}
			
			else if (formul[i]=='(')// elem is '('
				push_char_stack(&list_char,formul[i]);
			else if  (formul[i]==')')//elem is ')'
			{	
				while(list_char.elem[list_char.top]!='(')
				{
					pop_pro(&list_num,&list_char);
				}
				pop_char_stack(&list_char);//remove the'(' from the stack
			}
			else//the elem if '+-*/''
			{
				if((list_char.elem[list_char.top]=='(')||(list_char.top==-1))// if the top is () or nothing in the char stack
					push_char_stack(&list_char, formul[i]);
				else
				{
					priority_top=char_priority(list_char.elem[list_char.top]);
					priority_elem=char_priority(formul[i]);
					while(priority_elem<priority_top)//pop the elem in numstak
					{
						pop_pro(&list_num,&list_char);
						if (list_char.top<0)
							break;
						else
							priority_top=char_priority(list_char.elem[list_char.top]);
					}
					push_char_stack(&list_char, formul[i]);
				}
				
			}
			i++;
		}

	}
	while(list_char.top!=-1)//if some operator in charstack remaining
	{
		pop_pro(&list_num,&list_char);
	}

	printf("the result is:%d\n", list_num.elem[list_num.top]);
	list_num.top =-1;
}