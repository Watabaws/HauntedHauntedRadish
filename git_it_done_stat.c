#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

char * checksize(long o_size){
  	char * size;
	int og_size = o_size;
	if(!(og_size % 1000000000)){
		sprintf(size, "%dGB ", og_size % 1000000000);
		return strcat(size, checksize(og_size / 1000));
	}
	if(!(og_size % 1000000)){
		sprintf(size, "%dMB ", og_size % 1000000);
		return strcat(size, checksize(og_size / 1000));
	}
	if(!(og_size % 1000)){
		sprintf(size, "%dKB ", og_size % 1000);
		return strcat(size, checksize(og_size / 1000));
	}
	else{
		sprintf(size, "%dB", og_size);
		return size;
	}

}

int check_shift(int mode){
	int shifted = mode >> 1;
	int shifted_back = shifted << 1;

	return !(shifted == shifted_back);
}

char * ret_perms(int mode){
	char * perms = (char*)malloc(10);
	perms[10] = 0;

	if(check_shift(mode)){
		perms[9] = 'x';
	}
	else perms[9] = '-';
	mode = mode >> 1;

	if(check_shift(mode)){
		perms[8] = 'w';
	} 
	else perms[8] = '-';
	mode = mode >> 1;

	if(check_shift(mode)){
		perms[7] = 'r';
	}
	else perms[7] = '-';
	mode = mode >> 1;

	if(check_shift(mode)){
		perms[6] = 'x';
	}
	else perms[6] = '-';
	mode = mode >> 1;

	if(check_shift(mode)){
		perms[5] = 'w';
	} 
	else perms[5] = '-';
	mode = mode >> 1;

	if(check_shift(mode)){
		perms[4] = 'r';
	}
	else perms[4] = '-';
	mode = mode >> 1;

	if(check_shift(mode)){
		perms[3] = 'x';
	}
	else perms[3] = '-';
	mode = mode >> 1;

	if(check_shift(mode)){
		perms[2] = 'w';
	} 
	else perms[2] = '-';
	mode = mode >> 1;

	if(check_shift(mode)){
		perms[1] = 'r';
	}
	else perms[1] = '-';

	perms[0] = '-';

	return perms;
}





int main(){
	printf("Printing out stats for git_it_done_stat.c [this one :)]\n\n");

	struct stat matadeta;
	stat("git_it_done_stat.c", &matadeta);

	printf("The size is: %ld\n", matadeta.st_size);
	printf("The mode/permissions are: %o\n", matadeta.st_mode);
	printf("The time of last access is: %s\n", ctime(&matadeta.st_atime));

	printf("Here's some nicer formatting:\n\n");

	printf("The size of the file is %s\n", checksize(matadeta.st_size));
	printf("The permissions for this file are: %s\n", ret_perms(matadeta.st_mode));



}
