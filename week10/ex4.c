#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

#include <string.h>
#include <sys/stat.h>

#include <inttypes.h>

#define ERROR EXIT_FAILURE
#define SUCCESS EXIT_SUCCESS


typedef struct{
    char *name;
    ino_t inode; //
    int p_flag;
} fileInfo;



int main(){
	
	struct dirent *dir_t;
	int len = strlen("./tmp/");
	int n = 0;
	fileInfo *files;
	
    files = (fileInfo *)calloc(256, sizeof(fileInfo));

	//opening directory
    DIR *dirp = opendir("./tmp/");
    if (dirp == NULL) return ERROR;
    
    while((dir_t = readdir(dirp)) != NULL){
        (files + n)->name = (char *)calloc(256, sizeof(char));
        strcpy((files + n)->name, dir_t->d_name); //filename
        (files + n)->inode = dir_t->d_ino; //inode number
        (files + n)->p_flag = 0; //flag if it is printed
        n++;
    }
    closedir(dirp);

    for (int i=0;i<n;i++){
		
		//if the file is printed we skip it
        if ((files + i)->p_flag) continue;
		
        struct stat file;
		
        char* filePath =(char*)malloc(len + strlen((files + i)->name) + 1);
        strcpy(filePath, "./tmp/");
        strcat(filePath, (files + i)->name);
	
		//getting stats of the file
        stat(filePath, &file);
        free(filePath);
		
		//if number of hard links to the file is less than 2 we skip it
        if (file.st_nlink < 2) continue;

        int flag=1;
        for(int j=0;j<n;++j){
			//if inodes are the same and file is not printed we print it
            if((files + j)->inode == (files + i)->inode && (!(files + j)->p_flag)){
                if(strcmp((files+j)->name,"..") && strcmp((files+j)->name,".")){
					printf("%s ", (files + j)->name);
					flag=0;
				}
                (files + j)->p_flag = 1;
            }
        }
		
        if(flag==0){
			printf("\n");
		}
    }
    return SUCCESS;
}