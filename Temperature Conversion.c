#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    const int times = n;
    char units[times];
    float values[times];
    for (int i = 0; i < times; i++){       
        char unit;
        float value;
        scanf("%s %f", &unit, &value);
        units[i] = unit;
        values[i] = value;
    }
    for (int i = 0; i < times; i++){
        float new_val=0.0;
        char unit = units[i];
        float value = values[i];
        if (unit=='C'){
            new_val = 1.8 * value + 32;
        }else{
            new_val = (value - 32) / 1.8;
        }
        printf("%.2f\n", new_val);
    }
    
    return 0;
    getchar();
    getchar();
}