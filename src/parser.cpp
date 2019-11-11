#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>

int main (int argc, char *argv[]) {

	const char* short_options = "hs::f:";

	const struct option long_options[] = {
		{"help", no_argument, 0, 'h'},
		{"size", optional_argument, 0, 's'},
		{"file", required_argument, 0, 'f'},
		{0, 0, 0, 0}
	};

	int result;

	int option_index;

	int no_repeat_h = true;

	while ((result=getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
		switch (result) {
			case 'h': {
				if (no_repeat_h) {
					printf("Argument: Help\n");
					no_repeat_h = false;
				};
				break;
			};
			case 's': {
				if (optarg == NULL) {
					printf("Argument: Size. Value: none.\n");
				} else if (isdigit(*optarg)) {
					printf("Argument: Size. Value: %s.\n", optarg);
				} else if (optarg != NULL) {
					printf("Argument: Size. Value: unknown.\n");
				};
				break;
			};
			case 'f': {
				printf("Argument: File. Value: %s.\n", optarg);
				break;
			};
			case '?': default: {
				printf("Unknown argument!\n");
				break;
			};
		};
	};
	return 0;
};
