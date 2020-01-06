/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:57:15 by abarot            #+#    #+#             */
/*   Updated: 2020/01/06 13:35:27 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLBOX_H
# define TOOLBOX_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 10
int					get_next_line(int fd, char **line);
int					ft_hasnewline(char *str);
size_t				ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strjoinfree(char *s1, char *s2, int var_free);
void				ft_createkeep(char *keep, char *line);
int					ft_isdigit(int c);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *s);
int					ft_check_in_set_char(char to_test, char *dataset);
void				*ft_calloc(size_t num, size_t size);
#endif