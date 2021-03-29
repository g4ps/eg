#ifndef EG_H
#define EG_H

#define E_BUFSIZ  128

#include <stdlib.h>

size_t e_strlen(const char *str);
size_t print_str(const char *str);
char   *read_line(int fd);

#endif
