/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:39:40 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/08 18:56:34 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_ligne1(t_p st, t_ligne l)
{
	int i;

	l.cumul = l.dx / 2;
	i = 0;
	while (i <= l.dx)
	{
		i++;
		l.x += l.xplus;
		l.cumul += l.dy;
		if (l.cumul >= l.dx)
		{
			l.cumul -= l.dx;
			l.y += l.yplus;
		}
		mlx_pixel_put_to_image(st, l.x, l.y, st.color);
	}
}

static void		ft_ligne2(t_p st, t_ligne l)
{
	int i;

	l.cumul = l.dy / 2;
	i = 0;
	while (i <= l.dy)
	{
		i++;
		l.y += l.yplus;
		l.cumul += l.dx;
		if (l.cumul >= l.dy)
		{
			l.cumul -= l.dy;
			l.x += l.xplus;
		}
		mlx_pixel_put_to_image(st, l.x, l.y, st.color);
	}
}

void			ft_ligne(t_p st, t_tab p, t_tab p2)
{
	t_ligne l;

	l.x = p.x;
	l.y = p.y;
	l.dx = p2.x - p.x;
	l.dy = p2.y - p.y;
	l.xplus = (l.dx > 0) ? 1 : -1;
	l.yplus = (l.dy > 0) ? 1 : -1;
	l.dx = abs(l.dx);
	l.dy = abs(l.dy);
	mlx_pixel_put_to_image(st, l.x, l.y, st.color);
	if (l.dx > l.dy)
		ft_ligne1(st, l);
	else
		ft_ligne2(st, l);
}
