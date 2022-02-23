/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:58:55 by aboehm            #+#    #+#             */
/*   Updated: 2022/02/23 13:58:56 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fractol.h"

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	free((void **)&mlx);
	return (NULL);
}

t_mlx		*init(t_fractal *f)
{
	t_mlx	*mlx;
	char	*title;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		return (NULL);
	title = ft_strjoin("Fract'ol - ", f->name);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT, title)) == NULL ||
		(mlx->image = new_image(mlx)) == NULL ||
		(mlx->data = ft_calloc(sizeof(t_pixel) * WIN_WIDTH
								* WIN_HEIGHT, 1)) == NULL)
		return (mlxdel(mlx));
	mlx->mouse.isdown = 0;
	mlx->fractal = f;
	mlx->mouselock = 1 - f->mouse;
	mlx->palette = get_palettes();
	mlx->smooth = 1;
	return (mlx);
}
