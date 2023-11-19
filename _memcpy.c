#include "main.h"
/**
 * _memcpy - copies memory area
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 * Return: pointer to dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	const unsigned char *csrc = src;
	unsigned char *cdest = dest;

	for (i = 0; i < n; i++)
		cdest[i] = csrc[i];
	return (dest);
}
