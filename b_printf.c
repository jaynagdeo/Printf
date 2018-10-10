#include "libftprintf.h"


# include <stdio.h>
# include <string.h>
//decalre static

int ft_putchar(int c)
{
size_t nbytes = 1;
ssize_t bytes_written;

bytes_written = write(STDOUT_FILENO, &c, nbytes);

return c;
}

int ft_putoctal(unsigned int o)
{
size_t nbytes = 1;
ssize_t bytes_written;

bytes_written = write(STDOUT_FILENO, &c, nbytes);

return c;
}

int ft_putint(int c)
{
  int count = 0;
  int ct;
  int temp;
  char  *mem;
  ssize_t bytes_written;

  if (c == 0)
  {
    bytes_written = ft_putchar(c+'0');
    return c;
  }

  temp = c;

  while(temp != 0)
  {
    count++;
    temp=temp/10;
  }

  if (NULL == (mem = (char *)malloc(sizeof(char)*(count))))
      return -1;

  ct=count;
  temp = c;
  while(count-- != 0)
  {
    mem[count] = temp%10 + '0';
    temp=temp/10;
  }
  temp=0;
  while(temp != ct)
  {
    bytes_written = ft_putchar(mem[temp]);
    temp++;
  }

  free(mem);
  return c;
}

size_t ft_strlen(const char *s)
{
  unsigned int count = 0;
  const char *ptr;

    ptr = s;
    while (*ptr != '\0'){
        count++;
        ptr++;
      }
    return (count);
}

int ft_puts(const char *s)
{

size_t nbytes;
ssize_t bytes_written;
//int fd = 1; //STDOUT
//strcpy(buf, "This is a test\n");
nbytes = ft_strlen(s);

bytes_written = write(STDOUT_FILENO, s, nbytes);

return bytes_written;

}


void b_printf(const char *fmt, ...)
{
      va_list ap;
      int d;
      char c;
      const char  *s;
      int ret;
      unsigned int o;

     va_start(ap, fmt);
      while (*fmt)
          switch (*fmt++) {
          case 's':              /* string */
              s = va_arg(ap, const char *);
              //printf("string %s\n", s);
              ret = ft_puts(s);
              break;
          case 'd':              /* int */
              d = va_arg(ap, int);
              //printf("int %d\n", d);
              ret = ft_putint(d);
              break;

          case 'i':              /* int */
              d = va_arg(ap, int);
              //printf("int %d\n", d);
              ret = ft_putint(d);
              break;

          case 'c':              /* char */
              /* need a cast here since va_arg only
                 takes fully promoted types */
              c = (char) va_arg(ap, int);
              //printf("char %c\n", c);
              ret = ft_putchar(c);
              break;

          case ' ':              /* space */
              ret = ft_putchar(' ');
              break;
          }
      va_end(ap);
}


int main() {

//const char  *s = "Hello This is a test";
int ret;
  b_printf("%s %d","Hello",123);
  ret=ft_putchar('\n');
  //ret = ft_putint(1234);
  //printf("ret: %d\n", ret);
  return 0;
}
