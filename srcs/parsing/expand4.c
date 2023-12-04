/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:42:01 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_content_end(char *new_content, char *content, int i, int j)
{
	while (*(content + i))
	{
		new_content[j] = content[i];
		i++;
		j++;
	}
}

char	*delete_num(char *content, char **cursor)
{
	char	*new_content;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new_content = ft_calloc(sizeof(char), ft_strlen(content) - 1);
	if (!new_content)
		return (0);
	while (*(content + ++i) && content + i != *cursor)
	{
		new_content[j] = content[i];
		j++;
	}
	i ++;
	while (*(content + ++i))
	{
		new_content[j] = content[i];
		j++;
	}
	*cursor = new_content + j;
	copy_content_end(new_content, content, i, j);
	free(content);
	return (new_content);
}
