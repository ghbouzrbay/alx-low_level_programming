#include "main.h"

/**
 *create_file - ...
 *
 *@filename: ...
 *@text_content: ...
 *
 *Return: ...
 */

int create_file(const char *filename, char *text_content)
{

int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

int bytes_written;
int content_len;

if (!filename)
{
return (-1);
}

if (fd == -1)
{
return (-1);
}

if (!text_content)
{
text_content = "";
}

for (content_len = 0; text_content[content_len]; content_len++)
;
bytes_written = write(fd, text_content, content_len);

if (bytes_written == -1)
{
return (-1);
}

close(fd);
return (1);
}
