/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:48:14 by khee-seo          #+#    #+#             */
/*   Updated: 2021/01/22 02:52:16 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

char	*ft_strdup(char *src);
int		ft_strchr(char const *s, int c);
int		ft_strlen(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*line_split(char **backup, char *line, int cut_index);
char	*line_cpy(char *backup, char *line);
char	*save(char *backup, char *buf);
int		get_next_line(int fd, char **line);

#endif
