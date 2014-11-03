/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/18 14:55:55 by jbert             #+#    #+#             */
/*   Updated: 2014/08/21 11:34:28 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
/*#define malloc(S) (1 ? NULL : (malloc)(S))*/
void	ft_putendl(char *s, int fd);
int		*ft_bsq(char **tb, char vide, char obstacle);
char	**ft_strsplit(char *str);
int		map_size(int j);
char	**get_map(char *f, char *v, char *o, char *p);

#endif
