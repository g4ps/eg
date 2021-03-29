#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "eg.h"

size_t e_strlen(const char *str)
{
  size_t ret = 0;

  if (str == NULL)
    return 0;
  while (str[ret] != '\0')
    ret++;
  return ret;
}

void* e_memcpy(void *dst, void *src, size_t n)
{
  char *d = dst;
  char *s = src;

  if (dst == NULL || src == NULL || n == 0)
    return NULL;
  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dst;
}

size_t print_str(const char *str)
{
  size_t len;

  len = e_strlen(str);
  return write(1, str, len);
}

char* read_line(int fd)
{
  char *buf;
  char *ret;
  size_t times;
  char *temp;

  ret = NULL;
  times = 0;
  buf = malloc(E_BUFSIZ + 1);
  if (buf == NULL)
    return NULL;
  ssize_t n;
  while ((n = read(fd, buf, E_BUFSIZ)) != 0) {
    if (n < 0) {
      free(ret);
      free(buf);
      return NULL;
    }
    buf[n] = '\0';
    temp = malloc(E_BUFSIZ * (times + 1) + 1);
    if (temp == NULL) {
      free(ret);
      free(buf);
      return NULL;
    }
    e_memcpy(temp, ret, E_BUFSIZ * times);
    e_memcpy(temp + E_BUFSIZ * times, buf, n + 1);
    free(ret);
    ret = temp;
    if (buf[n - 1] == '\n')
      break;
    times++;
  }
  free(buf);
  return ret;
}
