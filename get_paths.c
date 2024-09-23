/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:55:27 by mayyildi          #+#    #+#             */
/*   Updated: 2022/07/09 21:53:09 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*	This function does the following tasks:							*/
/*	• Step 1: Separate PATH str into individual paths w/ ft_split()	*/
/*	• Step 2: Add '/' at the end of paths using ft_strjoin()		*/
/*	• Step 3: a) Add cmd at the end of paths using ft_strjoin();	*/
/*			  b) The resulting path is stored in cmd_path.			*/
/*	• Step 4: Check if path is valid with access()					*/
/*	• Step 5: If file exists or executable, return cmd_path			*/
/*	• Step 6: Loop till valid path is found, meanwhile free current	*/
/*			  cmd_path and increment i, to try next path			*/
/*	• Step 7: If no valid path is found, return "Error"				*/
char	*check_path(char *cmd, char *envp_path)
{
	char	*cmd_path;
	char	**paths;
	int		i;

	paths = ft_split(envp_path, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return ("Error: invalid path");
}

/*	This function does the following tasks:							*/
/*	• Step 1: Parse env to find line containing "PATH=" [strnstr()]	*/
/*	• Step 2: If line found, store it into char *envp_path & break	*/
/*	• Step 3: Else, go to next line of env till PATH line found		*/
/*	• Step 4: Send the output to check_path() function				*/
char	*get_path(char *cmd, char **envp)
{
	char	*envp_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		envp_path = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
		if (envp_path)
		{
			envp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			break ;
		}
		i++;
	}
	return (check_path(cmd, envp_path));
}
