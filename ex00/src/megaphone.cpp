#include <iostream>

// use to upper? simplify it?
int	main(int ac, char **av)
{
	int i;
	int j;

	i = 1;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					av[i][j] -= 32;
				j++;
			}
			if (av[i + 1])
				std::cout << av[i] << " ";
			else
				std::cout << av[i] << std::endl;
			i++;
		}
	}
	return (0);
}