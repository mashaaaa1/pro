#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h> 
void nextdir1 (char folder[],int digit)
{
    	DIR *dfd;
	static int i=0;
        char way[100]="";//директория
	char way2[100]="";//создание папки по первой букве
        strcpy(way,folder);
	strcat(way,"/");
	struct dirent *dp;
    dfd=opendir(folder);
    printf("Открытие папки %s \n",folder);
        while ((dp=readdir(dfd))!=NULL){
            if (dp->d_type!=4){
			char name[100]="";
			strcpy(name,dp->d_name);
			strcpy(way2,folder);
			strcat(way2,"/");
			char s[2]="";
			char mas1[]="";
			strcpy(mas1,dp->d_name);
			s[0]=tolower(mas1[0]);
			s[1]='\0';
			strcat(way2,s);
			mkdir(way2,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
			FILE* fp;
			char way3[100]="";//открытие папки
			strcpy(way3,folder);
			strcat(way3,"/");
			strcat(way3,dp->d_name);
			fp=fopen(way3,"r");
			char mas[]="";
			fread(mas,sizeof(char),1000,fp);
			strcat(way2,"/");
			strcat(way2,name);
			fp=fopen(way2,"w");
			fwrite(mas,sizeof(char),strlen(mas),fp);
			remove(way3);			
			fclose(fp);
}
}
    closedir(dfd);
}
void nextdir3 (char folder[],char mas[])
{
        DIR *dfd;
        static int i=0;
        char way[100]="";//директория
        char way2[100]="";//создание папки по первой букве
        strcpy(way,folder);
        strcat(way,"/");
        struct dirent *dp;
    dfd=opendir(folder);
    printf("Открытие папки %s \n",folder);
        while ((dp=readdir(dfd))!=NULL){
            if (dp->d_type!=4){
			if(strncmp(dp->d_name,mas,strlen(mas))==0 || strcmp(dp->d_name,mas)==0){
                        char way1[100]="";
			strcpy(way1,folder);
			strcat(way1,"/");
			strcat(way1,dp->d_name);
			printf("%s\n",way1);
			remove(way1);
			printf("удаление файла:%s\n",dp->d_name);
}}
                if ((dp->d_type==4) && ((strcmp(dp->d_name,".")!=0) && (strcmp(dp->d_name,"..")!=0))){
                   char folder[100]="";
                strcpy(folder,way);
                        strcat(folder,dp->d_name);          
                    nextdir3(folder,mas);
                }

}
    closedir(dfd);
}

 
int main()
{
    char filename[]="./c";
        int i=0;
	int digit;
	char mas[20];
	    scanf("%d",&digit);
if(digit==3){
	char c=getchar();
	while((c=getchar())!='\n'){
		mas[i]=c;
		i++;
	}
	mas[i]='\0';
	printf("%s\n",mas);
        nextdir3(filename,mas);
}
else{
    nextdir1(filename,digit);
}
       

return 0;
}
