/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:58:11 by aboehm            #+#    #+#             */
/*   Updated: 2022/02/28 15:12:50 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stddef.h>

t_palette	*get_palettes(void)
{
	static t_palette	array[5];

	array[0] = (t_palette)
		//{5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	{5, 0, {0xFFFFFF, 0x03f878, 0xccccc3, 0xF57336, 0xC22121}};
	array[1] = (t_palette)
	{5, 0, {0x451990, 0xfa373C, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[2] = (t_palette)
	{5, 0, {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF}};
	array[3] = (t_palette)
	{7, 10, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
		0x0000FF, 0xFF00FF, 0xFF0000}};
	array[4] = (t_palette){0, 0, {0}};
	return (array);
}
