#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/*External functions permitted :
 * malloc, free, write, va_start, va_arg, va_copy, va_end
 *
 * Conversions to manage :
 * %c - To print a single Char
 * %s - To print a whole string
 * %p - The void * pointer printed in hexa
 * %d - to print a decimal (base 10) number
 * %i - to print an integer in base 10
 * %u - To print an unsigned decimal (base 10) number
 * %x - to print a number in hexadecimal (base 16), with lowercase
 * %X - to print a number in hexadecimal (base 16, with uppercase
 * %% - to print a percent sign*/

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_putstring_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int	sum;
	va_list ap;

	sum = 0;
	va_start(ap, format);
	//in case its just a string 
	sum = ft_putstring_int((char *)format);
	format++;

	//
	va_end(ap);
	printf("Sum in my function is = %i\n", sum);
	return (sum);
}



int main(void)
{
	
	ft_printf("Allo les amis\n");
}
