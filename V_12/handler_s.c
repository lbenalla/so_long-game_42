/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labenall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:04:26 by labenall          #+#    #+#             */
/*   Updated: 2022/06/02 13:09:56 by labenall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handler_s_0(t_mlx **g_mlx)
{
	int		width;
	int		height;
	void	*img_p;
	void	*img_0;

	(*g_mlx)->map->map_array[(*g_mlx)->player->x + 1] \
		[(*g_mlx)->player->y] = 'P';
	(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
		[(*g_mlx)->player->y] = '0';
	(*g_mlx)->move++;
	write(1, "move :", 6);
	ft_putnbr((*g_mlx)->move);
	write(1, "\n", 1);
	img_p = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->p, &width, &height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_p, \
			((*g_mlx)->player->y) * 64, ((*g_mlx)->player->x + 1) * 64);
	img_0 = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->k, &width, &height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_0, \
			((*g_mlx)->player->y) * 64, (*g_mlx)->player->x * 64);
	(*g_mlx)->player->x++;
}

void	handler_s_c(t_mlx **g_mlx)
{
	int		width;
	int		height;
	void	*img_p;
	void	*img_0;

	(*g_mlx)->map->map_array[(*g_mlx)->player->x + 1] \
		[(*g_mlx)->player->y] = 'P';
	(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
		[(*g_mlx)->player->y] = '0';
	(*g_mlx)->map->c--;
	(*g_mlx)->move++;
	write(1, "move :", 6);
	ft_putnbr((*g_mlx)->move);
	write(1, "\n", 1);
	img_p = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->p, &width, &height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_p, \
			((*g_mlx)->player->y) * 64, ((*g_mlx)->player->x + 1) * 64);
	img_0 = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
			(*g_mlx)->image->k, &width, &height);
	mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_0, \
			((*g_mlx)->player->y) * 64, (*g_mlx)->player->x * 64);
	(*g_mlx)->player->x++;
}

void	handler_s_e(t_mlx **g_mlx)
{
	int		width;
	int		height;
	void	*img_p;
	void	*img_0;

	if ((*g_mlx)->map->c == 0)
	{
		(*g_mlx)->map->map_array[(*g_mlx)->player->x + 1] \
			[(*g_mlx)->player->y] = 'P';
		(*g_mlx)->map->map_array[(*g_mlx)->player->x] \
			[(*g_mlx)->player->y] = '0';
		write(1, "move :", 6);
		ft_putnbr(++(*g_mlx)->move);
		write(1, "\n", 1);
		img_p = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
				(*g_mlx)->image->p, &width, &height);
		mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, img_p, \
				((*g_mlx)->player->y) * 64, ((*g_mlx)->player->x + 1) * 64);
		img_0 = mlx_xpm_file_to_image((*g_mlx)->mlx_ptr, \
				(*g_mlx)->image->k, &width, &height);
		mlx_put_image_to_window((*g_mlx)->mlx_ptr, (*g_mlx)->window_ptr, \
				img_0, ((*g_mlx)->player->y) * 64, (*g_mlx)->player->x * 64);
		(*g_mlx)->player->x++;
		ft_exit(g_mlx, "Bravo\n", 0);
	}
}

void	handler_s(t_mlx **g_mlx)
{
	if ((*g_mlx)->map->map_array[(*g_mlx)->player->x + 1] \
			[(*g_mlx)->player->y] == '0')
		handler_s_0(g_mlx);
	else if ((*g_mlx)->map->map_array[(*g_mlx)->player->x + 1] \
			[(*g_mlx)->player->y] == 'C')
		handler_s_c(g_mlx);
	else if ((*g_mlx)->map->map_array[(*g_mlx)->player->x + 1] \
			[(*g_mlx)->player->y] == 'E')
		handler_s_e(g_mlx);
}
