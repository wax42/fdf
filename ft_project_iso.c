/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project_iso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:43:11 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/08 19:00:37 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double		ft_deg_to_rad(int angle)
{
	return ((angle / PI) / 180);
}

static void			ft_define_color(t_tab p, t_p *l)
{
	if (l->var_color == 1)
	{
		l->color = rgb_to_hexa(p.x * p.z * l->z, p.y * p.z, p.z * l->z);
	}
	else
	{
		if (p.z <= 0)
			l->color = rgb_to_hexa(0, 0, 200 + abs(p.z));
		else if (p.z > 0)
			l->color = rgb_to_hexa(102, 80 + p.z, 0);
		else if (p.z > 50)
			l->color = rgb_to_hexa(100 + p.z, 80 + p.z, 0);
		else if (p.z > 100)
			l->color = rgb_to_hexa(0, 0 + p.z, 0);
		else if (p.z > 200)
			l->color = rgb_to_hexa(254, 254, 254);
	}
	if (l->white == 1)
		l->color = rgb_to_hexa(l->r, l->g, l->b);
}

t_tab				project_iso(t_tab p, t_p *l)
{
	t_tab	v;
	double	al;

	ft_define_color(p, l);
	p.x *= l->size;
	p.y *= l->size;
	if (!l->proj)
	{
		al = ft_deg_to_rad(l->angle);
		v.x = (p.x + l->x) * cos(al) + (p.y + l->y) * cos(al + 2.0944) \
		+ p.z * l->z * 0.2 * cos(al - 2.0944);
		v.y = (p.x + l->x) * sin(al) + (p.y + l->y) * sin(al + 2.0944) \
		+ p.z * l->z * 0.2 * sin(al - 2.0944);
	}
	else
	{
		v.x = (p.x + l->x) + (p.z * 0.2 * l->z);
		v.y = (p.y + l->y) + (p.z * 0.2 * l->z);
	}
	v.x += l->var_dec;
	v.y += l->var_dec;
	return (v);
}
