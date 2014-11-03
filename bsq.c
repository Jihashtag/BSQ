/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/19 04:23:24 by jbert             #+#    #+#             */
/*   Updated: 2014/08/21 07:22:54 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	save_p(char c)
{
	static char	p = 0;

	if (c)
		p = c;
	return (p);
}

int		is_good(char **map, char v, int *t, int *i)
{
	int		x[2];
	char	p;
	int		tmp;

	tmp = t[2] > 1 ? t[2] - 1 : 0;
	p = save_p(0);
	while (++tmp)
	{
		x[0] = 0;
		while (map[i[0] + tmp - 1] && map[i[0] + x[0]] && x[0] < tmp)
		{
			x[1] = 0;
			while (map[i[0] + x[0]][i[1] + x[1]] == v && x[1] < tmp)
				x[1]++;
			if (x[1] < tmp && map[i[0] + x[0]][i[1] + x[1]] && \
					map[i[0] + x[0]][i[1] + x[1]] != p)
				return (-10);
			if (x[1] < tmp)
				return (tmp - 1);
			x[0]++;
		}
		if (x[0] < tmp || !map[i[0] + tmp - 1])
			return (tmp - 1);
	}
	return (tmp);
}

int		cmp_char(char map, char c, char p)
{
	if ((map != c && map != p) || map == '\0')
		return (1);
	return (0);
}

int		*ft_bsq(char **map, char c, char p)
{
	int	*t;
	int	i[4];

	i[0] = -1;
	t = save_p(p) ? (int *)malloc(sizeof(int) * 3) : 0;
	t[2] = 0;
	i[3] = 0;
	while (t[2] >= 0 && map[++i[0]] && (i[1] = -1))
	{
		while (t[2] >= 0 && map[i[0]][++i[1]])
		{
			i[2] = is_good(map, c, t, i);
			if (t[2] != -10 && (i[2] > t[2] || i[2] == -10))
			{
				t[0] = i[0];
				t[1] = i[1];
				t[2] = i[2];
				i[1] += i[2] - 1;
			}
		}
		if ((i[0] && i[3] != i[1]) || cmp_char(map[i[0]][i[1] - 1], c, p))
			t[2] = -10;
		i[3] = i[1];
	}
	return (t);
}
