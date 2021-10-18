#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/*program name libftprintf.a
Turn in files :*.c, **.c, *.h, **.h, Makefile
Makefile :all, clean, fclean, re, bonus
External functs: 
malloc, 
free, 
write,
va_start,
va_arg,
va_copy,va_end
Libft authorized yes
Description Write a library that contains ft_printf, a function
that will mimic the real printf
A small description of the required conversion:
• %c print a single character.
• %s print a string of characters.
• %p The void * pointer argument is printed in hexadecimal. • %d print a decimal (base 10) number
• %i print an integer in base 10.
• %u print an unsigned decimal (base 10) number.
• %x print a number in hexadecimal (base 16), with lowercase. • %X print a number in hexadecimal (base 16), with uppercase. • %% print a percent sign.
*/

int ft_printf(const char *format, ...)
{
    int sum;
    int i;
    char *output;

    sum = 0;
    i = 0;
    va_list argptr;

    va_start(argptr, format);
    while(format)
    {
	    output = va_arg(argptr, char *);
	    output++;
    }
    va_end(argptr);
    return (sum);

}

int main(int argc, char *argv[])
{

	return (0);

}

