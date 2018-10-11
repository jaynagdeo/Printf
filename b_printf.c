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
  int count = 0;
  int ct;
  int temp;
  char  *mem;
  ssize_t bytes_written;

  if (o == 0)
  {
    bytes_written = ft_putchar(o+'0');
    return o;
  }

  temp = o;

  while(temp != 0)
  {
    count++;
    temp=temp/8;
  }

  if (NULL == (mem = (char *)malloc(sizeof(char)*(count))))
      return -1;

  ct=count;
  temp = o;
  while(count-- != 0)
  {
    mem[count] = temp%8 + '0';
    temp=temp/8;
  }
  temp=0;
  while(temp != ct)
  {
    bytes_written = ft_putchar(mem[temp]);
    temp++;
  }

  free(mem);
  return o;
}


int ft_putint(int c)
{
  int count = 0;
  int ct;
  int temp;
  int neg = 0;
  char  *mem;
  ssize_t bytes_written;

  if (c == 0)
  {
    bytes_written = ft_putchar(c+'0');
    return c;
  }

  if(c<0)
  {
    count++;
    c*=-1;
    neg=1;
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

  if (neg == 0)
  {
    while(temp != ct)
    {
      bytes_written = ft_putchar(mem[temp]);
      temp++;
    }
  }
  else
  {
    mem[0] = '-';
    while(temp != ct)
    {
      bytes_written = ft_putchar(mem[temp]);
      temp++;
    }
  }

  free(mem);
  return c;
}

int ft_putunsignedint(unsigned int c)
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


int ft_puthex(unsigned int c)
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
    temp=temp/16;
  }

  if (NULL == (mem = (char *)malloc(sizeof(char)*(count))))
      return -1;

  ct=count;
  temp = c;
  while(count-- != 0)
  {
    if(temp%16 < 10)
      mem[count] = temp%16 + '0';
    else
    {
      mem[count] = (temp%16 - 10) + 'a';
    }

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


int ft_puthexl(unsigned long c)
{
  int count = 0;
  int ct;
  unsigned long temp;
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
    temp=temp/16;
  }

  if (NULL == (mem = (char *)malloc(sizeof(char)*(count))))
      return -1;

  ct=count;
  temp = c;
  while(count-- != 0)
  {
    if(temp%16 < 10)
      mem[count] = temp%16 + '0';
    else
    {
      mem[count] = (temp%16 - 10) + 'a';
    }

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

// int ft_putp(void *c)
// {
//   int ret;
//   unsigned long *temp = c;
//
//   ret = ft_puthexl(*temp);
//
//   return ret;
// }

// int ft_putp(unsigned long c)
// {
//   int ret;
//   // unsigned long *temp = c;
//
//   ret = ft_puthexl(c);
//
//   return ret;
// }

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
      unsigned long ul;

     va_start(ap, fmt);
      while (*fmt)
          switch (*fmt++) {
          case 's':              /* string */
              s = va_arg(ap, const char *);
              ret = ft_puts(s);
              break;
          case 'd':              /* int */
              d = va_arg(ap, int);
              ret = ft_putint(d);
              break;

          case 'i':              /* int */
              d = va_arg(ap, int);
              ret = ft_putint(d);
              break;

          case 'c':              /* char */
              /* need a cast here since va_arg only
                 takes fully promoted types */
              c = (char) va_arg(ap, int);
              ret = ft_putchar(c);
              break;
          case 'o':              /* octal */

            o = va_arg(ap, unsigned int);
            ret = ft_putchar(o);
            break;

          case 'u':              /* unsigned int */

            o = va_arg(ap, unsigned int);
            ret = ft_putunsignedint(o);
            break;

          case 'x':              /* hex */

            o = va_arg(ap, unsigned int);
            ret = ft_puts("0x");
            ret = ft_puthex(o);
            break;

          case 'p':              /* pointer */

            ul = (unsigned long) va_arg(ap, void *);
            ret = ft_puts("0x");
            ret = ft_puthexl(ul);
            break;

          case ' ':              /* space */
              ret = ft_putchar(' ');
              break;
          }
      va_end(ap);
}


int main() {

//const char  *s = "Hello This is a test";
//int ret;
unsigned int t=123;
// unsigned int te;
// *te = &t;

  b_printf("%p",&t);
  //ret=ft_puthex(*te);
  //ret = ft_putint(1234);
  //printf("%p\n", &temp);
  //ret=ft_putp(&t);
  // b_printf("%p",&t);
   printf("\n%p\n", &t);
  return 0;
}
