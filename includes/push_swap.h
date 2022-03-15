/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:44:07 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/14 02:57:28 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../libs/libft/libft.h"

typedef enum e_bool
{
	TRUE	=	1,
	FALSE	=	0
}	t_bool;

int	valid_args(int argc, char **argv);

#endif
