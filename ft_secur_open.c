/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secur_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:19:29 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/11 14:18:59 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_secur_open(char *str)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		i;

	i = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_exit(0);
	buf[read(fd, buf, BUFF_SIZE)] = '\0';
	if (buf[0] == '\0')
		ft_exit(1);
	while (buf[i])
	{
		if (buf[i] < 48 && buf[i] > 57 && buf[i] != '\n' && buf[i] != ' ')
			ft_exit(1);
		i++;
	}
	close(fd);
	return (0);
}
