/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:57:34 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/03 22:14:07 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbdigits(intmax_t n)
{
	int		i;

	if (n == 0)
		return (1);
	i = n < 0 ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
