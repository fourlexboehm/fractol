/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:57:49 by aboehm            #+#    #+#             */
/*   Updated: 2022/02/28 13:19:25 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include <stdlib.h>

int	draw_hooks(int key, t_mlx *mlx)
{
	int	doot;

	doot = 0;
	if (key >= K_DIGIT_1 && key <= K_DIGIT_1 + 3)
		mlx->palette = &get_palettes()[key - K_DIGIT_1];
	else if (key == K_NUM_ENTER)
		mlx->smooth = 1 - mlx->smooth;
	else
		doot = 1;
	if (!doot)
		draw(mlx);
	return (doot);
}

int	hook_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_NUM_0)
		reset_viewport(mlx);
	if (key == K_NUM_MULT)
		mlx->viewport.max *= 2;
	if (key == K_NUM_DIV)
		if (mlx->viewport.max / 2 >= 2)
			mlx->viewport.max /= 2;
	if (key == K_NUM_PLUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, 1 / ZOOM);
	if (key == K_NUM_MINUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, ZOOM);
	if (draw_hooks(key, mlx))
		render(mlx);
	return (0);
}
