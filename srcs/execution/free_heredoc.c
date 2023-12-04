/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:44:04 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_heredoc(t_lexing *ltable, t_data_env *data_env,
			char *error_msg)
{
	tk_clear(&ltable->tklist_head);
	ft_free_env(data_env->envp, data_env->size);
	free(data_env->pwd);
	ft_putstr_fd(error_msg, 2);
	exit(g_mini.exit_status);
}
