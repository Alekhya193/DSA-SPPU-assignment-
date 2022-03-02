*
Name - Usha sree alekhya siddi

Roll no - 25062

Div - A

Batch - C
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct conversion_Stack{
    char data;
    struct conversion_Stack *next;    
};

struct evaluation_Stack{
    int data;
    struct evaluation_Stack *next;    
};

struct conversion_Stack *Top = NULL;
struct evaluation_Stack *top = NULL;

void Push(char data){
        struct conversion_Stack *ptr = (struct conversion_Stack*)malloc(sizeof(struct conversion_Stack));
        ptr->data = data;
        ptr->next = Top;
        Top = ptr;
}

void push(int data){
        struct evaluation_Stack *ptr = (struct evaluation_Stack*)malloc(sizeof(struct evaluation_Stack));
        ptr->data = data;
        ptr->next = NULL;
        if(top == NULL){
            top = ptr;
        }else{
            ptr->next = top;
            top = ptr;
        }
}

void Pop(){
    struct conversion_Stack *temp = Top;
    Top = Top->next;
    free(temp);
    temp = NULL;
}

void pop(){
    struct evaluation_Stack *temp = top;
    top = top->next;
    free(temp);
    temp = NULL;
}

int precedence(char opr){
    if(opr == '^'){
        return 3;
    }else if(opr == '*' || opr == '/' || opr == '%'){
        return 2;
    }else if(opr == '+' || opr == '-'){
        return 1;
    }else{
        return -1;
    }
}

bool is_Operator(char opr){
    if(opr == '+' || opr == '-' || opr == '*' || opr == '/' || opr == '%' || opr == '^'){
		return true;
	}else{
		return false;
	}
}

int char_To_Int(char operand){
    switch(operand){
        case '0':
            return 0;
            break;
            
        case '1':
            return 1;
            break;

        case '2':
            return 2;
            break;

        case '3':
            return 3;
            break;

        case '4':
            return 4;
            break;

        case '5':
            return 5;
            break;

        case '6':
            return 6;
            break;

        case '7':
            return 7;
            break;

        case '8':
            return 8;
            break;

        case '9':
            return 9;
            break;
    }
    return operand;
}

string reverse(string Infix){
    string rev_Infix;
    for(int i = Infix.length(); i > 0; i--){
        rev_Infix = rev_Infix + (Infix[i-1]);
    }
    return rev_Infix;
}

void arithmetic_Operation(char choice, int a, int b){
    int evaluation;
    switch(choice){
                case '+':
                    evaluation = a + b;
                    push(evaluation);
                    break;

                case '-':
                    evaluation = a - b;
                    push(evaluation);
                    break;

                case '*':
                    evaluation = a * b;
                    push(evaluation);
                    break;

                case '/':
                    evaluation = a / b;
                    push(evaluation);
                    break;

                case '%':
                    evaluation = a % b;
                    push(evaluation);
                    break;

                case '^':
                    evaluation = pow(a, b);
                    push(evaluation);
                    break;
            }
}

