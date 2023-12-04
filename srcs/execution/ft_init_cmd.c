/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:42:50 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_cmd(t_cmd *cmd)
{
	cmd->argc = 0;
	cmd->argv = NULL;
	cmd->pipe = 0;
	cmd->pipefd[0] = -2;
	cmd->pipefd[1] = -2;
	cmd->final_cmd = 0;
	cmd->fd_in = -2;
	cmd->fd_out = -2;
	cmd->cmd_path = NULL;
	cmd->final_pid = 0;
	cmd->has_cmd = 0;
	cmd->first_arg = NULL;
	cmd->first_arg_done = 0;
	cmd->fd_heredoc = -2;
	cmd->inside_pipe = 0;
	cmd->error_fd = NULL;
	cmd->filename = NULL;
}
