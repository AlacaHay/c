#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 100
float st[MAX];
int top=-1;
void push(float st[],float);
float pop(float st[]);
float postfixDegeri(char postfix[]);

int main(){
    float val;
    char exp[MAX];
    fgets(exp,sizeof(exp),stdin);
    exp[strcspn(exp,"\n")]='\0';
    val=postfixDegeri(exp);
    printf("Ifadenin degeri: %.2f",val);

    return 0;
}

void push(float st[],float val){
    if(top==MAX-1) {
        printf("Stack Overflow\n");
        
    }
    else 
        st[++top]=val;
}

float pop(float st[]){
    float val=-5;
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    else {
        val=st[top];
        top--;
        return val;
    }

    
}

float postfixDegeri(char exp[]){
    int i=0;
    float operand1,operand2,value,dondur;
    while(exp[i]!='\0'){
        if(isdigit(exp[i])){
            push(st,(float)(exp[i]-'0'));
            
        }
        else{
            operand2=pop(st);//A        -islemi =B-A
            operand1=pop(st);//B
            switch(exp[i]){
                case '+':
                    value=operand1+operand2;
                    break;
                case '-':
                    value=operand1-operand2;
                    break;
                case '/':
                    value=operand1/operand2;
                    break;
                case '*':
                    value=operand1*operand2;
                    break;
                case '%':
                    value=(int)operand1 %(int)operand2;
                    break;
            }
            push(st,(float)value);

        }
        i++;
        
    }

    return pop(st);

}