#include <stdio.h>
#include <ctype.h>

int stack[100], top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) push(exp[i] - '0');
        else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[] = "231*+9-";
    printf("Result: %d", evaluatePostfix(exp));
}
