/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:42:40 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*gnl(void)
{
	char	*buffer;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!buffer)
		return (0);
	read(0, buffer, BUFFER_SIZE);
	return (buffer);
}

t_token	*fetch_delim(t_token **cursor)
{
	t_token	*browse;

	browse = *cursor;
	while (browse && browse->content[0] != '|')
	{
		if (browse->content[0] == '<' && browse->content[1] == '<')
		{
			*cursor = browse;
			return (browse->next);
		}
		browse = browse->next;
	}
	*cursor = browse;
	return (0);
}

int	delim_len(char *delim, char *line)
{
	int	line_len;
	int	delim_len;

	line_len = ft_strlen(line) - 1;
	delim_len = ft_strlen(delim);
	if (line_len > delim_len)
		return (line_len);
	else
		return (delim_len);
}
