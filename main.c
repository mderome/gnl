#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		printf("ERROR");
		return (0);
	}
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
