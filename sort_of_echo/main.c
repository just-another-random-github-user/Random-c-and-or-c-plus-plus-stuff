#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef FILE_SIZE
#define FILE_SIZE 0
#endif

int main(int argc, char** argv, char** envp) {
	int fd = open("/proc/self/exe", O_RDONLY);
	int64_t end = (int64_t)lseek(fd, 0, SEEK_END);
	int64_t off = (int64_t)lseek(fd, FILE_SIZE, SEEK_SET);
	char* ptr = (char*) malloc(end - off + 1);
	int64_t readL = (int64_t) read(fd, (void*) ptr, end - off);
	if (readL == 0) { //If there's no data
		printf("No data has been appended. Append a string and run again.\n");
		return 1;
	}
	if (readL == -1) { //If the read length is negative (and/or an error occurs)
		printf("Error.\n");
		return 1;
	}
	printf("%.*s", (int) readL, ptr); //Print string truncated to the length read
	return 0;
}
