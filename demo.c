#include <stdio.h>

int main()

{

    int a,b,c;

    scanf("%d %d %d",&a,&b,&c);

    if (a++==1&& b++==2)

        if (c--==3||b++!=2)

            printf("%d,%d,%d\n",a,b,c);

        else printf("%d,%d,%d\n",b,c,a);

    else printf("%d,%d,%d\n",1&3,a,b);

    return(0);
    getchar();
    getchar();
}