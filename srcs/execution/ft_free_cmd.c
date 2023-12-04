/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:43:28 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_cmd(t_cmd *cmd)
{
	if (cmd->argv != NULL)
		free_array(cmd->argv);
	if (cmd->cmd_path != NULL)
		free(cmd->cmd_path);
	if (cmd->first_arg != NULL)
		free(cmd->first_arg);
	cmd->argv = NULL;
	cmd->cmd_path = NULL;
	cmd->first_arg = NULL;
}