string Infix_To_Postfix(string Infix){
    string Postfix;
    for(int i = 0; i < Infix.length(); i++){
        if((Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z') || (Infix[i] >= '0' && Infix[i] <= '9')){
            Postfix += Infix[i];
        }else if(Infix[i] == '('){
                Push(Infix[i]);
        }else if(Infix[i] == ')'){
            while((Top->data != '(') && (Top != NULL)){
				Postfix += Top->data;
				Pop();
			}
            if(Top->data =='('){
		    	Pop();
			}
        }else if(is_Operator(Infix[i])){
            if(Top == NULL){
				Push(Infix[i]);
			}else{
				if(precedence(Infix[i]) > precedence(Top->data)){
					Push(Infix[i]);
				}else if((precedence(Infix[i]) == precedence(Top->data)) && (Infix[i] == '^')){
					Push(Infix[i]);
				}else{
					while((Top != NULL) && (precedence(Infix[i]) <= precedence(Top->data))){
						Postfix += Top->data;
						Pop();
					}
					Push(Infix[i]);
				}
			}
        }
    }
    while(Top != NULL){
		Postfix += Top->data;
		Pop();
	}
	
	return Postfix;
}

string Infix_To_Prefix(string rev){
    string Infix = reverse(rev);
    string Prefix;

    for(int i = 0; i < Infix.length(); i++){
        if(Infix[i] == '('){
            Infix[i] = ')';
        }else if(Infix[i] == ')'){
            Infix[i] = '(';
        }
    }

    for(int i = 0; i < Infix.length(); i++){
        if ((Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z')||(Infix[i] >= '0' && Infix[i] <= '9')){
            Prefix += Infix[i];
        }else if (Infix[i] == '('){
            Push(Infix[i]);
        }else if (Infix[i] == ')'){
            while ((Top->data != '(') && (Top != NULL)){
                Prefix += Top->data;
                Pop();
            }
            if (Top->data == '(') {
                Pop();
            }
        }else if (is_Operator(Infix[i])) {
            if (Top == NULL) {
                Push(Infix[i]);
            }else {
                if (precedence(Infix[i]) > precedence(Top->data)) {
                    Push(Infix[i]);
                }else if ((precedence(Infix[i]) == precedence(Top->data)) && (Infix[i] == '^')) {
                    while ((precedence(Infix[i]) == precedence(Top->data)) && (Infix[i] == '^')) {
                        Prefix += Top->data;
                        Pop();
                    }
                    Push(Infix[i]);
                }else if (precedence(Infix[i]) == precedence(Top->data)) {
                    Push(Infix[i]);
                }else {
                    while ((Top != NULL) && (precedence(Infix[i]) < precedence(Top->data))) {
                        Prefix += Top->data;
                        Pop();
                    }
                    Push(Infix[i]);
                }
            }
        }
    }
    while (Top != NULL) {
        Prefix += Top->data;
        Pop();
    }

    return reverse(Prefix);
}

int Postfix_Exppression_Evaluation(string Postfix){
    int a , b, evaluation;
    for(int i = 0; i < Postfix.length(); i++){
        if(!is_Operator(Postfix[i])){
            push(char_To_Int(Postfix[i]));
        }else if(is_Operator(Postfix[i])){
            b = top->data;
            pop();
            a = top->data;
            pop();
            arithmetic_Operation(Postfix[i], a, b);             
        }
    }
    evaluation = top->data;
    pop();

    return evaluation;
}

int Prefix_Exppression_Evaluation(string rev){
    string Prefix = reverse(rev);
    int a , b, evaluation;
    for(int i = 0; i < Prefix.length(); i++){
        if(!is_Operator(Prefix[i])){
            push(char_To_Int(Prefix[i]));
        }else if(is_Operator(Prefix[i])){
            a = top->data;
            pop();
            b = top->data;
            pop();
            arithmetic_Operation(Prefix[i], a, b);
        }
    }
    evaluation = top->data;
    pop();

    return evaluation;
}

int main(){
    string Infix_Expression, Postfix_Expression, Prefix_Expression;
    int Postfix_Exp_Eval, Prefix_Exp_Eval;
    cout<<"Enter a Infix Expression :";
  	cin>>Infix_Expression;
    cout<<endl;
    
    Postfix_Expression = Infix_To_Postfix(Infix_Expression);
    cout<<"Postfix Expression: "<<Postfix_Expression<<endl;

    Prefix_Expression = Infix_To_Prefix(Infix_Expression);
    cout<<"Prefix Expression: "<<Prefix_Expression<<endl;

    Postfix_Exp_Eval = Postfix_Exppression_Evaluation(Postfix_Expression);
    cout<<"Postfix Evaluation: "<<Postfix_Exp_Eval<<endl;

    Prefix_Exp_Eval = Prefix_Exppression_Evaluation(Prefix_Expression);
    cout<<"Prefix Evaluation: "<<Prefix_Exp_Eval<<endl;

    return 0;
}

/*
output:-
Enter a Infix Expression :
2+4*(5+6)/8+9*1

Postfix Expression: 2456+*8/+91*+
Prefix Expression: ++2/*4+568*91
Postfix Evaluation: 16
Prefix Evaluation: 16

*/