/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:43:32 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_all_exec(t_minishell *mini)
{
	ft_close_all_fds(mini);
	ft_free_cmd(&mini->cmd);
	ft_free_env(mini->data_env.envp, mini->data_env.size);
	tk_clear(&mini->ltable.tklist_head);
	free(mini->ltable.input);
	free(mini->data_env.pwd);
	rl_clear_history();
}
