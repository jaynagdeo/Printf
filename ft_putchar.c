#include "libftprintf.h"

int ft_putchar(int c)
{

//unsigned char c;
size_t nbytes = 1;
ssize_t bytes_written;
int fd = 1; //STDOUT
//strcpy(buf, "This is a test\n");
//nbytes = strlen(buf);

bytes_written = write(STDOUT_FILENO, (unsigned char)c, nbytes)

}
