#include "stdio.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

struct stat attributes;

int main(int argc, char const *argv[]) 
{
   	if(argc != 3)return -1;
   
	const char* old = argv[1];
   	const char* new = argv[2];
   
	int fpa = open(old, O_RDONLY);
   	if(fpa < 0)
	{
       		printf("Fehler beim Öffnen des Textfiles!\n");
  	     	return -1;
	}
   	
	int size = lseek(fpa, 0, SEEK_END);
	char* buff[size];
   	lseek(fpa, 0, SEEK_SET);
   	read(fpa, buff, sizeof(buff));
   	
  	int fpb = open(new, O_WRONLY);
   	if(fpb < 0)
	{
    		fpb = open(new, O_CREAT | O_WRONLY);
   	}

	int check = write(fpb, buff, size);
   	if(check != size)
	{
		printf("Fehler beim Kopieren des Textfiles!\n");
		return -1;
	}
	close(fpa);
   	close(fpb);
   	return 0;
}
