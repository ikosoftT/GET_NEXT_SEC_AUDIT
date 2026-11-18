/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoograme <yoograme@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:58:07 by yoograme          #+#    #+#             */
/*   Updated: 2026/11/18 13:16:59 by yoograme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*stash;
	struct s_list	*next;
}					t_list;

int					ft_strchr_bonus(char *str, char c);
char				*ft_strjoin_bonus(char *s1, char *s2);
char				*buffer_new_line_bonus(char *str);
char				*after_new_line_bonus(char *str);
char				*get_next_line(int fd);

#endif