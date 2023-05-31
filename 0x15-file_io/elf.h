#ifndef ELF_H
#define ELF_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



/******FUNCTION********/


void check_ELF(unsigned char *idetifier);
void ELF_magic(unsigned char *idetifier);
void ELF_class(unsigned char *idetifier);
void ELF_data(unsigned char *idetifier);
void ELF_version(unsigned char *idetifier);
void ELF_abi(unsigned char *idetifier);
void ELF_osabi(unsigned char *idetifier);
void ELF_type(unsigned int type, unsigned char *idetifier);
void ELF_entry(unsigned long int entry, unsigned char *idetifier);
void close_ELF(int elf);
int main(int __attribute__((__unused__)) argc, char *argv[]);

#endif
