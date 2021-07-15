#include "get_next_line.h"

char	*get_new_save(char *save)
{
	int		i;
	int		j;
	char	*tmp_save;

	i = recherch_return_line(save);
	tmp_save = save;
	free(save);
	save = malloc(sizeof(char) * (i + 1));
	if (!save)
		return (NULL);
	j = 0;
	while (tmp_save[i + j])
	{
		save[j] = tmp_save[i + j];
		j++;
	}
	save[j] = '\0';
	return (save);
}

char	*get_line(char *save)
{
	int		i;
	char	*line;

	if (!save || save[0] == 0)
		return (NULL);
	i = recherch_return_line(save);
	printf("test i : [%d]\n", i);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

char	*final_test(char *line, int check)
{
	printf("ceci est line au test final : [%s]\n", line);
	if (check == 0 && line == NULL)
		return (NULL);
	else
		return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	int			check;
	char		*line;

	if (fd <= -1 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	check = 1;
	if (!save)
		save = NULL;
	printf("ceci est save en entrant : [%s]\n", save);
	while (!check_return_line(save) && check)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check < 0)
		{
			free(save);
			save = NULL;
			return (NULL);
		}
		buffer[check] = '\0';
		save = ft_strjoin(save, buffer);
		printf("test\n");
	}
	line = get_line(save);
	printf("test2\n");
	save = get_new_save(save);
	return (final_test(line, check));
}
