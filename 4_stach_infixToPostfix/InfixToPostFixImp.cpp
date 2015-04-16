//Implementation File

#include <iostream>
#include <string>
#include "myStack.h"
#include "infixToPostfix.h"

using namespace std;

void infixToPostfix::convertToPostfix()
{
	stackType<char>  stack(50);
	char stackOpr;

	stack.initializeStack();
	pfx = "";

	int len = ifx.length();

	for (int i = 0; i < len; i++)
		if (ifx[i] >= 'A' && ifx[i] <= 'Z')
			pfx = pfx + ifx[i];
		else
		{
			switch (ifx[i])
			{
			case '(':
                stack.push(ifx[i]);
				break;

			case ')':
                stackOpr = stack.top();
				stack.pop();

                while (stackOpr != '(')
                {
                    pfx = pfx + stackOpr;

                    if (!stack.isEmptyStack())
                    {
                        stackOpr = stack.top();
                        stack.pop();
                    }
			        else
                        break;
                }
                break;

			case ';':
			case ' ':
                break;

			default:
                if (stack.isEmptyStack())
                    stack.push(ifx[i]);
                else
                {
                    stackOpr = stack.top();
                    stack.pop();

                    while (precedence(stackOpr,ifx[i]))
                    {
                        pfx = pfx + stackOpr;
                        if (!stack.isEmptyStack())
                        {
                            stackOpr = stack.top();
                            stack.pop();
                        }
                        else
                            break;
                    }

                    if (!precedence(stackOpr,ifx[i]))
                        stack.push(stackOpr);

                    stack.push(ifx[i]);
                }

			}//end switch
		}//end else

	while (!stack.isEmptyStack())
	{
		pfx += stack.top();
		stack.pop();
	}

}//end convertToPostfix


bool infixToPostfix::precedence(char opr1, char opr2)
{
	int prec1, prec2;

	if (opr1 == '*' || opr1 =='/')
		prec1 = 2;
	else if(opr1 == '+' || opr1 == '-')
        prec1 = 1;
    else if(opr1 ='(')
        prec1 = 0;

    if (opr2 == '*' || opr2 == '/')
        prec2 = 2;
	else if(opr2 =='+' || opr2 == '-')
        prec2 = 1;

    return(prec1 >= prec2);
}//end precedence

void infixToPostfix::getInfix(string data)
{
    ifx = data;
    convertToPostfix();
}

void infixToPostfix::showInfix()
{
	cout << "Infix: " << ifx << endl;
}


void infixToPostfix::showPostfix()
{
	cout << "Postfix: " << pfx << endl;
}

infixToPostfix::infixToPostfix(string infx)
{
	ifx = infx;
	convertToPostfix();
}



