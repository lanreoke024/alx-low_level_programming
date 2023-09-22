#include <unistd.h>

/**
 * _putchar - write the character c to stdout
 * @C: The character to print
 *
 * Return: On succes 1.
 * On error, -1 is returned, and error is set appropiately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
