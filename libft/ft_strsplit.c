/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:29:57 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/13 16:48:08 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_words(char const *str)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			words++;
		while (!ft_isspace(str[i]) && str[i] != '\0')
			i++;
	}
	return (words);
}

static void		split(char **ret, char const *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]) && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			break ;
		k = 0;
		while (ft_isspace(str[i]) && str[i] != '\0')
		{
			k++;
			i++;
		}
		if (!(ret[j] = (char*)malloc(sizeof(char) * (k + 1))))
			return ;
		ret[j] = ft_strncpy(ret[j], str + i - k, k);
		j++;
	}
	ret[j] = NULL;
}

char			**ft_strsplit(char const *str)
{
	char	**ret;

	if (!(ret = (char**)malloc(sizeof(char *) * (count_words(str) + 1))))
		return (NULL);
	split(ret, str);
	return (ret);
}
