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

// MY FUNCTION 

int	ft_printf(const char *format, ...)
{
	int				sum;
	va_list		 	VaList;
	int				PrintInteger;
	int				PrintUnsignedInt;
	char	 		*pPrintString;
	char			*IntegerString;
	unsigned char	PrintChar;
	size_t			HexaPrint;


	sum = 0;
	va_start(VaList, format);
//	sum = ft_putstring_int((char *)format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while(*format)
			{
				if(*format == 'x')
				{
					HexaPrint = va_arg(VaList, int);
					ft_putnbro(HexaPrint, 16, "0123456789abcdef");	
					format++;
					break;
				}
				if(*format == 'X')
				{
					HexaPrint = va_arg(VaList, int);
					ft_putnbro(HexaPrint, 16, "0123456789ABCDEF");	
					format++;
					break;
				}
				if(*format == 'u')
				{
					PrintUnsignedInt = va_arg(VaList, int);
					IntegerString = ft_itoa(PrintUnsignedInt);
					ft_putstring(IntegerString);
					format++;
					sum +=  ft_strlen(IntegerString);
					break;
				}
				if(*format =='c')
				{
					PrintChar = va_arg(VaList, int);
					ft_putchar(PrintChar);
					format++;
					sum++;
					break;
				}
				if(*format == 's')
				{
					pPrintString = va_arg(VaList, char *);
					ft_putstring(pPrintString);
					format ++;
					sum += ft_strlen(pPrintString);
					break;
				}
				if(*format ==  'd' || *format == 'i')
				{
					PrintInteger = va_arg(VaList, int);
					IntegerString = ft_itoa(PrintInteger);
					ft_putstring(IntegerString);
					format++;
					sum += ft_strlen(IntegerString);
					break;
				}
				if(*format == 'p')
				{
					HexaPrint = va_arg(VaList, size_t);
					ft_putstring("0x");
					ft_putnbro(HexaPrint,16 , "0123456789abcdef");
					format++;
					break;
				}
				if(*format =='%')
				{
					ft_putchar('%');
					format++;
					sum++;
					break;
				}
				if(*format == '\0')
					break;
				else
				{
					ft_putchar('%');
					ft_putchar(*format);
					format++;
					sum +=2;
				}
			}
		}
		else
		{
			ft_putchar(*format);
			format++;
			sum++;
		}
	}
	va_end(VaList);
//	printf("Sum in my function is = %i\n", sum);
	return (sum);
}



int main(void)
{
	char	*ptr= {"ALLO POPA"};
	int 	*ptr2;
	ptr2 = NULL;

	ft_printf("-----------------------TESTING THE CHAR-----------------------\n");
	printf("Allo les amis, j'essaye ici d'introduire une phrase avec le VRAI PRINTF = %c\n", 'X');
	ft_printf("Allo les amis, j'essaye ici d'introduire une phrase avec MON PRINTF = %c\n", 'X');
	ft_printf("-----------------------TESTING THE STRING-----------------------\n");
	printf("Allo les amis, j'essaye ici d'introduire une phrase avec le VRAI PRINTF = %s\n", "THIS IS A STRING WITH AN É");
	ft_printf("Allo les amis, j'essaye ici d'introduire une phrase avec MON PRINTF = %s\n", "THIS IS A STRING WITH AN É");
	ft_printf("-----------------------TESTING THE INTEGER-----------------------\n");
	printf("Allo les amis, j'essaye ici d'introduire un INT  avec le VRAI PRINTF= %i\n", -23435567);
	ft_printf("Allo les amis, j'essaye ici d'introduire un INT avec MON PRINTF = %i\n", -23435567);
	ft_printf("-----------------------TESTING THE PERCENT-----------------------\n");
	printf("Allo les amis, j'essaye ici d'introduire un POURCENT avec le VRAI PRINTF= %%\n");
	ft_printf("Allo les amis, j'essaye ici d'introduire un POURCENT avec MON PRINTF = %%\n");
	ft_printf("-----------------------TESTING THE POINTER-----------------------\n");
	printf("This is me printing the adress of my pointer with the real printf = %p\n", ptr);
	ft_printf("This is me printing the adress of my pointer with my ft_printf = %p\n", ptr);
	printf("This is me printing the adress of my pointer with the real printf = %p\n", ptr2);	
	ft_printf("This is me printing the adress of my pointerwith my ft_printf  = %p\n", ptr2);
	ft_printf("-----------------------TESTING THE UNSIGNED INT-----------------------\n");
	printf("This is me trying to print a negative int with U 0 THE REAL PRINTF  = %u\n", -1);
	ft_printf("This is me trying to print a negative int with U with MY FT_PRINTF  = %u\n", -1);
	printf("This is me trying to print a standard int with U with THE REAL PRINTF  = %u\n", 7324);
	ft_printf("This is me trying to print a standard int with U with MY FT_PRINTF  = %u\n", 7324);
	ft_printf("-----------------------TESTING THE lowcap HEXA -----------------------\n");
	printf("This is me trying to print a standard int in HEXA with THE REAL PRINTF  = %x\n", 7324);
	ft_printf("This is me trying to print a standard int in HEXA with MY FT_PRINTF  = %x\n", 7324);
	ft_printf("-----------------------TESTING THE HIGHCAP HEXA -----------------------\n");
	printf("This is me trying to print a standard int in HEXA with THE REAL PRINTF  = %X\n", 7324);
	ft_printf("This is me trying to print a standard int in HEXA with MY FT_PRINTF  = %X\n", 7324);
}
