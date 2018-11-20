#include <stdio.h>
#include "multi_before_and_after_negative.h"
#include "multi_between_negative.h"
#include "index_last_negative.h"
#include "index_last_negative.h"
#define N 20
int main(){
    char c=' ';
    int b;
    int a[N];
    int s;
    int i=0;
scanf("%d\n",&b); 

for(i=0;i<N&&c!='\n';i++){ 
        scanf("%d%c",&a[i],&c);

}

switch(b)
{
        case 0:
            s=index_first_negative(a,i);
            printf("%d\n",s);
            break;
        case 1:
            s=index_last_negative(a,i);
             printf("%d\n",s);
            break;
        case 2:
            s=multi_between_negative(a,i);
            printf("%d\n",s);
            break;          
        case 3: 
            s=multi_before_and_after_negative(a,i);
             printf("%d\n",s);
             break;
        default :
        printf("Данные некорректны\n");
}

        return 0;
}

