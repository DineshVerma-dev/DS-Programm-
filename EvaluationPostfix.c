#include <stdio.h>
#include<conio.h>
#include <string.h>

int operand(char n) {
  if (n >= '0' && n <= '9')
    return 1;
  else
    return 0;
}
int main() {
  int a, b, c, i, s[20];
  char postfix[20];
  int top = -1;
  printf("Enter Postfix:\n");
  gets(postfix);
  for (i = 0; postfix[i] != '\0'; i++) {
    if (operand(postfix[i]) == 1) {
      top++;
      s[top] = (int)(postfix[i] - '0');
    } else {
      b = s[top];
      top--;
      a = s[top];
      top--;
      switch (postfix[i]) {
      case '*':
        c = a * b;
        break;
      case '-':
        c = a - b;
        break;

      case '+':
        c = a + b;
        break;
      case '/':
        c = a / b;
        break;
      }
      top++;
      s[top] = c;
    }
  }
  printf("Answer Of Evaluation Is: %d", s[top]);
  return 0;
}

Algorithm for Evaluating Postfix Expression
Define Variables:

Initialize integer variables a, b, c, i, and an array s of size 20.
Initialize top to -1 to represent the stack pointer.
Declare a character array postfix to hold the input expression.
Input Postfix Expression:

Prompt the user to enter a postfix expression.
Use gets(postfix) to read the input string.
Iterate Over Each Character:

For each character in postfix, do the following:
If the character is an operand (digit):
Convert the character to an integer (by subtracting '0') and push it onto the stack:
Increment top and assign s[top] = (int)(postfix[i] - '0').
If the character is an operator:
Pop the top two elements from the stack:
Assign b = s[top] and decrement top.
Assign a = s[top] and decrement top.
Evaluate the operation based on the operator:
If postfix[i] is '*', set c = a * b.
If postfix[i] is '-', set c = a - b.
If postfix[i] is '+', set c = a + b.
If postfix[i] is '/', set c = a / b.
Push the result c back onto the stack:
Increment top and assign s[top] = c.
Output the Result:

After processing all characters, the final result will be at the top of the stack:
Print the result using printf("Answer Of Evaluation Is: %d", s[top]);.
End Program:

Return 0 to indicate successful execution.