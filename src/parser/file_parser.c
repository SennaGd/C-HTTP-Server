#include <stdio.h>
void read_file() {
	FILE *fptr = NULL;	
	
	fptr = fopen("html/index.html", "r");
	if (fptr == NULL) {
		printf("error reading file");
	}
	
	char file_buf[256];

	while(fgets(file_buf, 256, fptr)) {
		printf("%s", file_buf);
	}

	fclose(fptr);

	return;
}
