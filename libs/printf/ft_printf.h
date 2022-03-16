/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:14:11 by ldatilio          #+#    #+#             */
/*   Updated: 2021/10/13 16:26:55 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_type(va_list ap, char type);

int		ft_type_char(int c);
int		ft_type_string(char *s);
int		ft_type_pointer(unsigned long p);
int		ft_type_decimal(int d);
int		ft_type_ux(unsigned int x, char	*base);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_convert_base(size_t n, char *base);
char	*ft_uitoa(unsigned int value);

#endif
