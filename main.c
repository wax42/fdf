/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:53:03 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/11 13:19:00 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_clear_window(t_p *p, int win_x, int win_y)
{
	int y;
	int x;

	x = 0;
	while (x++ < win_x)
	{
		y = 0;
		while (y++ < win_y)
			mlx_pixel_put_to_image(*p, x, y, 0x0);
	}
}

static	void	my_key_funct2(int keycode, t_p *p)
{
	if (keycode == 124)
		p->x += 10;
	if (keycode == 126)
		p->y -= 10;
	if (keycode == 125)
		p->y += 10;
	if (keycode == 7)
		p->z -= 1;
	if (keycode == 6)
		p->z += 1;
	if (keycode == 69)
		p->size += 1;
	if (keycode == 78)
		p->size -= 1;
	if (keycode == 83)
		p->angle += 10;
	if (keycode == 84)
		p->angle -= 10;
	if (keycode == 15)
		p->r -= 10;
	if (keycode == 5)
		p->g -= 10;
	if (keycode == 11)
		p->b -= 10;
}

static int		my_key_funct(int keycode, t_p *p)
{
	ft_putstr("\nkey event :");
	ft_putnbr(keycode);
	if (keycode == 53)
		ft_exit(-1);
	if (keycode == 123)
		p->x -= 10;
	my_key_funct2(keycode, p);
	(keycode == 35) ? (p->proj = abs(p->proj - 1)) : (p->proj);
	(keycode == 0) ? (p->var_color = abs(p->var_color - 1)) : (p->var_color);
	(keycode == 13) ? (p->white = abs(p->white - 1)) : (p->white);
	ft_clear_window(p, WIN_X, WIN_X);
	ft_aff(p);
	return (0);
}

static void		ft_init_struct(t_p *p)
{
	int	max;

	max = 1;
	(p->x_max < p->y_max) ? (max *= p->y_max) : (max *= p->x_max);
	p->var_dec = (WIN_X / 3);
	p->size = (p->var_dec * 2) / max;
	p->win_size = WIN_X;
	p->r = 250;
	p->g = 250;
	p->b = 250;
	p->var_color = 0;
	p->white = 1;
	p->z = 1;
	p->x = 0;
	p->y = 0;
	p->angle = 30;
	p->proj = 0;
}

int				main(int argc, char **argv)
{
	t_p		p;
	int		fd;

	if (argc == 2)
	{
		ft_secur_open(argv[1]);
		fd = ft_openfile(argv[1]);
		ft_first_read(&p, fd);
		ft_closefile(fd);
		ft_init_struct(&p);
		p.mlx = mlx_init();
		p.win = mlx_new_window(p.mlx, p.win_size, p.win_size, "fdf");
		p.img = mlx_new_image(p.mlx, p.win_size, p.win_size);
		p.map = mlx_get_data_addr(p.img, &p.bpp, &p.size_line, &p.endian);
		if (!(p.tab = (t_tab**)malloc(sizeof(t_tab*) * p.y_max)))
			ft_exit(2);
		fd = ft_openfile(argv[1]);
		ft_read(&p, fd);
		ft_aff(&p);
		mlx_hook(p.win, 2, (1L << 0), my_key_funct, &p);
		mlx_loop(p.mlx);
	}
	else
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	return (0);
}
