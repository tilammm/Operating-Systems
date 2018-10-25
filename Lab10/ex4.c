#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>

int main(){
        struct stat *buff = malloc(sizeof(struct stat));
        int count = 0;

        DIR* dirp = opendir("tmp");
        struct dirent* dp;

        while ((dp = readdir(dirp)) != NULL) {
                count++;
        }

        dirp = opendir("tmp");

        struct dirent dps[count];

        int i = 0;
        while ((dp = readdir(dirp)) != NULL) {
                dps[i] = *dp;
                i++;
        }


        ino_t inode;
        for(int j=0; j < count; j++) {
                char *path = malloc(100); 
                strcat(path, "./tmp/");
                strcat(path, dps[j].d_name );
                stat(path, buff);


                
                if( buff->st_nlink >= 2 && dps[j].d_ino != 0) {
                        inode = buff->st_ino; 
                        printf("\n%s (i-node #: %lu ) : ", dps[j].d_name , inode);
                        dps[j].d_ino = 0; 
                        struct stat *buff_supp = malloc(sizeof(struct stat));
                        for(int k=0; k<count; k++) {
                                if(dps[k].d_ino!=0) { 
                                        char *path_supp = malloc(100); 
                                        strcat(path_supp, "./tmp/");
                                        strcat(path_supp, dps[k].d_name );
                                        stat(path_supp, buff_supp); 
                                        if(buff_supp->st_ino == inode ) { 
                                                printf("%s (i-node #: %lu ) ", dps[k].d_name, buff_supp->st_ino);
                                                dps[k].d_ino = 0; 
                                        }
                                }
                        }
                }
        }

        (void)closedir(dirp);
        return 0;
}