#include "index_first_negative.h"
int index_first_negative(int a[],int size){
        int i;
        for(i=0;i<size;i++){ 
            if (a[i]<0){
            return i;
            }
        }
}
