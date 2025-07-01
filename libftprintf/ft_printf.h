/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-rio <pdel-rio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:14:24 by pdel-rio          #+#    #+#             */
/*   Updated: 2025/07/01 16:14:55 by pdel-rio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int n, int counter);
int	ft_putu_pf(unsigned int n, int counter);
int	ft_puthex_pf(unsigned long n, int counter, const char base);
int	ft_putptr(void *ptr);
int	ft_print_pf(char *fmt, va_list arglst);
int	ft_printf(const char *format, ...);

#endif
