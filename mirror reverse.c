#include <stdio.h>

char ch;
char A[30];

char reverse(char a){
    switch(a){
        case 'A':
            return 'A';
            break;
        case 'E':
            return '3';
            break;
        case 'H':
            return 'H';
            break;
        case 'I':
            return 'I';
            break;
        case 'J':
            return 'L';
            break;
        case 'L':
            return 'J';
            break;
        case 'M':
            return 'M';
            break;
        case 'O':
            return 'O';
            break;
        case 'S':
            return '2';
            break;
        case 'T':
            return 'T';
            break;
        case 'U':
            return 'U';
            break;
        case 'V':
            return 'V';
            break;
        case 'W':
            return 'W';
            break;
        case 'X':
            return 'X';
            break;
        case 'Z':
            return '5';
            break;
        case 'Y':
            return 'Y';
            break;
        case '1':
            return '1';
            break;
        case '2':
            return 'S';
            break;
        case '3':
            return 'E';
            break;
        case '5':
            return 'Z';
            break;
        case '8':
            return '8';
            break;
        case '+':
            return '+';
            break;
        case '-':
            return '-';
            break;
        case '*':
            return '*';
            break;
        case '(':
            return ')';
            break;
        case ')':
            return '(';
            break;
        default:
            return -1;
    }
}

int main(){
    
    while (scanf("%s",&A) != EOF) {
        int a = 0;
        int len = strlen(A);
        for (int i = 0, j = len-1; i < j;i++,j--){
            if (A[i]!=reverse(A[j])){
                //printf("%c %c", A[i], A[j]);
                a = 1;
                break;
            }
            
        }
        if (a==0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        printf("%s", A);
    }
    //printf("%d", i);

    return 0;
    getchar();
    getchar();
}