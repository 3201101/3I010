#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>

/**
 * Éxecute la commande système passée en paramètre et affiches les statistiques temporelles détaillées de celle-ci.
 * @param commande Commande système à exécuter
 */
void lance_commandes_time(const char* commande)
{
	char s[150 + strlen(commande)];
	strcpy(s, "time -f \"# Statistiques de la commande ' %C '\n\t> Temps total réel :\t%es\n\t> Temps utilisateur :\t%Us\n\t> Temps système :\t%Ss\n\" ");
	strcat(s, commande);
	system(s);
}

/**
 * Éxecute la commande système passée en paramètre et affiche sa durée d'exécution en microsecondes.
 * @param commande Commande système à exécuter
 */
void lance_commandes(const char* commande)
{
	/* Évaluation du temps */
	struct timeval t1, t2;
	struct timezone t;
	long long diff;
	gettimeofday(&t1, &t);

	/* Éxecution de la commande */
	if(system(commande) == -1)
		printf("La commande a provoqué une erreur.\n");
	
	/* Évaluation du temps */
	gettimeofday(&t2, &t);
	diff = (t2.tv_sec - t1.tv_sec) * 1000000L + (t2.tv_usec-t1.tv_usec);
	printf("Durée d'exécution = %lld µs\n", diff);
}

int main(int argc, char const *argv[])
{
	/* Ne pas faire lance_commandes(argv[0]) */
	for(int i = 1; i < argc; i++)
		lance_commandes_time(argv[i]);

	return 0;
}