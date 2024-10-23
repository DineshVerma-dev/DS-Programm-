#include <stdio.h>
#include<conio.h>
#include <string.h>

int isOperand(char n) {
  return (n >= '0' && n <= '9');
}
int priority(char n) {
  if (n == '*' || n == '/') {
    return 2;
  } else if (n == '+' || n == '-') {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  int j = -1, i, top = -1;
  char infix[20], postfix[20], stack[20];
  printf("Enter Infix:\n");
  gets(infix);
  for (i = 0; infix[i] != '\0'; i++) {
    if (infix[i] == '(') {
      top++;
      stack[top] = infix[i];
    } else if (isOperand(infix[i])) {
      j++;
      postfix[j] = infix[i];
    } else if (top == -1) {
      top++;
      stack[top] = infix[i];
    } else if (infix[i] == ')') {
      while (stack[top] != '(') {
        j++;
        postfix[j] = stack[top];
        top--;
      }
      top--;
    } else if (priority(infix[i]) > priority(stack[top])) {
      top++;
      stack[top] = infix[i];
    } else {
      while (priority(stack[top]) >= priority(infix[i]) && top != -1 && stack[top] != '(') {
        j++;
        postfix[j] = stack[top];
        top--;
      }
      top++;
      stack[top] = infix[i];
    }
  }
  while (top != -1) {
    j++;
    postfix[j] = stack[top];
    top--;
  }
  postfix[j + 1] = '\0';
  puts(postfix);
  return 0;
}

Algorithm for Infix to Postfix Conversion
Initialize Variables:

Create infix array to store the input expression.
Create postfix array to store the converted expression.
Create stack array to hold operators.
Set top = -1 (to track the top of the stack) and j = -1 (to track the position in postfix).
Read Infix Expression:

Input the infix expression from the user.
Iterate Through Each Character:

For each character c in infix:
If c is '(':
Push c onto the stack.
If c is an operand (number):
Append c to postfix.
If c is ')':
Pop from the stack to postfix until '(' is found.
If c is an operator (+, -, *, /):
While the stack is not empty and the priority of the operator at the top of the stack is greater than or equal to the priority of c:
Pop the top of the stack to postfix.
Push c onto the stack.
Pop Remaining Operators:

After processing all characters, pop any remaining operators from the stack to postfix.
Terminate Postfix String:

Set the last character of postfix to '\0' to terminate the string.
Output Result:

Print the converted postfix expression.