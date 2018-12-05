/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:41:24 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 22:53:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

#include <string.h>
#include <stdio.h>

int 		main(void)
{
	char	*str1 = "aaabbbbbccccjaijreijarprjairjaprijaperjaperijaerpiajerpaijepijaidjapdijaedipajpidjapdij";
	char	*str2 = "aaabbbbbccccjaijrijrpjajtphaptuhap";
	char 	*str3 = "aaabbbbbccccjaijreijarprjjreerjiejraij";

	printf("[ft_strcmp:%i][strcmp:%i]\n", ft_strcmp(str1, str2), strcmp(str1, str2));
	printf("[ft_strcmp:%i][strcmp:%i]\n", ft_strcmp(str2, str3), strcmp(str2, str3));
	printf("[ft_strcmp:%i][strcmp:%i]\n", ft_strcmp(str1, str3), strcmp(str1, str3));
	return 0;
}
