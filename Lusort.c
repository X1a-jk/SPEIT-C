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
}

int partition(int* arr, int start, int end, int* ptr, int length){
    int i, j;
    int pivot = arr[(start + end) / 2];
    i = start;
    j = end;
    while (1){
        while (arr[i]<pivot){
            i++;
        }
        while (arr[j]>pivot){
            j--;
        }
        if (i<j)
            exchange(arr,i,j);
        else
            break;
    }
    (*ptr)++;
    if (*ptr<=3){
        display(arr, length, pivot);
    }

    return i;
}

void quickSort(int* arr, int start, int end, int* ptr,int length){
    int i;
    if (end > start){
    i = partition(arr, start, end, ptr,length);
    quickSort(arr, start, i-1, ptr,length);
    quickSort(arr, i+1, end, ptr,length);
    }
}

void display(int *arr, int length, int pivot){
    printf("pivot=%d\n", pivot);
    for (int i = 0; i <length;i++){
        printf("%d ", *(arr + i));
        
    }
    printf("\n");
}