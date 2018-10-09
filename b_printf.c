#include "libftprintf.h"


# include <stdio.h>
# include <string.h>
//decalre static

int ft_putchar(int c)
{

size_t nbytes = 1;
ssize_t bytes_written;
//int fd = 1; //STDOUT
//strcpy(buf, "This is a test\n");
//nbytes = strlen(buf);

bytes_written = write(STDOUT_FILENO, &c, nbytes);

return c;

}


void b_printf(const char *fmt, ...)
{
      va_list ap;
      int d;
      char c, *s;

     va_start(ap, fmt);
      while (*fmt)
          switch (*fmt++) {
          case 's':              /* string */
              s = va_arg(ap, char *);
              printf("string %s\n", s);
              break;
          case 'd':              /* int */
              d = va_arg(ap, int);
              printf("int %d\n", d);
              break;
          case 'c':              /* char */
              /* need a cast here since va_arg only
                 takes fully promoted types */
              c = (char) va_arg(ap, int);
              printf("char %c\n", c);
              break;
          }
      va_end(ap);
}


int main() {

char c = 'A';
int ret;
  //b_printf("%s %d","Hello",123);
  ret = ft_putchar(c);
  //printf("ret: %d\n", ret);
  return 0;
}
