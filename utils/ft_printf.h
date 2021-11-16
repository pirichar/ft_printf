/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:09:05 by pirichar          #+#    #+#             */
/*   Updated: 2021/11/16 09:05:37 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stddef.h>

void	ft_putchar(char c);
int		ft_putstring_rtn(char *str);
void	ft_putnbro_rtn(long long num, long long base_len, char *base, int *sum);
void	ft_putnbro_rtn_neg(long nb, int *sum);
void	ft_putnbr_rtn_p(size_t num, size_t base_len, char *base, int *sum);
int		ft_putchar_rtn(char c);
int		ft_printf(const char *format, ...);

#endif
