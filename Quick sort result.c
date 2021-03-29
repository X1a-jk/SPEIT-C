#include <stdio.h>

void quickSort(int* arr, int start, int end, int* ptr, int length);

void exchange(int *arr, int i, int j);

int partition(int *arr, int start, int end, int* ptr, int length);

void display(int *arr, int length, int pivot);

int main(){
    int times;
    scanf("%d", &times);
    getchar();
    
    for (int i = 0; i < times;i++){
        int count = 0;
        int *countptr = &count;
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
        quickSort(array, 0,j-1,countptr,j);
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

int partition(int* arr, int start, int end, int* ptr, int length){
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
    (*ptr)++;
    if (*ptr<=3){
        display(arr, length, pivot);
    }

    return j;
}

void quickSort(int* arr, int start, int end, int* ptr,int length){
    if (start>=end) return;
    int j = partition(arr, start, end, ptr,length);
    quickSort(arr, start, j-1, ptr,length);
    quickSort(arr, j+1, end, ptr,length);
}

void display(int *arr, int length, int pivot){
    printf("pivot=%d\n", pivot);
    for (int i = 0; i <length;i++){
        printf("%d ", *(arr + i));
        
    }
    printf("\n");
}