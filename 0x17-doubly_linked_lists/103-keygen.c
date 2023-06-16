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
char password[7];
char *charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
int input_length = strlen(argv[1]);
int i, temp;

temp = (input_length ^ 59) & 63;
password[0] = charset[temp];

temp = 0;
for (i = 0; i < input_length; i++)
temp += argv[1][i];
password[1] = charset[(temp ^ 79) & 63];

temp = 1;
for (i = 0; i < input_length; i++)
temp *= argv[1][i];
password[2] = charset[(temp ^ 85) & 63];

temp = 0;
for (i = 0; i < input_length; i++)
{
if (argv[1][i] > temp)
temp = argv[1][i];
}
srand(temp ^ 14);
password[3] = charset[rand() & 63];

temp = 0;
for (i = 0; i < input_length; i++)
temp += (argv[1][i] * argv[1][i]);
password[4] = charset[(temp ^ 239) & 63];

for (i = 0; i < argv[1][0]; i++)
temp = rand();
password[5] = charset[(temp ^ 229) & 63];

password[6] = '\0';

printf("%s\n", password);

return (0);
}
