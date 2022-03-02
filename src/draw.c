/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:57:28 by aboehm            #+#    #+#             */
/*   Updated: 2022/02/28 15:12:20 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

void	render(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			*(mlx->data + y * WIN_WIDTH + x)
				= mlx->fractal->pixel(x, y, &mlx->viewport, mlx);
			x++;
		}
		y++;
	}
	draw(mlx);
}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			image_set_pixel(mlx->image, x, y,
				get_color(*(mlx->data + y * WIN_WIDTH + x), mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}

t_mlx	*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	free((void **)&mlx);
	return (NULL);
}

t_mlx	*init(t_fractal *f)
{
	t_mlx	*mlx;
	char	*title;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		return (NULL);
	title = ft_strjoin("Fract'ol - ", f->name);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, title);
	mlx->image = new_image(mlx);
	mlx->data = ft_calloc(sizeof(t_pixel) * WIN_WIDTH * WIN_HEIGHT, 1);
	if (!mlx->mlx || !mlx->window || !mlx->image || !mlx->data)
		return (mlxdel(mlx));
	mlx->mouse.isdown = 0;
	mlx->fractal = f;
	mlx->mouselock = 1 - f->mouse;
	mlx->palette = get_palettes();
	mlx->smooth = 1;
	return (mlx);
}
