#include "main.h"

/**
 *append_text_to_file - ...
 *
 *@filename: ...
 *@text_content: ...
 *
 *Return: ...
 */

int append_text_to_file(const char *filename, char *text_content)
{

ssize_t bytes_written;
int fd = open(filename, O_WRONLY | O_APPEND);
int content_len;

if (!filename)
{
return (-1);
}

if (fd == -1)
{
return (-1);
}

if (text_content)
{
for (content_len = 0; text_content[content_len]; content_len++)
;
bytes_written = write(fd, text_content, content_len);

if (bytes_written == -1)
{
return (-1);
}
}

close(fd);
return (1);
}
