#include "main.h"
int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
   int i, operand1, operand2, result;
   int len = strlen(Prefix_exp);
   char ch;
   for(int i=len-1;i>=0;i--)
   {
       ch=Prefix_exp[i];
       if(ch>='0' && ch<='9')
       {
           int num=ch-'0';
           push(stk,num);
       }
       else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
       {
           operand1 = peek(stk);
           pop(stk); 
           operand2 = peek(stk);
           pop(stk); 
           switch (ch) 
           {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2; 
                    break;
           }
           push(stk, result);
       }
   }
   result = peek(stk);
   pop(stk); 
   return result;

}

