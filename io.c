#include "io.h"
#include <stdio.h>
#include <string.h>

//
// Private
//
static void empty_stream()
{
	int c;

	while ((c = getchar()) != EOF && c != '\n')
		;
}

//
// Public
//
int read_line(char *buf, int n)
{
	int buf_size;

	if (!fgets(buf, n, stdin))
	{
		empty_stream();
		return 0; // overflow
	}

	buf_size = strlen(buf);
	if (buf[buf_size - 1] != '\n')
	{
		empty_stream();
		return 0; // overflow
	}

	// remove new line
	buf[buf_size - 1] = '\0';
	return buf_size - 1;
}

void printOut(result_t *buf, printFunc func1, printFunc func2, printFunc func3, int n, char header[], char printOut1[], char printOut2[], char printOut3[])
{

	char sizePrintout[] = "Size";
	char timePrintout[] = "Time";
	printf("\n=========================================================================================\n\n");

	printf("%50s \n \n", header);
	printf("%15s", sizePrintout);
	printf("%15s", timePrintout);
	printf("%12s", printOut1);
	printf("%17s", printOut2);
	printf("%13s \n", printOut3);

	int size = SIZE_START;
	for (int i = 0; i < n; i++)
	{

		printf("%15d  ", size);
		printf("%15lf", buf[i].time);
		printf("%15e", func1(buf[i].time, n));
		printf("%15e", func2(buf[i].time, n));
		printf("%15e", func3(buf[i].time, n));
		printf("\n");

		size = size * 2;
	}

	printf("\n=========================================================================================\n\n");
}
