/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:49:01 by mayyildi          #+#    #+#             */
/*   Updated: 2022/07/09 21:56:20 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/*	Main functions...................................................*/
void	ft_error(void);
void	ft_exec(char *av, char **envp);
void	c_process(int *end, char **av, char **envp);
void	p_process(int *end, char **av, char **envp);
int		main(int ac, char **av, char **envp);

/*	Path functions...................................................*/
char	*get_path(char *cmd, char **envp);
char	*check_path(char *cmd, char *envp_path);

/*	Minilib functions................................................*/
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif