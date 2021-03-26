#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void	ft_check()
{
	char *arr;
	printf("%p\n", &arr[0]);
	arr = malloc(sizeof(char) * 5);

	int i = 0;
	while (i < 5)
	{
		arr[i] = '\0';
		i++;
		
	}
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[1]);
	free(arr);
	printf("%p\n", &arr[0]);
	printf("%p", &arr[1]);
}
int main(int argc, char const *argv[])
{
	ft_check();
	system("leaks a.out > leaks_result; cat leaks_result	| grep leaked && rm -rf leaks_result");
	return (0);

}