/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 18:03:25 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/14 14:41:15 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	advance_leftovers(char **tmp, char **line)
{
	char	*eol;
	char	*old_tmp;

	if (*tmp)
	{
		if ((eol = ft_strchr(*tmp, '\n')))
		{
			old_tmp = *tmp;
			*tmp = ft_strdup(eol + 1);
			ft_strdel(&old_tmp);
			if (!*tmp)
				return (-1);
		}
		else
			ft_strdel(tmp);
		if (*tmp && (eol = ft_strchr(*tmp, '\n')))
		{
			*line = ft_strndup(*tmp, (eol - *tmp));
			return (1);
		}
	}
	return (0);
}

static int	read_line(int fd, char **tmp, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*old_tmp;
	int		bt;
	char	*eol;

	while ((bt = read(fd, buff, BUFF_SIZE)))
	{
		if (bt == -1)
			return (-1);
		buff[bt] = '\0';
		eol = ft_strchr(buff, '\n');
		if (!eol)
			eol = ft_strchr(buff, '\0');
		if (*tmp)
		{
			if (*line)
				ft_strdel(line);
			*line = ft_strnjoin(*tmp, buff, eol - buff);
			if (!*line)
				return (-1);
			old_tmp = *tmp;
			*tmp = ft_strjoin(*tmp, buff);
			ft_strdel(&old_tmp);
			if (!*tmp)
				return (-1);
		}
		else
		{
			if (*line)
				ft_strdel(line);
			*line = ft_strndup(buff, eol - buff);
			if (!*line)
				return (-1);
			*tmp = ft_strdup(buff);
			if (!*tmp)
				return (-1);
		}
		if (*eol == '\n')
			break ;
	}
	return (bt);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp = NULL;
	int			bt;
	int			adv;

	if (line == NULL)
		return (-1);
	*line = NULL;
	if ((adv = advance_leftovers(&tmp, line)) != 0)
		return (adv);
	bt = read_line(fd, &tmp, line);
	if (bt == -1)
		return (-1);
	if (bt == 0)
	{
		if (!tmp)
			return (0);
		if (*tmp == '\0')
		{
			ft_strdel(&tmp);
			return (0);
		}
		else
			*line = tmp;
	}
	return (1);
}
