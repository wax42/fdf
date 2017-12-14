/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:11:14 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/11 14:18:13 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

# define WIN_X 1200
# define WIN_Y 1200
# define PI 3.1415926535897932384626433832795028841971693993751058209749445923

typedef struct		s_tab
{
	int				x;
	int				y;
	int				z;

}					t_tab;

typedef struct		s_ligne
{
	int				dx;
	int				dy;
	int				xplus;
	int				yplus;
	int				cumul;
	int				x;
	int				y;
}					t_ligne;

typedef struct		s_p
{
	void			*mlx;
	void			*win;
	int				size;
	int				var_dec;
	int				win_size;
	int				x_max;
	int				y_max;
	int				z;
	int				x;
	int				y;
	int				r;
	int				g;
	int				b;
	int				white;
	int				angle;
	int				var_color;
	int				color;
	int				proj;
	t_tab			**tab;
	void			*img;
	char			*map;
	int				bpp;
	int				size_line;
	int				endian;
}					t_p;

int					ft_secur_open(char *str);

int					rgb_to_hexa(int r, int g, int b);

int					ft_openfile(char *files);

void				ft_aff(t_p *p);

t_tab				project_iso(t_tab p, t_p *l);

void				ft_closefile(int fd);

void				ft_read(t_p *p, int fd);

void				ft_first_read(t_p *p, int fd);

void				ft_ligne(t_p p, t_tab p1, t_tab p2);

int					ft_exit(int i);

void				mlx_pixel_put_to_image(t_p p, int x, int y, int color);

#endif
