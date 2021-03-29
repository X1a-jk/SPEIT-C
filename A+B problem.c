#include <stdio.h>




int main(){
    

    int times;
    scanf("%d", &times);
    getchar();

    for (int i = 0; i < times;i++){
        char A[100];
        char B[100];
        int C[100]={0};
        scanf("%s %s", A, B);
        getchar();
        //printf("%s\n", A[0]);
        int a = strlen(A);
        int la = a;
        int b = strlen(B);
        int lb = b;
        if (a>b){
            while (b>=1){
                int d = A[a - 1] - '0' + B[b - 1] - '0' + C[a - 1];
                if (d>=10){
                    d = d % 10;
                    C[a - 1] = d;
                    C[a - 2]++;
                }else{
                    C[a - 1] = d;
                }
                a--;
                b--;
            }
            for (int i = a-1; i > 0;i--){
                if (A[i]-'0'+C[i]>=10){
                    C[i] = 0;
                    C[i - 1]++;
                }else{
                    C[i] = A[i]-'0'+C[i];
                }
            }
            C[0] = C[0] + A[0] - '0';
            for (int i = 0; i <la;i++){
                    printf("%d", C[i]);
                }
                printf("\n");
        }else{
            if (a<b){
                while (a>=1 ){
                int d = B[b - 1]-'0' + A[a - 1]-'0'+C[b - 1];
                if (d>=10){
                    d = d % 10;
                    C[b - 1] = d;
                    C[b - 2]++;
                }else{
                    C[b - 1] = d;
                }
                a--;
                b--;
                }
                for (int i = b-1; i > 0;i--){
                    if (B[i]-'0'+C[i]>=10){
                        C[i]=0;
                        C[i-1]++;
                    }else{
                        C[i] = B[i] - '0' + C[i];
                    }
                }
                C[0] = C[0] + B[0] - '0';
                for (int i = 0; i <lb;i++){
                    printf("%d", C[i]);
                }
                printf("\n");
            }else{
                //printf("%d",a);
                for (int i = a; i > 1;i--){
                    int d = A[i-1] - '0' + B[i-1] - '0'+C[i-1];
                    if (d>=10){
                        d = d % 10;
                        C[i-1] = d;
                        C[i - 2]++;
                    }else{
                        C[i-1] = d;
                    }
                }
                C[0] = C[0] + A[0] - '0' + B[0] - '0';
                for (int i = 0; i <a;i++){
                    printf("%d", C[i]);
                }
                printf("\n");
                //printf("%d\n", C);
            }
        }
        //int C[100]={0};
    }
    printf("END");
    return 0;
    getchar();
    getchar();
}

// int main(){
//     char A[100];
//     char B[100];
//     int times;
//     scanf("%d", &times);
//     getchar();

//     for (int i = 0; i < times;i++){
//         scanf("%s %s", &A, &B);
//         getchar();
//         for (int i = 0; i < strlen(A);i++){
//             printf("%d\n", A[i]-'0');
//         }
//     }

//     return 0;
//     getchar();
//     getchar();
// }