#include <stdio.h>

long isFactor(long long m, long long n){
    if (m%n!=0){
        return 0;
    }
    else{
        if (m==n*n)
            return 1;
        else
            return 2;
    }

}

int main(){
    int numbers;
    scanf("%d", &numbers);
    getchar();
    for (int i = 0; i < numbers;i++){
        long long divisor;
        long factor = 0;
        scanf("%lld", &divisor);
        getchar();
        for (long long numerator = 1; numerator * numerator <= divisor; numerator++){
            factor += isFactor(divisor,numerator);
        }
        printf("%ld\n", factor);
    }
    return 0;
    getchar();
    getchar();
}
