#include <stdio.h>

// void	set_map_neg(int **s, int i, int j)
// {
// 	int jj;
// 	int	ii;

// 	ii = 0;
// 	while (ii < i)
// 	{
// 		jj = 0;
// 		while (jj < j)
// 		{
// 			s[ii][jj] = 1;
// 			jj++;
// 			printf("%d ", s[ii][jj]);
// 		}
// 		ii++;
// 	}
// }

void	*ft_memset(void *ptr, int val, size_t s)
{
	while (s != 0)
	{
		*((int *)ptr + s - 1) = val;
		s--;
	}
	return (ptr);
}


int main(int argc, char const *argv[])
{
	int arr[10][10];
	int i = 0;
	while(i < 10)
		ft_memset(arr[i++], -1, 10);
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;

}