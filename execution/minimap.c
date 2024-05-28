/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:05:18 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/28 16:02:43 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_tile(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINI_TILE_SIZE)
	{
		j = -1;
		while (++j < MINI_TILE_SIZE)
			mlx_put_pixel(cub->minimap_img, x + i, y + j, color);
	}
}

void	draw_mini_player(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINI_TILE_SIZE / 4)
	{
		j = -1;
		while (++j < MINI_TILE_SIZE / 4)
			mlx_put_pixel(cub->minimap_img, x + i, y + j, color);
	}
	x += 2;
	y += 2;
	cast_rays(cub, x, y);
}

void	draw_minimap(t_cub *cub)
{
	int		x;
	int		y;
	char	**map;
	int		color;

	map = cub->data->map2d;
	y = -1;
	while (++y < cub->data->h_map)
	{
		x = -1;
		while (++x < cub->data->w_map)
		{
			if (map[y][x] == '1')
				color = 0xFF0F00FF;
			else if (map[y][x] == '0' || map[y][x] == 'P')
				color = C_TRANSPARENT;
			draw_tile(cub, x * MINI_TILE_SIZE, y * MINI_TILE_SIZE, color);
		}
	}
	draw_mini_player(cub, MINIMAP_SCALE * cub->p->x_pixel, MINIMAP_SCALE * cub->p->y_pixel, get_rgba(0, 0, 255, 255));
	
}

void	generate_minimap(t_cub *cub)
{
	new_img(cub, MINIMAP);
	draw_minimap(cub);
}
