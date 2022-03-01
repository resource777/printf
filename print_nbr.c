/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:44:17 by jaewonki          #+#    #+#             */
/*   Updated: 2022/02/28 14:44:17 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

int	print_nbr(char type, unsigned long nbr)
{
	int		len;
	int		tmp;
	char	*base;

	base = check_base(type);
	len = 0;
	if ((type == 'd' || type == 'i') && (int)nbr < 0)
	{
		len = write(1, "-", 1);
		nbr *= -1;
	}
	else if (type == 'p')
		len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	tmp = ft_put_nbr(type, nbr, base);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

int	ft_put_nbr(char type, unsigned long nbr, char *base)
{
	int				tmp;
	int				ret;
	unsigned long	num;

	tmp = 0;
	if (type == 'd' || type == 'i' || type == 'u')
	{
		num = 10;
		if (nbr >= num)
			tmp = ft_put_nbr(type, nbr / num, base);
	}
	else
	{
		num = 16;
		if (nbr >= num)
			tmp = ft_put_nbr(type, nbr / num, base);
	}
	if (tmp == -1)
		return (-1);
	ret = tmp;
	tmp = write(1, &base[nbr % num], 1);
	if (tmp == -1)
		return (-1);
	ret += tmp;
	return (ret);
}