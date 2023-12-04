/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:34:49 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dst;

	i = 0;
	if (!s)
		return (0);
	dst = (char *) malloc(ft_strlen(s) + 1);
	if (!dst)
		return (0);
	ft_bzero(dst, ft_strlen(s) + 1);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}
