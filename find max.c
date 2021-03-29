#include <stdio.h>

int find_max(int* arr,int n){
    //int i = 0;
    int p = *arr;
    int *ptr = arr;
    for (int i = 0; i < n;i++,ptr++){
        if (*ptr>p)
            p = *ptr;
    }
    return p;
}

int main(){
    int times;
    scanf("%d", &times);
    getchar();
    for (int i = 0; i < times;i++){
        int array[100] = {0};
        int j = 0;
        char s;
        do{
            scanf("%d", &array[j]);
            s = getchar();
            j++;
        } while (s != '\n' && s != -1);

        int ans = find_max(array, 100);
        printf("%d\n", ans);
        
    }
    return 0;
    getchar();
    getchar();
}