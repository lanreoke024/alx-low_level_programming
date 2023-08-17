#include <stdio.h>
/**
 * main - prints alphabets in lower case
 *
 * Return: (0)
 *
 */
int main(void)
{
	char alphabets = 'a';

	while (alphabets <= 'z')
	{
		putchar(alphabets);
		alphabets++;
	}
	putchar('\n');
	return (0);
}
