/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:14:24 by ldatilio          #+#    #+#             */
/*   Updated: 2021/10/13 22:42:49 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_char(int c)
{
	return (write(1, &c, sizeof(char)));
}

int	ft_type_string(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s) * sizeof(char)));
}

int	ft_type_pointer(unsigned long p)
{
	char	*str;
	char	*temp;
	int		len;

	str = ft_convert_base(p, "0123456789abcdef");
	temp = str;
	str = ft_strjoin("0x", temp);
	free(temp);
	len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}

int	ft_type_decimal(int d)
{
	char	*str;
	char	sign;
	int		len;

	sign = 0;
	len = 0;
	if (d < 0)
	{
		str = ft_uitoa(-(long)d);
		sign = 1;
	}
	else
		str = ft_uitoa(d);
	if (sign == 1)
		len = write(1, "-", sizeof(char));
	len += write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}

int	ft_type_ux(unsigned int x, char	*base)
{
	char	*str;
	int		len;

	str = ft_convert_base(x, base);
	len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}
