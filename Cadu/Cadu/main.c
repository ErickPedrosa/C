#include <stdio.h>

int main()
{
	int num, espacos = 0;
	
	scanf("%d", &num);
	


	for (int i = 1; i <= num; i++)
	{
		
			espacos = (num - i) / 2;

			for (int i = 0; i < espacos; i++)
			{
				printf("\t");
			}

			for (int j = 1; j <= i; j++)
			{
				printf("*\t");
			}

			for (int i = 0; i < espacos; i++)
			{
				printf("\t");
			}

			printf("\n");
		

	}


}