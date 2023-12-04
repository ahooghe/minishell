/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:43:15 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_get_cmd(t_token *tklist_head, t_minishell *mini, int pipe_before)
{
	t_token	*lst;

	lst = tklist_head;
	while (lst != NULL)
	{
		if (lst->content[0] == '|' && lst->type == 'R')
			break ;
		ft_fill_cmd(mini, lst);
		lst = lst->next;
	}
	if (lst == NULL)
	{
		mini->cmd.final_cmd = 1;
		if (pipe_before == 1 || mini->cmd.pipe == 1)
			mini->cmd.inside_pipe = 1;
		return (lst);
	}
	if (lst->content[0] == '|' && lst->type == 'R')
	{
		mini->cmd.pipe = 1;
		mini->cmd.inside_pipe = 1;
		lst = lst->next;
	}
	return (lst);
}
