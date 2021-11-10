/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_rtn_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:53:10 by pirichar          #+#    #+#             */
/*   Updated: 2021/11/10 10:02:45 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_rtn_p(size_t num, size_t base_len, char *base, int *sum)
{
	char	c;

	ft_putchar('0');
	ft_putchar('x');
	(*sum) += 2;
	if (num >= base_len)
		ft_putnbro_rtn(num / base_len, base_len, base, sum);
	c = base[(num % base_len)];
	write(1, &c, 1);
	(*sum)++;
}
