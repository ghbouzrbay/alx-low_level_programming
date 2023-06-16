#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
char password[7], *crypto;
int len = strlen(argv[1]), i, tmp;

crypto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

tmp = (len ^ 59) & 63;
password[0] = crypto[tmp];

tmp = 0;
for (i = 0; i < len; i++)
tmp += argv[1][i];
password[1] = crypto[(tmp ^ 79) & 63];

tmp = 1;
for (i = 0; i < len; i++)
tmp *= argv[1][i];
password[2] = crypto[(tmp ^ 85) & 63];

tmp = 0;
for (i = 0; i < len; i++)
{
if (argv[1][i] > tmp)
tmp = argv[1][i];
}
srand(tmp ^ 14);
password[3] = crypto[rand() & 63];

tmp = 0;
for (i = 0; i < len; i++)
tmp += (argv[1][i] * argv[1][i]);
password[4] = crypto[(tmp ^ 239) & 63];

for (i = 0; i < argv[1][0]; i++)
tmp = rand();
password[5] = crypto[(tmp ^ 229) & 63];

password[6] = '\0';
printf("%s", password);
return (0);
}
