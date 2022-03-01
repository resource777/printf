/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:43:29 by jaewonki          #+#    #+#             */
/*   Updated: 2022/02/28 14:43:29 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_arg(va_list ap, char *str)
{
	int		formLen;

	formLen = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			formLen++;
		}
		else
		{
			str++;
			if (check_format(ap, *str, &formLen) == -1)
				return (-1);
		}
		str++;
	}
	return (formLen);
}