/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:44:44 by jaewonki          #+#    #+#             */
/*   Updated: 2022/02/28 14:44:44 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!str)
		len = (int)write(1, "(null)", 6);
	else
		len = ft_putstr(str);
	return (len);
}