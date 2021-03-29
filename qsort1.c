#include <stdio.h>
void quisort(int* arr, int start, int end, int* ptr, int length);

void swap(int *arr, int i, int j);

int partition(int *arr, int start, int end, int* ptr, int length);

void display(int *arr, int length, int pivot);

int loop_num = 0;

void swap(int *A, int i, int j)
{
    int temp;
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

int partition(int* A, int left, int right, int* ptr, int len)
{
    int i,j;
    int pivo = A[ (left+right)/2 ];
   
    i = left; j = right;
    while( 1 )
    {
        while( A[ i ] < pivo ){ i++; }
        while( A[ j ] > pivo ){ j--; }
        if ( i < j )
            swap(A, i, j);
        else
            break;
    }


    (*ptr)++;
    if (*ptr<=3){
        display(A, len, pivo);
    }
    return i;
}

void quisort(int* A, int start, int end, int* ptr, int len)
{
    int i;
    if( end > start )
    {
        i = partition( A, start, end, ptr, len);
        quisort( A, start, i - 1, ptr, len );
        quisort( A, i + 1, end, ptr, len);
    }
}

void display(int *arr, int length, int pivot){
    printf("pivot=%d\n", pivot);
    for (int i = 0; i <length;i++){
        printf("%d ", *(arr + i));
        
    }
    printf("\n");
}

int main() {
    int num;
    scanf("%d", &num);
    int arr[100];
    int j;
    int c;
    for (int i = 0; i < num; ++i) {
        int count = 0;
        int *countptr = &count;
            j = 0;
            scanf("%d", &arr[j++]);
            while( (c =getchar()) !='\n' && c != EOF)
            {
                scanf("%d", &arr[j++]);
            }

           quisort(arr, 0, j - 1, countptr, j);
            if (i != num - 1)
                printf("\n");
        }
    return 0;
    getchar();
    getchar();
}
