/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:13:59 by pirichar          #+#    #+#             */
/*   Updated: 2021/11/09 16:18:15 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static void	ft_parse(char **format, int *sum, va_list va_list)
{
	(*format)++;
	if(**format == 'x')
		ft_putnbro_rtn(va_arg(va_list, unsigned long long), 16, "0123456789abcdef", sum);	
	else if(**format == 'X')// I have to solve the negative hex
		ft_putnbro_rtn(va_arg(va_list, unsigned long long), 16, "0123456789ABCDEF", sum);	
	else if(**format == 'u')
		ft_putnbro_rtn(va_arg(va_list, unsigned int), 10, "0123456789", sum);
	else if(**format =='c')
		(*sum) += ft_putchar_rtn(va_arg(va_list, int));
	else if(**format == 's')
		(*sum) += ft_putstring_rtn(va_arg(va_list, char *));
	else if(**format ==  'd' || **format == 'i')
		ft_putnbro_rtn_neg(va_arg(va_list, int), sum);	
	else if(**format == 'p')
		ft_putnbro_rtn_pointer(va_arg(va_list, unsigned long long), 16 , "0123456789abcdef", sum);
	else if(**format =='%')
		(*sum) += ft_putchar_rtn('%');
	else if(**format == '\0') // pas nécessaire je crois 
		return;
	else
	{
		(*sum) += ft_putchar_rtn('%');
		(*sum) += ft_putchar_rtn(**format);
	}		
}

int	ft_printf(const char *format, ...)
{
	int				sum;
	va_list		 	va_list;

	sum = 0;
	va_start(va_list, format);
	while (*format)
	{
		if (*format == '%')
			ft_parse((char **)&format, &sum, va_list);
		else
			sum += ft_putchar_rtn(*format);
		format++;
	}
	va_end(va_list);	
	return (sum);
}