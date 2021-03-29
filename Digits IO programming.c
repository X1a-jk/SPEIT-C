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
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n;i++){
        int b;
        scanf("%d", &b);
        a[n - i] = b;
    }

    int result = a[0];
    for (int j = 1; j < n;j++){
        result = max_factor(result, a[j]);
    }
    printf("%d", result);
    
    return 0;
    getchar();
    getchar();
}