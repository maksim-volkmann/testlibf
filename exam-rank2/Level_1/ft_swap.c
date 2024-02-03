// Assignment name  : ft_swap
// Expected files   : ft_swap.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that swaps the contents of two integers the adresses of which
// are passed as parameters.

// Your function must be declared as follows:

// void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#include <stdio.h>

int main(void)
{
	int x = 10;
	int y = 20;

	// Print the values of x and y before swapping
	printf("Before swap: x = %d, y = %d\n", x, y);

	// Swap the values of x and y
	ft_swap(&x, &y);

	// Print the values of x and y after swapping
	printf("After swap: x = %d, y = %d\n", x, y);

	return 0;
}
