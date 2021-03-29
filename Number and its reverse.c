#include <stdio.h>
#include <math.h>

long len(long num){
    long n = 1;
    while (num/10!=0){
        num = num / 10;
        n++;
    }
    return n;
}

long inverse(long origin){
    long length = len(origin);
    long inv = 0;
    for (int i = 1; i <= length;i++)
    {
        inv += (origin % 10) * pow(10, length - i);
        origin = origin / 10;
    }
    return inv;
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t;i++){
        long target;
        long tot=0;
        scanf("%ld", &target);
        getchar();
        for (long i = target; i >= target / 2;i--){
            if (i+inverse(i)==target){
                if (i==target/2 || i%10==0)
                    tot += 1;
                else
                    tot += 2;
            printf("%ld\n", i);
            printf("%ld\n", inverse(i));
                
            }                
        }
        printf("%ld\n", tot);
    }

    return 0;
    getchar();
    getchar();
}