#include "main.h"

/**
 *read_textfile - ...
 *
 *@filename:...
 *@letters: ...
 *
 *Return: ...
 */


ssize_t read_textfile(const char *filename, size_t letters)
{

int fd = open(filename, O_RDONLY);
char *buf = (char *) malloc(letters);

ssize_t fwrite;
ssize_t fread;

if (!filename)
{
return (0);
}

if (fd == -1)
return (0);

if (!buf)
return (0);

fread = read(fd, buf, letters);
fwrite = write(STDOUT_FILENO, buf, fread);

free(buf);
close(fd);
return (fwrite);
}
