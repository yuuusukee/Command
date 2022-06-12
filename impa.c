#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	DIR *dir;
	FILE *fp;

	fp = fopen(argv[2],"w");
	fprintf(fp,argv[3]);
	fprintf(fp,"\n");
	struct dirent *ds;
	dir=opendir(argv[1]);
	for(ds = readdir(dir); ds != NULL; ds = readdir(dir) ){
		fprintf(fp,ds->d_name);
		fprintf(fp,"\n");
	}

	closedir(dir);
	fclose(fp);
	return 0;
}
