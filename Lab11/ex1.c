#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int file;
	struct stat fStat;
	file = open("ex1.txt", O_RDWR);
	if (file < 0){
	perror("Error");
	}

	if (stat("ex1.txt", &fStat) < 0){
	perror("Error");
	}
	size_t fileSize = (size_t) fStat.st_size;
	char *map = mmap(0, fileSize, PROT_WRITE, MAP_SHARED, file, 0);

	if (map == MAP_FAILED){
	perror("Error");
	}
	char *result = "This is a nice day";
	size_t resultLen = strlen(result);

	if(fileSize < resultLen){
        fileSize = resultLen;
	}

	memset(map, ' ', fileSize);
	strcpy(map, result);
	map[resultLen] = ' ';
	munmap(map, fileSize);
	return 0;
}