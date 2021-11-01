#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "./libft/libft.h"

// MY FUNCTION 

int	ft_printf(const char *format, ...)
{
	int		sum;
	va_list		 VaList;
	int		PrintInteger;
	char	 	*pPrintString;
	char		*IntegerString;
	size_t		HexaPrint;


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

	ft_printf("-----------------------TESTING THE STRING-----------------------\n");
	printf("Allo les amis, j'essaye ici d'introduire une phrase avec le VRAI PRINTF = %s\n", "THIS IS A STRING");
	ft_printf("Allo les amis, j'essaye ici d'introduire une phrase avec MON PRINTF = %s\n", "THIS IS A STRING");
	ft_printf("-----------------------TESTING THE INTEGER-----------------------\n");
	printf("Allo les amis, j'essaye ici d'introduire un INT  avec le VRAI PRINTF= %i\n", -23435567);
	ft_printf("Allo les amis, j'essaye ici d'introduire un INT avec MON PRINTF = %i\n", -23435567);
	ft_printf("-----------------------TESTING THE PERCENT-----------------------\n");
	printf("Allo les amis, j'essaye ici d'introduire un POURCENT avec le VRAI PRINTF= %%\n");
	ft_printf("Allo les amis, j'essaye ici d'introduire un POURCENT avec MON PRINTF = %%\n");
	ft_printf("-----------------------TESTING THE POINTER-----------------------\n");
	printf("This is me printing the adress of my pointer with the real printf = %p\n", ptr);
	printf("This is me printing the adress of my pointer with the real printf = %p\n", ptr2);	
	ft_printf("This is me printing the adress of my pointer with my ft_printf = %p\n", ptr);
	ft_printf("This is me printing the adress of my pointerwith my ft_printf  = %p\n", ptr2);


}
