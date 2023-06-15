#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  generateKey - ...
 *
 * @username: ...
 *
 */

void generateKey(char *username)
{
printf("Key for %s: %s\n", username, generateKey);
}

/**
 * main - ...
 *
 * @argc: ...
 * @argv: ...
 *
 * Return: ...
 */

int main(int argc, char *argv[])
{
char *username = argv[1]; 
if (argc != 2)
 {
printf("Usage: %s username\n", argv[0]);
return (1);
}

generateKey(username);

return (0);
}
