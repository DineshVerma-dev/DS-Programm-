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