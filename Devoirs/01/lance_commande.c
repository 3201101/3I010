#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if(argc <= 0)
	{
		printf("Erreur, nombre d'arguments insuffisant.");

		return 1;
	}

	for (int i = 0; i < argc; i++	)
	{
		lance_commande(argv[i])
	}

	printf("Maximum : %d\n", max);

	return 0;
}

void lance_commande(char* commande)
{
	if(system(commande) == -1)
		printf("Erreur.\n");
}