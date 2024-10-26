#include "main.h"

int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
	int start=0;
	int len=strlen(Infix_exp);
	int end=len-1;
	while(start<=end)
	{
	    char temp=Infix_exp[start];
	    Infix_exp[start]=Infix_exp[end];
	    Infix_exp[end]=temp;
	    start++;
	    end--;
	}
	char ch;
	int j=0;
	for(int i=0;i<strlen(Infix_exp);i++)
	{
	    ch=Infix_exp[i];
	    if(ch>='0' && ch<='9')
	    {
	        Prefix_exp[j++]=ch;
	    }
	    else
	    {
	        if(stk->top==-1)
	        {
	            push(stk,ch);
	        }
	        else
	        {
	            if(ch==')')
	            {
	                push(stk,ch);
	            }
	            else if(ch=='(')
	            {
	                while(stk->top!=-1 && stk->stack[stk->top]!=')')
	                {
	                    Prefix_exp[j++]=peek(stk);
	                    pop(stk);
	                    
	                }
	                pop(stk);
	            }
	            else
	            {
	                if(priority(peek(stk))>priority(ch))
	                {
	                     while(priority(peek(stk))>priority(ch))
	                     {
	                         Prefix_exp[j++]=peek(stk);
	                         pop(stk);
	                    //push(stk,ch);
	                     }
	                     push(stk,ch);
	                }
	                else
	                {
	                 push(stk,ch);
	                }
	            }
	        }
	    }
	}
	while(stk->stack[stk->top]!=-1)
	{
	    Prefix_exp[j++]=peek(stk);
	    pop(stk);
	}
	Prefix_exp[j]='\0';
	int k=0;
	int l=strlen(Prefix_exp)-1;
	while(k<=l)
	{
	    char temp=Prefix_exp[k];
	    Prefix_exp[k]=Prefix_exp[l];
	    Prefix_exp[l]=temp;
	    k++;
	    l--;
	}
	
	return 0;
}
