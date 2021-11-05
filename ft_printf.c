#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "./libft/libft.h"

/*External functions permitted :
 * malloc, free, write, va_start, va_arg, va_copy, va_end
 *
 * Conversions to manage :
 * %c - ASCII Character ;To print a single Char; Works with char and unsigned char - CHECKED **
 * %s - To print a whole string ; Works with char * char[]   - CHECKED
 * %p - The void * pointer printed in hexa prendre ; works with pointers - CHECKED
 * %d - to print a decimal (base 10) integer; works with int - CHECKED
 * %i - to print an integer in base 10   - CHECKED 
 * %u - To print an unsigned decimal (base 10) number; works with unsigned int;  - DONE NOT TOTALLY WORKING THO **
 * %x - to print a number in hexadecimal lowcase, works with : short, unsigned short, unsigned int, int - CHECKED
 * %X - to print a number in hexadecimal upcase, works with : short, unsigned short, unsigned int, int - CHECKED
 * %% - to print a percent sign  - CHECKED **
 *
 * Bonus :
 * MUST WORK TOGETHER
 * flag : -   ; LEFT JUSTIFY
 * flag : 0   ; PAD WITH LEADING ZEROS
 * flag : .	  ;
 *
 *WORK ALONE
 * flag : #	;imprimer 0x devant les HEX
 * flag : + ; ALWAYS DISPLAY SIGN
 * 
 * flag width.precision
 * Width  specifies the minimum number of characters to display
 * Precision specifies the number of digits to display after decimal point
 * video a ecouter : https://www.youtube.com/watch?v=Y9kUWsyyChk 
 * video a ecouter : https://www.youtube.com/watch?v=nXuMuzgtsNw&t=556s */

int	ft_printf(const char *format, ...)
{
	int				sum;
	va_list		 	VaList;
	int				PrintInteger;
	char	 		*pPrintString;
	char			*IntegerString;
	unsigned char	PrintChar;
	size_t			HexaPrint;


	sum = 0;
	va_start(VaList, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format == 'x')
			{
				HexaPrint = va_arg(VaList, int);
				ft_putnbro_rtn(HexaPrint, 16, "0123456789abcdef", &sum);	
				format++;
			}
			else if(*format == 'X')
			{
				HexaPrint = va_arg(VaList, int);
				ft_putnbro_rtn(HexaPrint, 16, "0123456789ABCDEF", &sum);	
				format++;
			}
			else if(*format == 'u')
			{
				PrintInteger = va_arg(VaList, int);
				printf("PrintInterger is = %i\n", PrintInteger);
				IntegerString = ft_itoa(PrintInteger);
				ft_putstring(IntegerString);
				format++;
				sum +=  ft_strlen(IntegerString);
				free (IntegerString);
				//To do : fix the fac that it cant be a negative
			}
			else if(*format =='c')
			{
				PrintChar = va_arg(VaList, int);
				ft_putchar(PrintChar);
				format++;
				sum++;
			}
			else if(*format == 's')
			{
				pPrintString = va_arg(VaList, char *);
				ft_putstring(pPrintString);
				format ++;
				sum += ft_strlen(pPrintString);
			}
			else if(*format ==  'd' || *format == 'i')
			{
				PrintInteger = va_arg(VaList, int);
				IntegerString = ft_itoa(PrintInteger);
				ft_putstring(IntegerString);
				format++;
				sum += ft_strlen(IntegerString);
				free (IntegerString);
			}
			else if(*format == 'p')
			{
				HexaPrint = va_arg(VaList, size_t);
				ft_putstring("0x");
				sum +=2;
				ft_putnbro_rtn(HexaPrint, 16 , "0123456789abcdef", &sum);
				format++;
			}
			else if(*format =='%')
			{
				ft_putchar('%');
				format++;
				sum++;
			}
			else if(*format == '\0')
					break;
			else
			{
				ft_putchar('%');
				ft_putchar(*format);
				format++;
				sum +=2;
			}
		}
		else
		{
			ft_putchar(*format);
			format++;
			sum++;
		}
	}
	va_end(VaList);	return (sum);
}