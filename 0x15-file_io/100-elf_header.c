#include "elf.h"


/**
 * check_ELF - ...
 * @identifier: ...
 *
 */

void check_ELF(unsigned char *identifier)
{
int current;

for (current = 0; current < 4; current++)
{
      if (identifier[current] != 127 &&
	  identifier[current] != 'E' &&
	  identifier[current] != 'L' &&
	  identifier[current] != 'F')
	{
	  dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
	  exit(98);
	}
    }
}

/**
 * ELF_magic - ...
 * @identifier: ...
 *
 */
void ELF_magic(unsigned char *identifier)
{
  int current;

  printf("  Magic:   ");

  for (current = 0; current < EI_NIDENT; current++)
    {
      printf("%02x", identifier[current]);

      if (current == EI_NIDENT - 1)
	printf("\n");
      else
	printf(" ");
    }
}

/**
 * ELF_class - ...
 * @identifier: ...
 */

void ELF_class(unsigned char *identifier)
{
  printf("  Class:                             ");

  switch (identifier[EI_CLASS])
    {
    case ELFCLASSNONE:
      printf("none\n");
      break;
    case ELFCLASS32:
      printf("ELF32\n");
      break;
    case ELFCLASS64:
      printf("ELF64\n");
      break;
    default:
      printf("<unknown: %x>\n", identifier[EI_CLASS]);
    }
}

/**
 * ELF_data - ...
 * @identifier: ...
 */
void ELF_data(unsigned char *identifier)
{
  printf("  Data:                              ");

  switch (identifier[EI_DATA])
    {
    case ELFDATANONE:
      printf("none\n");
      break;
    case ELFDATA2LSB:
      printf("2's complement, little endian\n");
      break;
    case ELFDATA2MSB:
      printf("2's complement, big endian\n");
      break;
    default:
      printf("<unknown: %x>\n", identifier[EI_CLASS]);
    }
}

/**
 * ELF_version - ...
 * @identifier: ...
 */

void ELF_version(unsigned char *identifier)
{
  printf("  Version:                           %d",
	 identifier[EI_VERSION]);

  switch (identifier[EI_VERSION])
    {
    case EV_CURRENT:
      printf(" (current)\n");
      break;
    default:
      printf("\n");
      break;
    }
}

/**
 * ELF_osabi - ...
 * @identifier: ...
 */

void ELF_osabi(unsigned char *identifier)
{
  printf("  OS/ABI:                            ");

  switch (identifier[EI_OSABI])
    {
    case ELFOSABI_NONE:
      printf("UNIX - System V\n");
      break;
    case ELFOSABI_HPUX:
      printf("UNIX - HP-UX\n");
      break;
    case ELFOSABI_NETBSD:
      printf("UNIX - NetBSD\n");
      break;
    case ELFOSABI_LINUX:
      printf("UNIX - Linux\n");
      break;
    case ELFOSABI_SOLARIS:
      printf("UNIX - Solaris\n");
      break;
    case ELFOSABI_IRIX:
      printf("UNIX - IRIX\n");
      break;
    case ELFOSABI_FREEBSD:
      printf("UNIX - FreeBSD\n");
      break;
    case ELFOSABI_TRU64:
      printf("UNIX - TRU64\n");
      break;
    case ELFOSABI_ARM:
      printf("ARM\n");
      break;
    case ELFOSABI_STANDALONE:
      printf("Standalone App\n");
      break;
    default:
      printf("<unknown: %x>\n", identifier[EI_OSABI]);
    }
}

/**
 * ELF_abi - ...
 * @identifier: ...
 */

void ELF_abi(unsigned char *identifier)
{
  printf("  ABI Version:                       %d\n",
	 identifier[EI_ABIVERSION]);
}

/**
 * ELF_type - ... 
 * @identifier: ...
 * @type: ...
 */
void ELF_type(unsigned int type, unsigned char *identifier)
{
  if (identifier[EI_DATA] == ELFDATA2MSB)
    type >>= 8;

  printf("  Type:                              ");

  switch (type)
    {
    case ET_NONE:
      printf("NONE (None)\n");
      break;
    case ET_REL:
      printf("REL (Relocatable file)\n");
      break;
    case ET_EXEC:
      printf("EXEC (Executable file)\n");
      break;
    case ET_DYN:
      printf("DYN (Shared object file)\n");
      break;
    case ET_CORE:
      printf("CORE (Core file)\n");
      break;
    default:
      printf("<unknown: %x>\n", type);
    }
}

/**
 * ELF_entry - ...
 * @identifier: ...
 * @entry: ...
 */

void ELF_entry(unsigned long int entry, unsigned char *identifier)
{
  printf("  Entry point address:               ");

  if (identifier[EI_DATA] == ELFDATA2MSB)
    {
      entry = ((entry << 8) & 0xFF00FF00) |
	((entry >> 8) & 0xFF00FF);
      entry = (entry << 16) | (entry >> 16);
    }

  if (identifier[EI_CLASS] == ELFCLASS32)
    printf("%#x\n", (unsigned int)entry);

  else
    printf("%#lx\n", entry);
}

/**
 * close_ELF - ...
 * @elf: ...
 *
 */
void close_ELF(int elf)
{
  if (close(elf) == -1)
    {
      dprintf(STDERR_FILENO,
	      "Error: Can't close fd %d\n", elf);
      exit(98);
    }
}

/**
 * main - ...
 *
 * @argc: The number of arguments
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
  Elf64_Ehdr *header;
  int f_open, f_read;

  f_open = open(argv[1], O_RDONLY);
  if (f_open == -1)
    {
      dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
      exit(98);
    }
  header = malloc(sizeof(Elf64_Ehdr));
  if (header == NULL)
    {
      close_ELF(f_open);
      dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
      exit(98);
    }
  f_read = read(f_open, header, sizeof(Elf64_Ehdr));
  if (f_read == -1)
    {
      free(header);
      close_ELF(f_open);
      dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
      exit(98);
    }

  check_ELF(header->e_ident);
  printf("ELF Header:\n");
  ELF_magic(header->e_ident);
  ELF_class(header->e_ident);
  ELF_data(header->e_ident);
  ELF_version(header->e_ident);
  ELF_osabi(header->e_ident);
  ELF_abi(header->e_ident);
  ELF_type(header->e_type, header->e_ident);
  ELF_entry(header->e_entry, header->e_ident);

  free(header);
  close_ELF(f_open);
  return (0);
}
