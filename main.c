#include "./minilibx/mlx.h"
#include "fdf.h"
#include <stdlib.h>

void ft_init(t_fdf *fdf)
{
	if (tab_filler(fdf) == -1)
	{
		ft_putendl("Error");
		return ;
	}
	ft_printer(fdf);
}

void ft_printer(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->lines)
	{
		j = 0;
		while(j < fdf->chars)
		{
			printf("%d ", fdf->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_fdf fdf;

	if (ac != 2)
		ft_putendl("usage: fdf \"name of file\"\n");
	if (!(fdf.fd = open(av[1], O_RDONLY)))
		ft_putendl("error\n");
	fdf.name = av[1];
	ft_init(&fdf);
    draw_init(&fdf);
    
    
    
    
	return (0);
}
