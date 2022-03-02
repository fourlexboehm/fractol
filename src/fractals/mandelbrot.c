/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:42:15 by aboehm            #+#    #+#             */
/*   Updated: 2022/02/28 12:30:34 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

t_pixel	mandelbrot_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	(void)mlx;
	z = screen_to_complex(x, y, v);
	c = screen_to_complex(x, y, v);
	i = 0;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < v->max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return ((t_pixel){.c = z, .i = i});
}

void	mandelbrot_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
}
