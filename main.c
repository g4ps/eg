#include <unistd.h>
#include "eg.h"


int main()
{
  print_str("Hello, my dear editor\n");
  char *buf = read_line(0);
  print_str(buf);
  free(buf);
  return 0;
}
