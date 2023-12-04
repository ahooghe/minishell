/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:36:27 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_trimlen(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (len && ft_isinbase(s1[len - 1], set))
		len--;
	while (s1[i] && len && ft_isinbase(s1[i], set))
	{
		i++;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		trimlen;
	char	*trim;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	trimlen = ft_trimlen(s1, set);
	trim = malloc(trimlen + 1);
	if (!trim)
		return (0);
	while (s1[i] && ft_isinbase(s1[i], set))
		i++;
	while (s1[i] && j < trimlen)
	{
		trim[j] = s1[i];
		i++;
		j++;
	}
	trim[trimlen] = 0;
	return (trim);
}
