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