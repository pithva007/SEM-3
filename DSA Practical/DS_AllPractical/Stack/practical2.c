#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    if(top<MAX-1){
        top++;
        stack[top] = c;
    }
}

char pop(){
    if (top>=0) return stack[top--];
    return '\0';
}

char peek(){
    if (top >= 0) return stack[top];
    return '\0';
}

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

int isRightAssociative(char c){
    return c=='^';
}

int main(){
    char infix[MAX], postfix[MAX] = "";
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    int step = 1;
    printf("\nstep\tsymbol\tstack\tpostfix\n");
    printf("\n");

    for (int i = 0; i<strlen(infix); i++) {
        char c = infix[i];

        if(isalnum(c)){
            int len = strlen(postfix);
            postfix[len] = c;
            postfix[len+1] = '\0';
        } 
        else if (c == '('){
            push(c);
        } 
        else if(c == ')'){
            while (top != -1 && peek() != '(') {
                int len = strlen(postfix);
                postfix[len] = pop();
                postfix[len+1] = '\0';
            }
            if (top!=-1 && peek()=='(') pop();
        } 
        else{  
            while(top!=-1 && peek()!='('&&(precedence(peek())>precedence(c)||(precedence(peek())==precedence(c)&& !isRightAssociative(c)))) {
                int len = strlen(postfix);
                postfix[len] = pop();
                postfix[len+1] = '\0';
            }
            push(c);
        }

        printf("%d\t%c\t", step++, c);
        for(int j = 0; j<=top; j++){
            printf("%c", stack[j]);
        } 
        printf("\t%s\n", postfix);
    }

    while(top!=-1){
        int len = strlen(postfix);
        postfix[len] = pop();
        postfix[len+1] = '\0';

        printf("%d\t \t", step++);
        for (int j = 0; j<=top; j++) {
            printf("%c", stack[j]);
        }
        printf("\t\t%s\n", postfix);
    }

    printf("\nPostfix Expression: %s\n", postfix);
    return 0;
}
