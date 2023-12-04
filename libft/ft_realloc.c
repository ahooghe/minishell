/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:34:35 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	len;

	new_ptr = ft_calloc(sizeof(char), size);
	if (!new_ptr)
		return (0);
	len = ft_strlen((char *)ptr) + 1;
	if (len > size)
		len = size;
	ft_strlcpy(new_ptr, ptr, len);
	free(ptr);
	return (new_ptr);
}
