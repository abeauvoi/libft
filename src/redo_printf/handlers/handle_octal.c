/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:03:07 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/19 05:08:38 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_oct_int(t_ftpf_info *info)
{
	info->a = num_to_oct(info->arg.i, info->z);
	if (info->arg.i && (info->flags & ALT_FORM))
	{
		info->prefix_len = 1;
		info->prefix += 5;
	}
}
