/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/07 18:38:36 by jbert             #+#    #+#             */
/*   Updated: 2014/08/21 07:01:32 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_count(char *s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s[j])
	{
		if (s[j] == '\n')
		{
			while (s[j] == '\n')
				j++;
			i++;
		}
		j++;
	}
	return (i);
}

char	*white_mall(char *s, int *j)
{
	int		i;
	char	*t;

	if (j[4] == 1 || j[4] == 0)
	{
		i = 0;
		while (s[i] && s[i] != '\n')
			i++;
		j[3] = i;
		j[4]++;
	}
	else
		i = j[3];
	t = (char *)malloc(sizeof(char) * (i + 1));
	if (!t)
		exit(0);
	return (t);
}

char	**ft_strsplit(char *str)
{
	char	**t;
	int		i;
	int		j[5];

	j[2] = map_size(0);
	t = (char **)malloc(sizeof(char *) * (j[2] + 3));
	i = 0;
	j[1] = 1;
	j[0] = 0;
	j[4] = 0;
	j[3] = 0;
	while (t && str[i] && j[0] < j[2] + 3 && j[1] > 0)
	{
		t[j[0]] = white_mall(&str[i], j);
		j[1] = (t[j[0]]) ? 0 : -10;
		while (str[i] && str[i] != '\n' && j[1] >= 0)
			t[j[0]][j[1]++] = str[i++];
		(j[1] > 0) ? (t[j[0]][j[1]] = 0) : 1;
		(j[1] == j[3]) ? 1 : (j[1] = -10);
		j[0]++;
		t[j[0]] = 0;
		i++;
	}
	j[1] == -10 ? (j[0] = -1) : 1;
	return ((j[0] == (j[2] + 1)) ? t : NULL);
}
