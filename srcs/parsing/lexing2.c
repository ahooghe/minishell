/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:57:00 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	define_joins(t_lexing *ltable, t_token *quoted,
	int reader, int quote_len)
{
	if (ltable->input[reader + quote_len] && ltable->input[reader + quote_len]
		!= ' ' && ltable->input[reader + quote_len] != '\t')
		quoted->join_next = 1;
	if (!reader)
		return ;
	else if (ltable->input [reader - 1] != ' '
		&& ltable->input[reader - 1] != '\t')
		quoted->join_prev = 1;
}
