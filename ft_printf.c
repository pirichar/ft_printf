#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

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
 * %% - to print a percent sign
 *
 * Bonus :
 * flag : -
 * flag : 0
 * flag : .
 *
 * video a ecouter : https://www.youtube.com/watch?v=Y9kUWsyyChk */

//HELPER FUNCTIONS
void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0 )
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putstring(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	if (n != 0)
	{
		while (i < n)
		{
			str[i] = '\0';
			i++;
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (str == NULL)
		return (0);
	ft_bzero(str, size * count);
	return (str);
}

static int	ft_char_count(int n)
{
	int	count;

	count = 2;
	if (n < 0)
	{
		count ++;
	}
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		count ++;
	}
	return (count);
}

static char	*ft_swap_neg(char *str)
{
	int	i;
	int	ri;
	int	size;
	int	temp;

	i = 0;
	size = ft_strlen((const char *)str);
	ri = ft_strlen((const char *)str) - 1;
	while (i < (size / 2))
	{
		temp = str[i];
		str[i] = str[ri];
		str[ri] = temp;
		i++;
		ri--;
	}
	return (str);
}

static char	*ft_swap(char *str)
{
	int	i;
	int	ri;
	int	size;
	int	temp;

	i = 0;
	size = ft_strlen((const char *)str);
	ri = ft_strlen((const char *)str) - 1;
	if (str[0] == '-')
		ft_swap_neg(str + 1);
	else
	{
		while (i < (size / 2))
		{
			temp = str[i];
			str[i] = str[ri];
			str[ri] = temp;
			i++;
			ri--;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*rtn;
	int		i;

	i = 0;
	rtn = ft_calloc(ft_char_count(n), sizeof(char));
	if (!rtn)
		return (NULL);
	if (n == 0)
	{
		rtn[0] = '0';
		i++;
	}
	if (n < 0)
	{
		rtn[i++] = '-';
		rtn[i++] = '0' - n % 10;
		n = n / -10;
	}
	while (n)
	{
		rtn[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	return (ft_swap(rtn));
}


// MY FUNCTION 

int	ft_printf(const char *format, ...)
{
	int		sum;
	va_list VaList;
	int		PrintInteger;
	char 	*pPrintString;
	char	*IntegerString;

	sum = 0;
	va_start(VaList, format);
//	sum = ft_putstring_int((char *)format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch(*format)
			{
				case 's':
					pPrintString = va_arg(VaList, char *);
					ft_putstring(pPrintString);
					format ++;
					sum += ft_strlen(pPrintString);
					break;

				case 'i':
					PrintInteger = va_arg(VaList, int);
					IntegerString = ft_itoa(PrintInteger);
					ft_putstring(IntegerString);
					format++;
					sum += ft_strlen(IntegerString);
					break;
				case '%':
					ft_putchar('%');
					format++;
					sum++;
					break;
				case '\0':
					break;
				default:
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
	va_end(VaList);
	printf("Sum in my function is = %i\n", sum);
	return (sum);
}



int main(void)
{
	
	ft_printf("Allo les amis\n j'essaye ici d'introduire une phrase %s\n", "LA DITE PHRASE");
}
