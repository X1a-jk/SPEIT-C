#include <stdio.h>

#define N 10000
void quickSort(long arr[][N], long start, long end);

void quickSort2(long arr[][N], long start, long end);

void exchange(long arr[][N], long i, long j);

long partition(long arr[][N], long start, long end);

long partition2(long arr[][N], long start, long end);

void regroup(long arr[][N], long start, long end);

///void regroup(int arr[][N], int num);

int main(){
    long numbers;
    scanf("%ld", &numbers);
    getchar();

    long data[2][N];

    for (long i = 0; i < numbers;i++){
        scanf("%ld %ld", &data[0][i],&data[1][i]);
        getchar();
    }
    quickSort(data, 0, numbers - 1);
    
    
    // for (long i = 0; i < numbers;i++){
    //     printf("%d ", data[0][i]);
    //     printf("%d\n", data[1][i]);
    //     //printf("\n");
    // }
    //printf("\n");
    regroup(data, 0, numbers - 1);
    for (long i = 0; i < numbers;i++){
        printf("%ld ", data[0][i]);
        printf("%ld\n", data[1][i]);
        //printf("\n");
    }
    return 0;
    getchar();
    getchar();
}

// int partition( int A[][N], int left, int right){
//     int i, j;
//     int pivo = A[1][(left + right) / 2];
//     int idpivo=A[0][(left + right) / 2];
//     i = left;
//     j = right;
//     while (1){
//         while (A[1][i] > pivo){i++;}
//         while (A[1][j] < pivo){j--;}

//     if (i < j)
//         exchange(A, i, j);
//     else
//         break;
//     }
//     return i;
// }


void exchange(long grades[][N], long i, long j){
    long temp = grades[0][i];
    grades[0][i] = grades[0][j];
    grades[0][j] = temp;
    
    long temps = grades[1][i];
    grades[1][i] = grades[1][j];
    grades[1][j] = temps;
    i++;
    j--;
}

long partition(long arr[][N], long start, long end){
    long i= start;
    long j= end+1;
    long mid = (start + end) / 2;
    long pivot = arr[1][mid];
    exchange(arr,start,mid);
    while (1){
        while (arr[1][++i]>pivot){
            if (i>=end) break;
        }
        // if (arr[1][i]==pivot){
        //     if (arr[0][i]>arr[0][start]){
        //         exchange(arr,i,start);
        //         //printf("1=%d",&arr[0][i]);
        //         //printf("1=%d",&arr[0][mid]);
        //     }
        // }
        while (arr[1][--j]<pivot){
            if (j<=start) break;
        }
        // if (arr[1][j]==pivot){
        //     if (arr[0][j]<arr[0][start]){
        //         exchange(arr,j,start);
        //         // printf("2=%d",&arr[0][j]);
        //         // printf("2=%d",&arr[0][mid]);
        //     }
        // }
        
        if (i>=j)
            break;
        exchange(arr, i, j);       
    }
    exchange(arr,start,j);
    return j;
}

void quickSort(long arr[][N], long start, long end){
    if (start>=end) return;
    long j = partition(arr, start, end);
    quickSort(arr, start, j-1);
    quickSort(arr, j+1, end);
}

void quickSort2(long arr[][N], long start, long end){
    if (start>=end) return;
    long j = partition2(arr, start, end);
    quickSort2(arr, start, j-1);
    quickSort2(arr, j+1, end);
}

long partition2(long arr[][N], long start, long end){
    long i= start;
    long j= end+1;
    long mid = (start + end) / 2;
    long pivot = arr[0][mid];
    exchange(arr,start,mid);
    while (1){
        while (arr[0][++i]<pivot){
            if (i>=end) break;
        }
        // if (arr[1][i]==pivot){
        //     if (arr[0][i]>arr[0][start]){
        //         exchange(arr,i,start);
        //         //printf("1=%d",&arr[0][i]);
        //         //printf("1=%d",&arr[0][mid]);
        //     }
        // }
        while (arr[0][--j]>pivot){
            if (j<=start) break;
        }
        // if (arr[1][j]==pivot){
        //     if (arr[0][j]<arr[0][start]){
        //         exchange(arr,j,start);
        //         // printf("2=%d",&arr[0][j]);
        //         // printf("2=%d",&arr[0][mid]);
        //     }
        // }
        
        if (i>=j)
            break;
        exchange(arr, i, j);       
    }
    exchange(arr,start,j);
    return j;
}


void regroup(long arr[][N], long start, long end){
    long i = start;
    while (i<=end){
        if (arr[1][i]==arr[1][i+1]){
            long j = 1;
            while (arr[1][i]==arr[1][i+j] && i+j<=end){
                j++;
            }
            //printf("%d %d\n", i, i + j - 1);
            quickSort2(arr, i, i + j-1);
            i = i + j;
        }else{i++;}
        
    }
}



// void regroup(int arr[][N],int num){
//     for (int j = 0; j < num;j++){

//     }
// }