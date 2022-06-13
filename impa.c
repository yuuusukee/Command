#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include<string.h>

static void dir_error(){
	printf("Directory not found");
	exit(0);
}
static void argument_error(){
	printf("Please specify 3 arguments\n");
	exit(0);
}
int main(int argc, char* argv[]){
	DIR *dir;
	FILE *fp;
	if(argc != 4){
		argument_error();
	}
	char* ref_der = argv[1];
	char* gen_file = argv[2];
	char* column_name = argv[3];
	fp = fopen(gen_file,"w");

	fprintf(fp,column_name);
	fprintf(fp,"\n");
	struct dirent *ds;
	dir=opendir(ref_der);
	if(dir == 0){
		dir_error();
	}
	for(ds = readdir(dir); ds != NULL; ds = readdir(dir) ){
		printf("%s",ds[0]);
		if(strcmp(ds->d_name[0],".")==1 || strcmp(ds->d_name,"..")==1){
			fprintf(fp,ds->d_name);
			fprintf(fp,"\n");
		}
	}

	closedir(dir);
	fclose(fp);
	return 0;
}
