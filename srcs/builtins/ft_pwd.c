/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe   <ahooghe@student.s19.be   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:53:56 by ahooghe           #+#    #+#             */
/*   Updated: 2023/09/28 13:44:17 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_pwd_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmp_env("PWD=", envp[i]) == 0)
			break ;
		i++;
	}
	if (envp[i] != NULL)
		return (envp[i] + 4);
	else
		return (NULL);
}

void	ft_print_pwd(char *pwd, t_minishell *mini)
{
	printf("%s\n", pwd);
	ft_exit_utils(EXIT_SUCCESS, 1, mini);
}

void	ft_pwd(t_minishell *mini)
{
	char	current_path[1000];
	char	*cwd;
	char	*pwd;

	if (mini->data_env.pwd != NULL)
		pwd = mini->data_env.pwd;
	else
		pwd = ft_get_pwd_env(mini->data_env.envp);
	if (pwd == NULL)
	{
		cwd = getcwd(current_path, sizeof(current_path));
		if (cwd == NULL)
		{
			perror("pwd: getcwd");
			ft_exit_utils(EXIT_FAILURE, 1, mini);
		}
		else
		{
			printf("%s\n", current_path);
			ft_exit_utils(EXIT_SUCCESS, 1, mini);
		}
	}
	else
		ft_print_pwd(pwd, mini);
}
