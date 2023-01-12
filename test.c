/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 23:37:45 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/01/09 23:37:45 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
// #include"libft/libft.h"
#include "../printf/ft_printf.h"
// we are using >> &

int max(int *arr)
{
	int max = 0;
	// int n = (sizeof(arr));
	// printf("sizeofa=%d",n);
	for (int i = 0; i < sizeof(arr); ++i) {
   	 if (max < arr[i]) {
    	  max = arr[i];
    	}
  }
return(max);
}
int maxbit(int a)
{
	int i = 0;
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return(i);
}

/* int main(int argc, char** argv)
{
	if (argc >1)
	{
		int a[] = {2,3,444,4,99999, 6327, 6716};
		char *base = "01";
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);
		printf("%d\t%d\n",num1,num2);
		ft_itoa_base(num1,base);
		printf("\n");
		ft_itoa_base(num2,base);
		printf("\nbase2\n");
	// printf("%d",num1>>2);
		ft_printf("num1 & num2= %d\n",num1 & num2);
		ft_printf("num1>>2 & num2>>2= %d\n",num1>>2 & num2>>2);
			printf("sizeof a=%lu\n",sizeof(a));

		printf("a.max()= %d\n", max(a));
		printf("maxbit(a)= %d\n", maxbit(max(a)));
		

	return (0);
	}
} */