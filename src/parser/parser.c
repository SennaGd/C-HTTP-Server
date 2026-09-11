#include <stdio.h>
void read_file() {
	FILE *fptr = NULL;	
	
	fptr = fopen("html/index.html", "r");
	if (fptr == NULL) {
		printf("error reading file");
	}
	
	char file_buf[100];

	while(fgets(file_buf, sizeof(file_buf), fptr)) {
		printf("%s", file_buf);
	}

	fclose(fptr);

	return;
}
