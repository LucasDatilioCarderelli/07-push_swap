/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:14:32 by ldatilio          #+#    #+#             */
/*   Updated: 2021/10/13 22:46:55 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	src_len;
	size_t	i;

	if ((dest || src) == 0)
		return (0);
	src_len = ft_strlen(src);
	if (destsize)
	{
		i = 0;
		while (src[i] != '\0' && i < (destsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		join[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		join[i] = *s2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_convert_base(size_t n, char *base)
{
	int		len;
	char	*n_base;
	size_t	base_len;
	size_t	aux;

	base_len = ft_strlen(base);
	len = 0;
	aux = n;
	if (n == 0)
		len = 1;
	while (aux != 0)
	{
		aux /= base_len;
		len++;
	}
	n_base = malloc(sizeof(char) * (len + 1));
	if (!n_base)
		return (NULL);
	n_base[len] = '\0';
	while (len--)
	{
		n_base[len] = base[n % base_len];
		n /= base_len;
	}
	return (n_base);
}

char	*ft_uitoa(unsigned int value)
{
	char			*str;
	int				i;
	unsigned int	aux;

	aux = value;
	i = 0;
	if (value == 0)
		i = 1;
	while (aux != 0)
	{
		aux /= 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (value % 10) + '0';
		value /= 10;
	}
	return (str);
}
