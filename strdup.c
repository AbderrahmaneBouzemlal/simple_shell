#include "main.h"
char *_strdup (const char *s)
{
  size_t len = _strlen(s) + 1;
  void *new = malloc (len);
  if (new == NULL)
    return NULL;
  return (char *) memcpy (new, s, len);
}
