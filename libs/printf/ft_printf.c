/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:15:53 by ldatilio          #+#    #+#             */
/*   Updated: 2021/10/13 16:26:27 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len = len + ft_type(ap, format[i]);
		}
		else
			len = len + write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}

int	ft_type(va_list ap, char type)
{
	if (type == 'c')
		return (ft_type_char(va_arg(ap, int)));
	else if (type == 's')
		return (ft_type_string(va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_type_pointer(va_arg(ap, unsigned long)));
	else if (type == 'd' || type == 'i')
		return (ft_type_decimal(va_arg(ap, int)));
	else if (type == 'u')
		return (ft_type_ux(va_arg(ap, unsigned int), "0123456789"));
	else if (type == 'x')
		return (ft_type_ux(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_type_ux(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (type == '%')
		return (write(1, "%", 1));
	else
		return (0);
}
