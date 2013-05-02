#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	char fname[21];
	time_t epoch;
	struct tm *date;
	FILE *fnew;	

	epoch = time(NULL);
	date  = localtime(&epoch);
	strftime(fname, 21, "%d_%h_%Y_%H:%M:%S", date);

	fnew = fopen(fname, "a+"); 
	if (fnew == NULL) {
		printf("File %s not opend %s.\n", fname);
		return 1;
	}
        printf("File %s opend.\n", fname);
	if (fclose(fnew) != 0)
		printf("File %s not closed. The system "
				"should do it for us.\n", fname);
	else
		printf("File %s closed.\n", fname);
	return 0;
}