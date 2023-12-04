/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:36:10 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!little || !little[0])
		return ((char *)big);
	if (!big)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[i + j] == little[j]) && ((i + j) < len)
			&& little[j] && big[i + j])
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
