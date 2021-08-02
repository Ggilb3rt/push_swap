/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:19:21 by ggilbert          #+#    #+#             */
/*   Updated: 2021/02/04 18:54:13 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_clear(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (ptr);
}

char	*properjoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	tmp = ft_clear(tmp);
	return (s1);
}

char	*nintxt(char **txt, int *n)
{
	char	*ptrn;
	char	*line;
	char	*tmp;

	ptrn = ft_strchr(*txt, '\n');
	if (ptrn)
	{
		*ptrn = '\0';
		line = ft_strdup(*txt);
		tmp = *txt;
		*txt = ft_strdup(++ptrn);
		tmp = ft_clear(tmp);
		*n = 0;
	}
	else
	{
		line = ft_strdup(*txt);
		*txt = ft_clear(*txt);
	}
	return (line);
}

char	*freshchar(int fd, int *n, char *line, char **txt)
{
	char	*buff;
	char	*ptrn;

	buff = ft_newstr(BUFFER_SIZE);
	while ((*n = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[*n] = '\0';
		ptrn = ft_strchr(buff, '\n');
		if (ptrn)
		{
			*ptrn = '\0';
			line = properjoin(line, buff);
			if (*txt == NULL)
				*txt = ft_newstr(0);
			*txt = properjoin(*txt, ++ptrn);
			buff = ft_clear(buff);
			break ;
		}
		line = properjoin(line, buff);
	}
	buff = ft_clear(buff);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	*txt;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	if (txt)
		*line = nintxt(&txt, &ret);
	else
	{
		*line = ft_newstr(0);
		if (!(*line))
			return (-1);
	}
	if (ret)
	{
		*line = freshchar(fd, &ret, *line, &txt);
		if (ret == 0 && txt)
			txt = ft_clear(txt);
		if (ret > 0)
			return (1);
		else
			return (ret);
	}
	return (1);
}
