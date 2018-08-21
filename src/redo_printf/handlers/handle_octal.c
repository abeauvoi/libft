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

inline void	handle_oct_int(t_ftpf_info *info)
{
	info->workptr = num_to_oct(info->arg.i, info->endptr);
	if (info->arg.i && (info->flags & ALT))
	{
		info->prefix_len = 1;
		info->prefix += 5;
	}
}
