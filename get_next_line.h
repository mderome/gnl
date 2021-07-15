#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *dest, char *src);
int		ft_len(const char *str);
char	*ft_memcpy(char *dest, char *src);
int		check_return_line(char *save);
char	*ft_strndup(const char *src, int n);
int		recherch_return_line(char *s);

#endif
