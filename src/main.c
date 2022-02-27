/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:57:56 by aboehm            #+#    #+#             */
/*   Updated: 2022/02/23 13:57:57 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "mlx.h"

int		hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

int		die(char *reason)
{
	ft_putendl_fd(reason, 1);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractal	*f;

	if (argc < 2)
		return (die("error: not enough arguments"));
	f = fractal_match(argv[1]);
	if (!f->name)
		return (die("error: invalid fractal name"));
	mlx = init(f);
	if (!mlx)
		return (die("error: mlx couldn't initialize properly"));
	reset_viewport(mlx);
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}