/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:48:44 by mayyildi          #+#    #+#             */
/*   Updated: 2022/07/09 21:53:19 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*	We're handling errors in this function. Here are the details:	*/
/*	• Step 1: Signal the problem using perror() [yellow text]		*/
/*	• Step 2: Exit the program using exit() function				*/
void	ft_error(void)
{
	perror("\033[0;33mError\e[0m");
	exit(EXIT_FAILURE);
}

/*	This function does several things, here's the breakdown:		*/
/*	• Step 1: Seperate cmd into char** using ft_split()				*/
/*	• Step 2: Try execve() in case we use absolute path of cmd		*/
/*	• Step 3: Otherwise, we get the path of the cmd using get_path()*/
/*	• Step 4: If path doesn't exist, free **cmd and send error msg	*/
/*	• Step 5: Check if execve() runs properly and execute it if yes	*/
void	ft_exec(char *av, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(av, ' ');
	execve(cmd[0], cmd, NULL);
	path = get_path(cmd[0], envp);
	i = 0;
	if (!path)
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		ft_error();
	}
	if (execve(path, cmd, envp) == -1)
		ft_error();
}

/*	This is our child process. It runs first and then the parent	*/
/*	process takes the relay. This function runs in 4 steps:			*/
/*	• Step 1: Check validity of infile								*/
/*	• Step 2: Make infile our STDIN and end[1] our STDOUT			*/
/*	• Step 3: Close our end[0] so that it doesn't wait for input	*/
/*	• Step 4: Execute our commands									*/
void	c_process(int *end, char **av, char **envp)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile < 0)
		ft_error();
	dup2(infile, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	ft_exec(av[2], envp);
}

/*	This is our parent process. It runs second and then the main	*/
/*	program continues. This function runs in 4 steps:				*/
/*	• Step 1: Check validity of outfile								*/
/*	• Step 2: Make outfile our STDOUT and end[0] our STDIN			*/
/*	• Step 3: Close our end[1] so that it doesn't wait for input	*/
/*	• Step 4: Execute our commands									*/
void	p_process(int *end, char **av, char **envp)
{
	int	outfile;

	outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
		ft_error();
	dup2(outfile, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	ft_exec(av[3], envp);
}

/*	Our main function works this way:								*/
/*	• Step 1: Declare ends and pid for child process				*/
/*	• Step 2: Check if arguments count is equal to 5				*/
/*	• Step 3: Pipe the two ends and call ft_error() if error found	*/
/*	• Step 4: Fork to create child process							*/
/*	• Step 5: Handle fork() error									*/
/*	• Step 6: Check if in child process, if yes run c_process()		*/
/*	• Step 7: Wait for child process to finish with waitpid()		*/
/*	• Step 8: Run p_process() [second end of pipe]					*/
/*	• Final step: Handle error message for incorrect ac	count		*/
int	main(int ac, char **av, char **envp)
{
	int		end[2];
	pid_t	c_pid;

	if (ac == 5)
	{
		if (pipe(end) == -1)
			ft_error();
		c_pid = fork();
		if (c_pid < 0)
			ft_error();
		else if (c_pid == 0)
			c_process(end, av, envp);
		waitpid(c_pid, NULL, 0);
		p_process(end, av, envp);
	}
	else
	{
		write(2, "\e[0;31mError: Can't execute.\e[0m\n", 33);
		write(2, "==========================\n", 27);
		write(2, "\033[0;34mPlease verify the arguments.\e[0m\n\n", 42);
	}
	return (0);
}
