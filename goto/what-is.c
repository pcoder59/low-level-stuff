#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc == 2) {
		goto print;
	}
	goto leave;

print:
	printf("We got two arguments\n");
leave:
	return 0;
}
