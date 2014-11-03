/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 20:17:06 by jbert             #+#    #+#             */
/*   Updated: 2014/08/21 14:18:30 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	while (s1 && s1[i])
		i++;
	j = 0;
	while (s2 && s2[j])
		j++;
	t = (char *)malloc(sizeof(char) * (i + j + 1));
	while (t && s2 && j >= 0)
	{
		t[i + j] = s2[j];
		j--;
	}
	while (t && s1 && i > 0)
	{
		--i;
		t[i] = s1[i];
	}
	return (t);
}

char	*ft_get_map(int	fd)
{
	char	*map;
	char	l[1025];
	int		r;
	char	*tmp;

	map = 0;
	map = ft_join(map, "\0");
	while ((r = read(fd, l, 1024)) > 0)
	{
		l[r] = '\0';
		tmp = ft_join(map, l);
		free(map);
		map = tmp;
		tmp = 0;
	}
	close(fd);
	return (map);
}

char	**free_ret(char **map, char *s)
{
	free(s);
	return (map);
}

int		ft_atoi(char *str)
{
	int	nb;
	int	i;

	if (!str)
		return (0);
	nb = 0;
	i = 0;
	if (str[i] == '-')
		return (0);
	while (str[i] <= '9' && str[i] >= '0' && str[i] && str[i] != '\n' && \
		str[i + 1] && str[i + 1] != '\n' && str[i + 2] && \
		str[i + 2] != '\n' && str[i + 3] && str[i + 3] != '\n' && str[i + 4])
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	if (!str[i] || (str[i] && (!str[i + 1] || (str[i + 1] && (!str[i + 2] \
		|| (str[i + 2] && !str[i + 3]))))))
		return (0);
	return (nb);
}

char	**get_map(char *f, char *v, char *o, char *p)
{
	int		fd;
	char	*s;
	int		i;
	char	**map;

	fd = f ? open(f, O_RDONLY) : 0;
	if (fd < 0)
		return (NULL);
	s = ft_get_map(fd);
	i = map_size(ft_atoi(s)) ? 0 : -1;
	while (i >= 0 && s[i] && s[i] <= '9' && s[i] >= '0' && s[i + 3] != '\n')
		i++;
	if (i <= 0 || i >= 14 || (s && !s[i]) || map_size(0) <= 0 || \
(s && s[i] && (!s[i + 1] || (s[i + 1] && (!s[i + 2] || \
(s[i + 2] && (s[i + 3] != '\n' || (s[i + 3] && !s[i + 4]))))))))
		return (free_ret(NULL, s));
	if (s[i] == s[i + 1] || s[i + 1] == s[i + 2] || s[i] == s[i + 2] || \
		s[i] == '\n' || s[i + 1] == '\n' || s[i + 2] == '\n')
		return (free_ret(NULL, s));
	(*v) = s[i];
	(*o) = s[i + 1];
	(*p) = s[i + 2];
	map = ft_strsplit(s);
	return (free_ret(map, s));
}
