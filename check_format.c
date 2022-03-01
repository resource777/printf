/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:41:46 by jaewonki          #+#    #+#             */
/*   Updated: 2022/02/28 14:41:46 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list ap, char type, int *formLen)
{
	int	ret;

	if (type == 'd' || type == 'i')
		ret = print_nbr(type, va_arg(ap, int));
	else if (type == 'u' || type == 'x' || type == 'X')
		ret = print_nbr(type, va_arg(ap, unsigned int));
	else if (type == 'p')
		ret = print_nbr(type, va_arg(ap, unsigned long));
	else if (type == 's')
		ret = print_str(va_arg(ap, char *));
	else if (type == 'c')
		ret = print_char((char)va_arg(ap, int));
	else if (type == '%')
		ret = print_char('%');
	else
		return (-1);
	*formLen += ret;
	return (ret);
}