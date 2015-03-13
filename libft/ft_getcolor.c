/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:22:09 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/20 13:22:25 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_getcolor(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}