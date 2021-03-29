#include <stdio.h>

int time = 0;

void exchange(int *A, int i, int j);

int partition(int *A, int left, int right, int len);

void quisort(int *A, int start, int end, int len);

int main() {
    int num;
    scanf("%d", &num);
    int arr[100];
    int j;
    int c;
    for (int i = 0; i < num; ++i) {

            j = 0;
            scanf("%d", &arr[j++]);
            while( (c =getchar()) !='\n' && c != EOF)
            {
                scanf("%d", &arr[j++]);
            }

           quisort(arr, 0, j - 1, j);
            if (i != num - 1)
                printf("\n");
            time = 0;
        }
    return 0;
    getchar();
    getchar();
}


void exchange(int *A, int i, int j)
{
    int temp;
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

int partition(int* A, int left, int right, int len)
{
    int i,j;
    int pivo = A[ (left+right)/2 ];
    if (time < 3){
        printf("pivo=%d\n", pivo);
    }
    i = left; j = right;
    while( 1 )
    {
        while( A[ i ] < pivo ){ i++; }
        while( A[ j ] > pivo ){ j--; }
        if ( i < j )
            exchange(A, i, j);
        else
            break;
    }

    if (time < 3) {
        for (int k = 0; k < len - 1; ++k) {
            printf("%d ", A[k]);
        }
        printf("%d", A[len - 1]);
        printf("\n");
    }

    time ++;
    return i;
}

void quisort(int* A, int start, int end, int len)
{
    int i;
    if( end > start )
    {
        i = partition( A, start, end, len);
        quisort( A, start, i - 1, len );
        quisort( A, i + 1, end, len);
    }
}