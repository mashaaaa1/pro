#include "index_first_negative.h"
#include "index_last_negative.h"
int multi_between_negative(int a[],int size){
        int p=1;
        int i;
        for(i=index_first_negative(a,size);i<index_last_negative(a,size);i++){
          p*=a[i];

        }
        return p;
        }
