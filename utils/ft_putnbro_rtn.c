/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbro_rtn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:04:07 by pirichar          #+#    #+#             */
/*   Updated: 2021/11/16 09:38:26 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbro_rtn(size_t num, size_t base_len, char *base, int *sum)
{
	char	c;

	if (num >= base_len)
		ft_putnbro_rtn(num / base_len, base_len, base, sum);
	c = base[(num % base_len)];
	write(1, &c, 1);
	(*sum)++;
}
