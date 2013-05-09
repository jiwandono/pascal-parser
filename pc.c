#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "common.h"
#include "tokenizer.h"
#include "parser.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return EXIT_INVALID_PARAM;
	}

	printf("Scanning %s...\n", argv[1]);

	f = fopen(argv[1], "r");

	/* Old main program
	do {
		get_symbol();

		if(!feof(f)) {
			if(symbol == TOKEN_INVALID) {
				printf("Invalid token: %s\n", buf);
				return EXIT_INVALID_TOKEN;
			} else if(symbol != WHITESPACE) {
				if(symbol == TOKEN_IDENTIFIER) {
					printf("%12s %3d %s\n", get_token_string(symbol), identifier_id, buf);
				} else {
					printf("%12s     %s\n", get_token_string(symbol), buf);
				}
			}
		}
	} while(!feof(f));
	 */

	program();

	fclose(f);

	return EXIT_SUCCESS;
}
