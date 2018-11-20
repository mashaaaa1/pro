#include "index_first_negative.h"
#include "index_last_negative.h"
int multi_before_and_after_negative(int a[],int size){
        int von=1;
        int i;
        int j;
        int man=1;
        for(i=0;i<index_first_negative(a,size);i++){
        von*=a[i];
        }
        for(j=index_last_negative(a,size);j<size;j++){
        man*=a[j];
        }
        return man*=von;
        }
