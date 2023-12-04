/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:44:43 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_minishell *mini)
{
	int	i;

	if (mini->cmd.argc > 1)
		ft_exit_utils(EXIT_SUCCESS, 1, mini);
	else
	{
		i = 0;
		while (mini->data_env.envp[i])
			printf("%s\n", mini->data_env.envp[i++]);
		ft_exit_utils(EXIT_SUCCESS, 1, mini);
	}
}
