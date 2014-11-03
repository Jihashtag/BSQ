/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 14:55:28 by jbert             #+#    #+#             */
/*   Updated: 2014/08/21 04:03:00 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putendl(char *s, int fd)
{
	int	i;

	i = 1;
	while (*s && i)
		i = write(fd, s++, 1);
	i = write(fd, "\n", 1);
}

char	**place_p(char **map, int *t, char p, int i)
{
	int	k;
	int	j;

	k = t[0];
	while (k < i + t[2])
	{
		j = t[2];
		while (j)
		{
			map[k][t[1] + j - 1] = p;
			j--;
		}
		k++;
	}
	return (map);
}

void	ft_print(char **map, int *t, char p)
{
	int	i;

	if (!map || (t && t[2] <= 0))
		ft_putendl("Map error\nPlease do ./bsq good_map\nOr ./bsq < good_map", 2);
	else
	{
		i = 0;
		while (map[i])
		{
			if (i == t[0])
				map = place_p(map, t, p, i);
			ft_putendl(map[i], 1);
			i++;
		}
	}
	if (map)
	{
		i = 0;
		free(map[-1]);
		while (map[i])
			free(map[i++]);
		free(t);
	}
}

int		map_size(int j)
{
	static int	size = 0;

	if (j)
		size = j;
	return (size);
}

int		main(int ac, char **av)
{
	char	**map;
	char	vide;
	char	obstacle;
	char	plein;
	int		*t;

	if (ac == 1)
	{
		map = get_map(0, &vide, &obstacle, &plein);
		t = map ? ft_bsq(&map[1], vide, obstacle) : 0;
		map ? ft_print(&map[1], t, plein) : ft_print(0, 0, 0);
		free(map);
	}
	else
	{
		ac = 0;
		while (av[++ac])
		{
			map = get_map(av[ac], &vide, &obstacle, &plein);
			t = map ? ft_bsq(&map[1], vide, obstacle) : 0;
			map ? ft_print(&map[1], t, plein) : ft_print(0, 0, 0);
			free(map);
		}
	}
	return (0);
}
