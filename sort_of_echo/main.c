#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifndef FILE_SIZE
#error File size undefined.
#define FILE_SIZE 0
#endif

int main(int argc, char** argv, char** envp) {
	int fd = open("/proc/self/exe", O_RDONLY);
	int64_t end = (int64_t)lseek(fd, 0, SEEK_END);
	int64_t off = (int64_t)lseek(fd, FILE_SIZE, SEEK_SET);
	char* ptr = (char*) malloc(end - off + 1);
	int64_t readL = (int64_t) read(fd, (void*) ptr, end - off);
	if (readL == 0) { //No data
		printf("No data has been appended. Append a string and run again.\n");
		return 1;
	}
	if (readL == -1) { //Error
		printf("Error.\n");
		return 1;
	}
	ssize_t writeL = 0;
	ssize_t temp = 0;
	while (writeL < readL) { //So as to retry if EINTR or reaches write limit
		temp = write(1,ptr+writeL,readL-writeL);
		if (temp == -1) {
			if (errno == EINTR) continue;
			return 1; //Not much else you can do
		}
		writeL += temp;
	}
	return 0;
}
