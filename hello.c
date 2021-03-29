#include <stdio.h>
void exchange(int *arr, int i, int j);

int main()

{
void exchange(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int A[8] = {1, 2, 3,4,5,6,7,0};
exchange(A, 0, 2);
for (int i = 0; i < 8;i++){
    printf("%d\n", *(A + i));
}

    getchar();
getchar();
}