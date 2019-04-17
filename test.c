#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
 
int nextdir (char folder[],char* res[],int n)
{
    DIR *dfd;
static int i=0;
	char way[100]="";
	strcpy(way,folder);
    struct dirent *dp;
    dfd=opendir(folder);
    printf("Открытие папки %s \n",folder);
        while ((dp=readdir(dfd))!=NULL){
            if (dp->d_type!=4){
			// strcpy(res[i++],dp->d_name);
//			printf("%s\n",safe);
		         if(n==3){
			char safe[100]="";
                        strcpy(safe,way);
                        strcat(safe,"/");
                        strcat(safe,dp->d_name);//qsort(result,i,sizeof(char*),comp);
			int j;
			 for(j=0;j<=i;j++){
			if(!strcmp(dp->d_name,res[j])){
//					printf("%s %s\n ",dp->d_name,res[j]);
					remove(safe);
			}}
			}
			strcpy(res[i++],dp->d_name);
				}
                if ((dp->d_type==4) && ((strcmp(dp->d_name,".")!=0) && (strcmp(dp->d_name,"..")!=0))){
                   char folder[100]="";
		strcpy(folder,way);
		strcat(folder,"/");
			strcat(folder,dp->d_name);          
                    nextdir(folder,res,n);
                }
}
    closedir(dfd);
 return i;
}

int comp(const void* str, const void* str1){
    return strcmp(*((char**)str),*((char**)str1));
}
 
int main()
{
    char filename[]="./c";
	char* result[500];
	int i;
	int digit;
	for(i=0;i<500;i++){
		result[i]=calloc(100,sizeof(char));
}
    scanf("%d",&digit);
    printf("Корневой каталог %s\n\n", filename);
    int j=nextdir(filename,result,digit);
	int k=0;
	qsort(result,j,sizeof(char*),comp);
	for(i=0;i<j;i++){
		if(!strcmp(result[i],result[i+1])){
			//printf("%s\n",result[i]);
			while(!strcmp(result[i],result[i+1])){
				i++;
				k++;
			}
			if(digit==2){
			printf("%s - %d\n",result[i-1],k+1);
			k=0;
			}
			if(digit==1){
			printf("%s\n",result[i-1]);
			k=0;
			}
		}
	}
	for(i=0;i<500;i++){
		free(result[i]);
}
    return 0;
}
