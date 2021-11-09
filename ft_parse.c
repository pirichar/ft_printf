#include "./libft/libft.h"

void	ft_parse(const char **format, int *sum, va_list VaList)
{
	if(*format == 'x')
		ft_putnbro_rtn(va_arg(VaList, int), 16, "0123456789abcdef", &sum);	
	else if(*format == 'X')// I have to solve the negative hex
		ft_putnbro_rtn(va_arg(VaList, int), 16, "0123456789ABCDEF", &sum);	
	else if(*format == 'u')
		ft_putnbro_rtn(va_arg(VaList, unsigned int), 10, "0123456789", &sum);
	else if(*format =='c')
		(*sum) += ft_putchar_rtn(va_arg(VaList, int));
	else if(*format == 's')
		(*sum) += ft_putstring_rtn(va_arg(VaList, char *));
	else if(*format ==  'd' || *format == 'i')
		ft_putnbro_rtn_neg(va_arg(VaList, int), &sum);	
	else if(*format == 'p')
		ft_putnbro_rtn_pointer(va_arg(VaList, size_t), 16 , "0123456789abcdef", &sum);
	else if(*format =='%')
		(*sum) += ft_putchar_rtn('%');
	else if(*format == '\0') // pas nécessaire je crois 
		return;
	else
	{
		(*sum) += ft_putchar_rtn('%');
		(*sum) += ft_putchar_rtn(*format);
	}
			
}