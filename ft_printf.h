/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:42:55 by jaewonki          #+#    #+#             */
/*   Updated: 2022/02/28 14:42:55 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *arg, ...);
int		parse_arg(va_list ap, char *arg);
int		check_format(va_list ap, char type, int *nprintf);

int		print_nbr(char type, unsigned long nbr);
char	*check_base(char type);
int		ft_put_nbr(char type, unsigned long nbr, char *base);

int		print_str(char *str);
int		print_char(char c);

int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
int		ft_putchar(char c);
int		ft_putstr(char *s);

#endif