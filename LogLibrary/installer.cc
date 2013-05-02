//fixare che crei la cartella se non la trova
//vedere se fopen si può usare

using namespace std;
#include <stdio.h>

int main()
{
	FILE * pthread1log;
	FILE * pthread2log;
	FILE * pthread3log;
	FILE * pthread4log;
	pthread1log = fopen ("logfiles/thread1.log","w");
	if (pthread1log!=NULL)
	{
		fputs ("Installazione file log relativa a thread1 riuscita!",pthread1log);
		fclose (pthread1log);
	}
	pthread2log = fopen ("logfiles/thread2.log","w");
	if (pthread2log!=NULL)
	{
		fputs ("Installazione file log relativa a thread2 riuscita!",pthread2log);
		fclose (pthread2log);
	}
	pthread3log = fopen ("logfiles/thread3.log","w");
	if (pthread3log!=NULL)
	{
		fputs ("Installazione file log relativa a thread3 riuscita!",pthread3log);
		fclose (pthread3log);
	}
	pthread4log = fopen ("logfiles/thread4.log","w");
	if (pthread4log!=NULL)
	{
		fputs ("Installazione file log relativa a thread4 riuscita!",pthread4log);
		fclose (pthread4log);
	}

	return 0;
}