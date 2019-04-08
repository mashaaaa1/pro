#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void arr_reverse(char* array[]);

int recDir(char* direct, char* result[], char* name_of_file);

int main() {

	char* result[3000];
	int i;
	for (i = 0; i < 3000; i++)
		result[i] = calloc(1000, sizeof(char));
	FILE *file = fopen("result.txt", "w");

	recDir("./labyrinth", result, "file.txt");

	arr_reverse(result);
	for (i = 0; result[i] != NULL; i++) {
		fprintf(file, "%s\n", result[i]);
		free(result[i]);
	}


	fclose(file);
	return 0;
}

int recDir(char* direct, char* result[], char* name_of_file) {

	static int i = 0;
	int d = 0, c = 0;
	char tmp[100] = "", way[1000] = "", branch[1000] = "";
        DIR* dir = opendir(direct);
	FILE* fp;
	struct dirent* de;

	strcpy(way, direct);
	strcat(way, "/");

	for (de = readdir(dir); de != NULL; de = readdir(dir))
    {
		if (strstr(de->d_name, ".") == NULL) {

			strcpy(branch, way);
			strcat(branch, de->d_name);
			d += recDir(branch, result, name_of_file);

		} else if (strcmp(name_of_file, de->d_name) == 0) {

			strcat(way, de->d_name);
			fp = fopen(way, "r");
			fgets(tmp, 100, fp);

			if (strstr(tmp, "\n")) *strstr(tmp, "\n") = '\0';

			c++;

			if (strcmp(tmp, "Minotaur") == 0) {

				strcpy(result[i++], way);
				fclose(fp);
				break;

			} else if (strcmp(tmp, "Deadlock") == 0) {

				d++;
				fclose(fp);
				closedir(dir);

				return d;

			} else if (strstr(tmp, ".txt")) {

				d += recDir("./labyrinth", result, strstr(tmp, " ") + 1);
				while (fgets(tmp, 100, fp) && strstr(tmp, ".txt")) {
					c++;
					if(strstr(tmp, "\n")) *strstr(tmp, "\n") = '\0';
					d += recDir("./labyrinth", result, strstr(tmp, " ") + 1);
				}
				if (d >= c) {

					fclose(fp);
					closedir(dir);

					return 1;

				} else {

					closedir(dir);
					fclose(fp);

					strcpy(result[i++], way);

					return 0;
				}

			}
		}
    }
	closedir(dir);

	return d;
}


void arr_reverse(char* array[]) {

	int i, j;
	char* temp;
	int k = 0;
	for(; *array[k] == '.'; k++);

	for (j = 0; j < k - 1; j++)
		for (i = j + 1; i < k; i++) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}

	for (i = k; i < 3000; i++) {
		free(array[i]);
		array[i] = NULL;
	}

}
