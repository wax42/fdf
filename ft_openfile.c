/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:47:21 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/08 18:57:05 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_openfile(char *files)
{
	int	fd;

	fd = open(files, O_RDONLY);
	if (fd == -1)
		ft_exit(0);
	return (fd);
}
