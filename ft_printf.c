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
 * %c - ASCII Character ;To print a single Char; Works with char and unsigned char
 * %s - To print a whole string ; Works with char * char[]
 * %p - The void * pointer printed in hexa prendre ; works with pointers
 * %d - to print a decimal (base 10) integer; works with int
 * %i - to print an integer in base 10
 * %u - To print an unsigned decimal (base 10) number; works with unsigned int;
 * %x - to print a number in hexadecimal lowcase, works with : short, unsigned short, unsigned int, int
 * %X - to print a number in hexadecimal upcase, works with : short, unsigned short, unsigned int, int
 * %% - to print a percent sign 
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
/*
int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == 0 || base[1] == 0)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = 1;
		while (base[i + j])
		{
			if (base[i] == base[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		baseCount;
	long	n;

	n = nbr;
	baseCount = ft_strlen(base);
	if (ft_checkbase(base) == 0)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= baseCount)
		{
			ft_putnbr_base(n / baseCount, base);
			ft_putnbr_base(n % baseCount, base);
		}
		else
			ft_putchar(base[n]);
	}
}*/

void ft_putnbro(size_t num, size_t base_len, char *base)
{
    char c;

    if(num >= base_len)
        ft_putnbro(num / base_len,  base_len, base);
    c = base[(num % base_len)];
    write(1, &c, 1);
}


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
			switch(*format)
			{
				case 's':
					pPrintString = va_arg(VaList, char *);
					ft_putstring(pPrintString);
					format ++;
					sum += ft_strlen(pPrintString);
					break;
				case 'd':
				case 'i':
					PrintInteger = va_arg(VaList, int);
					IntegerString = ft_itoa(PrintInteger);
					ft_putstring(IntegerString);
					format++;
					sum += ft_strlen(IntegerString);
					break;
				case 'p':
					HexaPrint = va_arg(VaList, size_t);
					ft_putstring("0x");
					ft_putnbro(HexaPrint,16 , "0123456789abcdef");
					format++;
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
//	printf("Sum in my function is = %i\n", sum);
	return (sum);
}



int main(void)
{
	ft_printf("-----TESTING THE STRING-----\n");
	ft_printf("Allo les amis, j'essaye ici d'introduire une phrase = %s\n", "THIS IS A STRING");
	ft_printf("-----TESTING THE INTEGER-----\n");
	ft_printf("Allo les amis, j'essaye ici d'introduire un INT = %i\n", -23435567);
	ft_printf("-----TESTING THE PERCENT-----\n");
	ft_printf("Allo les amis, j'essaye ici d'introduire un POURCENT = %%\n");

	char	*ptr= {"ALLO POPA"};
	int 	*ptr2;

	//ptr = NULL;
	ptr2 = NULL;
	printf("This is me printing the adress of my pointer with the real printf = %p\n", ptr);
	printf("This is me printing the adress of my pointer with the real printf = %p\n", ptr2);	
	ft_printf("-----TESTING THE POINTER-----\n");
	ft_printf("This is me printing the adress of my pointer with my ft_printf = %p\n", ptr);
	ft_printf("This is me printing the adress of my pointerwith my ft_printf  = %p\n", ptr2);


}
