/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:53:03 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/08 19:05:12 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			ft_test_errreur(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])) && (str[i] != ' ') && (str[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}

static int			ft_strlentab(char **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void				ft_first_read(t_p *p, int fd)
{
	char	*line;
	char	**l_tab;

	p->x_max = 0;
	p->y_max = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(ft_test_errreur(line)))
			ft_exit(1);
		l_tab = ft_strsplit(line, 32);
		if (p->x_max == 0)
			p->x_max = ft_strlentab(l_tab);
		else if (p->x_max != ft_strlentab(l_tab))
			ft_exit(1);
		p->y_max++;
		free(l_tab);
		free(line);
	}
}

void				ft_read(t_p *p, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**l_tab;

	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		l_tab = ft_strsplit(line, 32);
		p->tab[y] = (t_tab*)malloc(sizeof(t_tab) * p->x_max);
		x = 0;
		while (l_tab[x])
		{
			p->tab[y][x].z = ft_atoi(l_tab[x]);
			p->tab[y][x].x = x;
			p->tab[y][x].y = y;
			x++;
		}
		free(l_tab);
		free(line);
		y++;
	}
}
