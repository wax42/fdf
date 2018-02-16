/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:20:18 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/08 18:34:38 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_aff(t_p *p)
{
	int y;
	int x;

	y = 0;
	while (y < p->y_max)
	{
		x = 0;
		while (x < p->x_max)
		{
			if (y != 0)
				ft_ligne(*p, project_iso(p->tab[y][x], p), \
						project_iso(p->tab[y - 1][x], p));
			if (x != 0)
				ft_ligne(*p, project_iso(p->tab[y][x], p), \
						project_iso(p->tab[y][x - 1], p));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
