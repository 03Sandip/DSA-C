#include <stdio.h>
#include <string.h> 
#include <process.h>
#define STACK_SIZE 20

void push(char item, int *top, char s[])
{
    if (*top != STACK_SIZE - 1)
    {
        *top = *top + 1;
        s[*top] = item;
    }
    else
    {
        printf("\nOverflow of stack.");
        getch();
    }
}

char pop(int *top, char s[])
{
    char item;
    if (*top != -1)
    {
        item = s[*top];
        *top = *top - 1;
        return item;
    }
    else
    {
        printf("\nStack is empty.");
        return 0;
    }
}

int G(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

int F(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}

int R(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '$':
        return -1;
    default:
        return 1;
    }
}

int infix_postfix(char infix[], char postfix[])
{
    int i, j, top, rank;
    char symbol, temp, s[20];
    top = -1;
    push('#', &top, s);
    rank = 0;
    j = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        while (F(s[top]) > G(symbol))
        {
            temp = pop(&top, s);
            rank += R(temp);
            if (rank < 1) // Invalid expression
                return -1;
            postfix[j] = temp;
            j++;
        }
        if (F(s[top]) < G(symbol))
            push(symbol, &top, s);
        else
            pop(&top, s);
    }
    while (s[top] != '#') 
    {                     
        temp = pop(&top, s); 
        rank += R(temp);
        if (rank < 1)
            return -1; 
        postfix[j] = temp;
        j++;
    }
    postfix[j] = '\0';
    return rank;
}

int main()
{
    char infix[20], postfix[20];
    int rank;
    //clrscr();
    printf("\nEnter the infix expression: ");
    gets(infix);
    rank = infix_postfix(infix, postfix);
    if (rank != 1)
        printf("\nThe input expression is invalid.");
    else
        printf("\nThe postfix expression is %s", postfix);
    //getch();
    return 0 ;
}
