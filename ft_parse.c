#include "./libft/libft.h"

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
				PrintInteger = va_arg(VaList, long long);
				if (PrintInteger < 0)
					PrintInteger = (4294967296 + PrintInteger);
				IntegerString = ft_itoa(PrintInteger);
				ft_putstring(IntegerString);
				format++;
				sum +=  ft_strlen(IntegerString);
				free (IntegerString);
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