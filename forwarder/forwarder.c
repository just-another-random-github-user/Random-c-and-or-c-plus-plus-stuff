//Yes, this is the only name I can think of for this.
//It forwards any runs of the program to a compile time declared path.
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
	#ifndef PATH
	#error Please add -DPATH="path/to/executable"
	#else
	argv[0]=(char*)"#PATH";
	execve(argv[0],argv,envp);
	#endif
	return 1;
}
