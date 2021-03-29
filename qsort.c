#include <stdio.h>

void quickSort(int* arr, int start, int end,int* count);

void exchange(int *arr, int i, int j);

int partition(int *arr, int start, int end);



int main(){
    int times;
    scanf("%d", &times);
    getchar();
    int num = 3;
    for (int i = 0; i < times;i++){
        int array[100] = {0};
        int j = 0;
        char s;
        do{
            scanf("%d", &array[j]);
            s = getchar();
            j++;
            //printf("j=%d\n", j);
        } while (s != '\n' && s != -1);

        // for (int i = 0; i < j;i++){
        //     printf("%d\n", array[i]);
        // }
        // printf("%d\n", j);
        quickSort(array, 0,j-1,&num);
        // printf("%d\n", ans);
        // for (int i = 0; i < j;i++){
        //     printf("%d\n", array[i]);
        // }
    }
    return 0;
    getchar();
    getchar();
}

void exchange(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
}

int partition(int* arr, int start, int end){
    int i= start;
    int j= end+1;
    int mid = (start + end) / 2;
    int pivot = arr[mid];
    exchange(arr,start,mid);
    while (1){
        while (arr[++i]<pivot){
            if (i>=end) break;
        }
        while (arr[--j]>pivot){
            if (j<=start) break;
        }
        if (i>=j)
            break;
        exchange(arr, i, j);       
    }
    exchange(arr,start,j);
    // while (*count>0){
    //     printf("pivot=%d\n", mid);
    //     for (int i = start; i <= end;i++){
    //         printf("%d ", arr[i]);
    //     }
    //     printf("\n");
    //     *count--;
    //     printf("count=%d",*count);
    // }
    return j;
}

void quickSort(int* arr, int start, int end, int* count){
    if (start>=end) return;
    int mid = (start + end) / 2;
    int pivot = arr[mid];
    int j = partition(arr, start, end);
    quickSort(arr, start, j-1,count);
    quickSort(arr, j+1, end,count);
    
    while (*count>0){
        printf("pivot=%d\n", pivot);
        for (int i = start; i <= end;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        *count--;
        //printf("count=%d",*count);
    }
}