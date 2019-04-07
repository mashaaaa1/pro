#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
int DirTree(char* dir,char* res[],char* file){
    int tr=0,fl=0;
    char* way_res[500],tmp[500],way[5000];
    DIR* direct=opendir(dir);
    FILE* fp;
    struct dirent* dr;
    strcpy(way_res,dir);
    strcat(way_res,"/");
    while(dr=readdir(direct)){
        if(!strstr(dr->d_name,".")){
            strcpy(way,way_res);
            strcpy(way,dr->d_name);
            fl+=DirTree(way,res,file);
        }
        else if(!strcmp(dr->d_name,file)){
            strcat(way_res,dr->d_name);
            fp=fopen(way_res,"r");
            tr++;
            fgets(tmp,100,fp);
            if(strstr(tmp,"\n")){
                *(strstr(tmp,"\n"))='\0';
            }
            else if(!strcmp(tmp,"Minotaur")){
                strcpy(result[i++],way_res);
                fclose(fp);
                closedir(dr);
                return fl;
            }
            else if(!strcmp(tmp,"Deadlock")){
                fl++;
                fclose(fp);
                closedir(dr);
                return fl;
            }
            else if(strstr(tmp,".txt")){
                fl+=DirTree("./labyrinth", res, strstr(tmp, " ") + 1);
                while (fgets(tmp, 150, fp) && strstr(tmp, ".txt")) {
					tr++;
					if(strstr(tmp, "\n")){
					    *strstr(tmp, "\n") = '\0';
					}
					fl += DirTree("./labyrinth", res, strstr(tmp, " ") + 1);
				}
				if (fl >= tr){
					fclose(fp);
					closedir(direct);
					return 1;
				} 
				else{
					closedir(direct);
					fclose(fp);
					strcpy(res[i++], way_res);
					return 0;
				}
            }
        }
    }
    closedir(direct);
    return fl;
}
void back(char* mas[]){
	int i, j;
	char* tmp;
	int k=0;
	for(; *mas[k] == '.'; k++);
	for (j = 0; j < k - 1; j++)	
		for (i = j + 1; i < k; i++) {
			tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
		}
	for (i = k; i < 3000; i++) {
		free(array[i]);
		array[i] = NULL;
	}

}
int main()
{
    char* result[3000];
    int i;
    for(i=0;i<3000;i++){
        result[i]=malloc(1000*sizeof(char));
    }
    FILE *file=fopen("result.txt","w");
    DirTree("./labyrinth",result,"file.txt");
    back(result);
    for (i = 0; result[i] != NULL; i++) {
		fprintf(file, "%s\n", result[i]);
		free(result[i]);
	}
	fclose(file);
    return 0;
}

