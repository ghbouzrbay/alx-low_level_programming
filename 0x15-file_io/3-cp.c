#include "main.h"

/**
 *error_file - ...
 *
 *@file_from: ...
 *@file_to: ...
 *@argv: ...
 *
 */


void error_file(int file_from, int file_to, char *argv[])
{

if (file_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

if (file_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
}

/**
 * main - ...
 *
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 *Return: ...
 */
int main(int argc, char *argv[])
{
char buffer[1024];
int file_from;
int file_to;
int errorclose;
ssize_t bytes_read, bytes_written;
if (argc != 3)
{
dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
exit(97);
}
file_from = open(argv[1], O_RDONLY);
file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
error_file(file_from, file_to, argv);
bytes_read = 1024;
do {
bytes_read = read(file_from, buffer, bytes_read);
if (bytes_read == -1)
error_file(-1, 0, argv);

bytes_written = write(file_to, buffer, bytes_read);
if (bytes_written == -1)
error_file(0, -1, argv);

} while (bytes_read == 1024);
errorclose = close(file_from);
if (errorclose == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
exit(100);
}
errorclose = close(file_to);
if (errorclose == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
exit(100);
}
return (0);
}
