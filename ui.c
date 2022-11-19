#include "ui.h"
#include "io.h"
#include "analyze.h"
#include "timemath.h"
#include <stdbool.h>
#include <stdio.h>

//
// Private
//
static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}

static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0)
	{
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i = 0; i < num_options; i++)
	{
		printf("    %c) %s\n", 'a' + i, options[i]);
	}
}

static void ui_menu()
{
	const char *options[] = {
		"Menu",
		"Exit\n",
		"Bubble sort best case",
		// TODO: complete menu
	};

	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}

void printResult(algorithm_t a, case_t c, result_t *buf)
{
	char *com1;
	char *com2;
	char *com3;
	char *casename;
	switch (a)
	{
	case bubble_sort_t:
		switch (c)
		{
		case best_t:
			com1 = "T/N";
			com2 = "T/N^2";
			com3 = "T/(N/2)";
			casename = "BUBBLE SORT: BEST CASE";
			printOut(buf, TtN, Np2, TtN2, ITERATIONS, casename, com1, com2, com3);
			break;

		case worst_t:
			com1 = "T/N";
			com2 = "T/N^2";
			com3 = "T/(N/2)";
			casename = "BUBBLE SORT: WORST CASE";
			printOut(buf, TtN, Np2, TtN2, ITERATIONS, casename, com1, com2, com3);
			break;
		case average_t:
			com1 = "T/N";
			com2 = "T/N^2";
			com3 = "T/(N/2)";
			casename = "BUBBLE SORT: AVARAGE CASE";
			printOut(buf, TtN, Np2, TtN2, ITERATIONS, casename, com1, com2, com3);
			break;
		}
		break;

	case quick_sort_t:
		switch (c)
		{
		case best_t:
			com1 = "T/N";
			com2 = "T/N^2";
			com3 = "T/(N/2)";
			casename = "QUICKSORT: BEST CASE";
			printOut(buf, TtN, Np2, TtN2, ITERATIONS, casename, com1, com2, com3);
			break;
		case worst_t:
			com1 = "T/N";
			com2 = "T/N^2";
			com3 = "T/(N/2)";
			casename = "QUICKSORT: WORST CASE";
			printOut(buf, TtN, Np2, TtN2, ITERATIONS, casename, com1, com2, com3);
			break;
		case average_t:
			com1 = "T/N";
			com2 = "T/N^2";
			com3 = "T/(N/2)";
			casename = "QUICKSORT: AVARAGE CASE";
			printOut(buf, TtN, Np2, TtN2, ITERATIONS, casename, com1, com2, com3);
			break;
		}
		break;

	case insertion_sort_t:
		switch (c)
		{
		case best_t:
			com1 = "T/N";
			com2 = "T/N^2";
			com3 = "T/(N/2)";
			casename = "INSERTION SORT: BEST CASE";
			printOut(buf, TtN, Np2, TtN2, ITERATIONS, casename, com1, com2, com3);
			break;
		case worst_t:
			com1 = "T/N";
			com2 = "T/N^2";
			com3 = "T/(N/2)";
			casename = "INSERTION SORT: WORST CASE";
			printOut(buf, TtN, Np2, TtN2, ITERATIONS, casename, com1, com2, com3);
			break;
		case average_t:
			com1 = "T/N";
			com2 = "T/N^2";
			com3 = "T/(N/2)";
			casename = "INSERTION SORT: AVARAGE CASE";
			printOut(buf, TtN, Np2, TtN2, ITERATIONS, casename, com1, com2, com3);
			break;
		}
		break;

	case binary_search_t:
		switch (c)
		{
		case best_t:
			com1 = "hello";
			com2 = "hello";
			com3 = "hello";
			break;
		case worst_t:
			com1 = "hello";
			com2 = "hello";
			com3 = "hello";
			break;
		case average_t:
			com1 = "hello";
			com2 = "hello";
			com3 = "hello";
			break;
		}
		break;

	case linear_search_t:
		switch (c)
		{
		case best_t:
			com1 = "hello";
			com2 = "hello";
			com3 = "hello";
			break;
		case worst_t:
			com1 = "hello";
			com2 = "hello";
			com3 = "hello";
			break;
		case average_t:
			com1 = "hello";
			com2 = "hello";
			com3 = "hello";
			break;
		}
		break;

	default:
		break;
	}
}

void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];

	show_menu = true;
	running = true;
	while (running)
	{
		if (show_menu)
		{
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice())
		{
		// House keeping
		case 'a':
			show_menu = true;
			break;
		case 'b':
			running = false;
			break;
		// Bubble sort
		case 'c':
			benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
			printResult(bubble_sort_t, best_t, result);
			printf("todo> implemenet BE + present results in FE\n");
			break;

		case 'd':
			benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
			printResult(bubble_sort_t, worst_t, result);
			printf("todo> implemenet BE + present results in FE\n");
			break;

		case 'e':
			benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
			printResult(bubble_sort_t, average_t, result);
			printf("todo> implemenet BE + present results in FE\n");
			break;

		// Insertion sort
		case 'f':
			benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
			printResult(insertion_sort_t, best_t, result);
			break;

		case 'g':
			benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
			printResult(insertion_sort_t, worst_t, result);
			break;

		case 'h':
			benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
			printResult(insertion_sort_t, average_t, result);
			break;
		// Quick sort
		case 'i':
			benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
			printResult(quick_sort_t, best_t, result);
			break;

		case 'j':
			benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
			printResult(quick_sort_t, worst_t, result);
			break;

		case 'k':
			benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
			printResult(quick_sort_t, average_t, result);
			break;

		// Linear search
		case 'l':
			benchmark(linear_search_t, best_t, result, RESULT_ROWS);
			printf("todo> implemenet BE + present results in FE\n");
			break;

		case 'm':
			benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
			printf("todo> implemenet BE + present results in FE\n");
			break;

		case 'n':
			benchmark(linear_search_t, average_t, result, RESULT_ROWS);
			printf("todo> implemenet BE + present results in FE\n");
			break;

		// Binary search
		case 'o':
			benchmark(binary_search_t, best_t, result, RESULT_ROWS);
			printf("todo> implemenet BE + present results in FE\n");
			break;

		case 'p':
			benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
			printf("todo> implemenet BE + present results in FE\n");
			break;

		case 'q':
			benchmark(binary_search_t, average_t, result, RESULT_ROWS);
			printf("todo> implemenet BE + present results in FE\n");
			break;
		// Invalid input
		default:
			show_menu = false;
			ui_invalid_input();
			break;
		}
	}
	ui_exit();
}
