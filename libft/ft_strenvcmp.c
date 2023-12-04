/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strenvcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:34:56 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strenvcmp(const char *s1, char *env, size_t n)
{
	char	*cursor;
	size_t	i;

	i = 0;
	cursor = env;
	if (!n)
		return (0);
	while (*cursor && *cursor != '=')
	{
		cursor++;
		i++;
	}
	if (i < n)
		i = n;
	return (ft_strncmp(s1, env, i));
}
