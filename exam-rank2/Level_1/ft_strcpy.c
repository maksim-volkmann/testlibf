// Assignment name  : ft_strcpy
// Expected files   : ft_strcpy.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcpy (man strcpy).

// Your function must be declared as follows:

// char    *ft_strcpy(char *s1, char *s2);



char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s2[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	return (s1);
}

#include <stdio.h>

int	main()
{
	char s1[] = "Hello.";
	char s2[20];

	printf("Asnwer: %s\n", ft_strcpy(s1, s2));
	return (0);
}
