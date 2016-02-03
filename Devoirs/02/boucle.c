#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 1000; j++)
			system("ls -la > /dev/null");
		printf("Boucle  : %d\n", i);
	}

	return 0;
}