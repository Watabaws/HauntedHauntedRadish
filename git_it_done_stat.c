#include <stdio.h>
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

char * ret_perms(int mode){
	if(mode >> 1 == mode >> 1 << 1)
	char * oct_mode;
	sprintf(oct_mode, "%o", mode);
	while(mode){
		if(oct_mode[strlen(oct_mode) - 1] == '7'){
			return strcat(ret_perms(mode / 10), "rwx");
		}
		else if(oct_mode[strlen(oct_mode) - 1] == '6'){
			return strcat(ret_perms(mode/10), "rw-");
		}
		else if(oct_mode[strlen(oct_mode) - 1] == '5'){
			return strcat(ret_perms(mode/10), "r-x");
		}
		else if(oct_mode[strlen(oct_mode) - 1] == '4'){
			return strcat(ret_perms(mode/10), "r--");
		}
		else if(oct_mode[strlen(oct_mode) - 1] == '3'){
			return strcat(ret_perms(mode/10), "-wx");
		}
		else if(oct_mode[strlen(oct_mode) - 1] == '2'){
			return strcat(ret_perms(mode/10), "-w-");
		}
		else if(oct_mode[strlen(oct_mode) - 1] == '1'){
			return strcat(ret_perms(mode/10), "--x");
		}
		else{
			return "-";
		}

	}
}



int main(){
	printf("Printing out stats for git_it_done_stat.c [this one :)]\n\n");

	struct stat matadeta;
	stat("git_it_done_stat.c", &matadeta);

	printf("The size is: %ld\n", matadeta.st_size);
	printf("The mode/permissions are: %o\n", matadeta.st_mode);
	printf("The time of last access is: %s\n", ctime(&matadeta.st_atime));

	printf("Here's some nicer formatting:\n\n");
	char size[256];

	printf("The size of the file is %s\n", checksize(matadeta.st_size));
	printf("The permissions for this file are: %s", ret_perms(matadeta.st_mode));



}
