/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:58:19 by aboehm            #+#    #+#             */
/*   Updated: 2022/02/28 13:05:54 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	viewport_fit(t_viewport *v)
{
	double	w;
	double	h;

	w = v->xmax - v->xmin;
	h = v->ymax - v->ymin;
	if (w / h >= (float)WIN_WIDTH / WIN_HEIGHT)
	{
		v->ymin = -(w * WIN_HEIGHT / WIN_WIDTH / 2);
		v->ymax = w * WIN_HEIGHT / WIN_WIDTH / 2;
	}
	else
	{
		v->xmin = -(h * WIN_WIDTH / WIN_HEIGHT / 2);
		v->xmax = (h * WIN_WIDTH / WIN_HEIGHT / 2);
	}
}

void	reset_viewport(t_mlx *mlx)
{
	mlx->viewport.offx = 0;
	mlx->viewport.offy = 0;
	mlx->fractal->viewport(&mlx->viewport);
	viewport_fit(&mlx->viewport);
	mlx->viewport.max = 32;
	mlx->viewport.zoom = 1.0f;
}

t_complex	screen_to_complex(int x, int y, t_viewport *v)
{
	t_complex	p;

	p.r = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	p.i = (((double)y / WIN_HEIGHT) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (p);
}
