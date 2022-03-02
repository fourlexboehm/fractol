/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:58:02 by aboehm            #+#    #+#             */
/*   Updated: 2022/02/28 15:12:29 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, t_viewport *v, double z)
{
	double	w;
	double	h;
	double	nw;
	double	nh;

	w = (v->xmax - v->xmin) * (v->zoom);
	h = (v->ymax - v->ymin) * (v->zoom);
	nw = (v->xmax - v->xmin) * (v->zoom * z);
	nh = (v->ymax - v->ymin) * (v->zoom * z);
	v->zoom *= z;
	v->offx -= ((double)x / WIN_WIDTH) * (nw - w);
	v->offy -= ((double)y / WIN_HEIGHT) * (nh - h);
}

int	hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
	{
		zoom(x, y, &mlx->viewport, 1 / ZOOM);
		render(mlx);
	}
	else if (button == 5)
	{
		zoom(x, y, &mlx->viewport, ZOOM);
		render(mlx);
	}
	if (y < 0)
		return (0);
	mlx->mouse.isdown |= 1 << button;
	return (0);
}

int	hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse.isdown &= ~(1 << button);
	return (0);
}

int	hook_mousemove(int x, int y, t_mlx *mlx)
{
	double	w;
	double	h;

	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (!mlx->mouselock)
		mlx->viewport.mouse = screen_to_complex(x, y, &mlx->viewport);
	if (mlx->mouse.isdown & (1 << 1))
	{
		w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
		h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
		mlx->viewport.offx += (double)(mlx->mouse.lastx - mlx->mouse.x)
			/ WIN_WIDTH * w;
		mlx->viewport.offy += (double)(mlx->mouse.lasty - mlx->mouse.y)
			/ WIN_HEIGHT * h;
	}
	if (mlx->mouse.isdown || (mlx->fractal->mouse && !mlx->mouselock))
		render(mlx);
	return (0);
}
