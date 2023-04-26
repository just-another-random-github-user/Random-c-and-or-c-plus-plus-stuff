#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		return 1; //No arguments passed
	}
	if (argc == 2) {
		printf("%s is not meant to be run.\n", argv[1]);
		return 1; //One argument passed (filename)
	}
	if (argc == 3) {
		printf("%s %s\n", argv[2], argv[1]);
		return 1; //Two args passed (message, filename)
	}
	return 1;
}
