/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 16:15:38 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	ft_atoi_exit(char *str)
{
	int	nb;
	int	i;
	int	sign;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		str++;
		sign = -1;
	}
	i = 1;
	nb = str[0] % '0';
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] % '0');
		i++;
	}
	return (sign * nb);
}

void	ft_exit(t_minishell *mini)
{
	if (mini->cmd.argc > 2)
	{
		if (ft_check_numeric_arg(mini) != -1)
		{
			if (mini->cmd.inside_pipe == 1)
				ft_exit_utils(1, 1, mini);
			if (g_mini.status_done == 0 && mini->cmd.final_cmd == 1)
			{
				g_mini.exit_status = 1;
				g_mini.status_done = 1;
			}
		}
	}
	else if (mini->cmd.argc == 1)
		ft_exit_utils(g_mini.exit_status, 0, mini);
	else
	{
		if (ft_check_numeric_arg(mini) != -1)
			ft_exit_utils(ft_atoi_exit(mini->cmd.argv[1]), 0, mini);
	}
}
