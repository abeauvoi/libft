/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 01:22:25 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/03 01:28:39 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printtf.h"

int			handle_pointer(t_ftpf *info)
{
	info->prec = MAX(sizeof(void *) * 2, info->prec);
	info->flags |= ALT;
	return (handle_hex_int(info));
}
