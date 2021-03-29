#include <stdio.h>

int max_factor(int a, int b){
    while (b!=0){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}


int main(){
    int x, y;
    scanf("%d/%d", &x, &y);
    printf("%d",max_factor(x, y));
    return 0;
    getchar();
    getchar();
}




