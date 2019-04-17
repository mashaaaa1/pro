#include <stdio.h> 
#include <stdlib.h> 
#include <dirent.h> 
#include <limits.h> 
#include <string.h> 
#include <regex.h> 
#include <sys/stat.h>
 int find(char* way){
char* string ="[a-zA-Z0-9_]+@[a-zA-Z0-9_-]+\\.[a-z]+";
    regex_t reg;
    FILE* fp;
    fp=fopen(way,"r");
	if( regcomp(&reg, string, REG_EXTENDED)){
                return 0;
} 
        int j=0;

	char s[100];
	while(fgets(s,100,fp)){
		if(!regexec(&reg, s, 0, NULL, 0)){
			j=1;
	}
	}
   return j;	
}

void rem(char* way){
char* string ="[a-zA-Z0-9_]+@[a-zA-Z0-9_-]+\\.[a-z]+";
    regex_t reg;
    FILE* fp;
    fp=fopen(way,"r");
     regcomp(&reg, string, REG_EXTENDED);           
	char mas[3000];
        char s[100];
	int i=0;
	int j=0;
	while(fgets(s,100,fp)){
                if(regexec(&reg, s, 0, NULL, 0)){
			i=0;
                       while(s[i]!='\n'){
			mas[j]=s[i];
			j++;
			i++;
			}
			mas[j++]='\n'; 
        }}
	remove(way);
	fp=fopen(way,"w");
	fwrite(mas,sizeof(char),strlen(mas),fp);
}

int nextdir (char folder[],char* res[], char name[],int n)
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
			if(strstr(dp->d_name,name)!=NULL){
                         strcpy(res[i++],dp->d_name);
                        }
			char folder[100]="";
                strcpy(folder,way);
                strcat(folder,"/");
                        strcat(folder,dp->d_name);
			if(n==2){ 
			int j=find(folder);
			if(j){
				printf("%s\n",folder);
				remove(folder);
			}}
			if(n==3){
				rem(folder);
			}
		}
                if ((dp->d_type==4) && ((strcmp(dp->d_name,".")!=0) && (strcmp(dp->d_name,"..")!=0))){
                   char folder[100]="";
                strcpy(folder,way);
                strcat(folder,"/");
                        strcat(folder,dp->d_name);          
                    nextdir(folder,res,name,n);
                }
}
    closedir(dfd);
 return i;
}

int main()
{
    char filename[]="./c";
        char* result[500];
        int i;
        for(i=0;i<500;i++){
                result[i]=calloc(100,sizeof(char));
}
	int n;
	scanf("%d",&n);
    char type[10]=".";
	char tst[10];
	i=0;
	char c=getchar();
    while ((c = getchar()) != '\n'){
      tst[i++]=c;
    }
    tst[i+1]='\0';
    strcat(type,tst);
    printf("Корневой каталог %s\n\n", filename);
    int j=nextdir(filename,result,type,n);
int k=0;
if(n==1){
printf("%d\n",j);
	for(i=0;i<j;i++){
		printf("%s\n",result[i]);
}}
        for(i=0;i<500;i++){
                free(result[i]);
}
    return 0;
}

