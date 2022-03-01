/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:42:19 by jaewonki          #+#    #+#             */
/*   Updated: 2022/02/28 14:42:19 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	int		formLen;
	va_list	ap;
	char	*str;

	if (!form)
		return (-1);
	va_start(ap, form);
	str = (char *)form;
	if (!ft_strchr(str, '%'))
		formLen = (int)write(1, str, ft_strlen(str));
	else
		formLen = parse_arg(ap, str);
	va_end(ap);
	return (formLen);
}