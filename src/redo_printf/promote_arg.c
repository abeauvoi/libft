/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 07:04:50 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/24 07:16:49 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void			*promote_arg(t_u32 state, void *value)
{
    if (state == INT)
        return ((void *)(int)value);
    else if (state == UINT)
        return ((void *)(t_u32)value);
    else if (state == LONG)
        return ((void *)(t_s64)value);
    else if (state == ULONG)
        return ((void *)(t_u64)value);
    else if (state == SHORT)
        return ((void *)(t_s16)value);
    else if (state == USHORT)
        return ((void *)(t_u16)value);
    else if (state == CHAR)
        return ((void *)(char)value);
    else if (state == UCHAR)
        return ((void *)(t_u8)value);
}
