/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:57:35 by aboehm            #+#    #+#             */
/*   Updated: 2022/02/28 13:08:55 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

t_fractal	*get_fractals(void)
{
	static t_fractal	array[8] = {
	{"mandelbrot", mandelbrot_viewport, mandelbrot_pixel, 0},
	{"julia", julia_viewport, julia_pixel, 1},
	{NULL, NULL, NULL, 0}
	};

	return (array);
}

t_fractal	*fractal_match(char *str)
{
	t_fractal	*f;
	int			i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}
