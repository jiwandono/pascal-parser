#ifndef PARSER_H
#define	PARSER_H

#include <stdlib.h>

#include "common.h"
#include "tokenizer.h"

int accept(int s) {
	if(symbol == s) {
		printf("%s ", get_token_string(s));
		get_symbol();
		return 1;
	}
	return 0;
}

int expect(int s) {
	if(accept(s)) {
		return 1;
	}
	printf("%s ", get_token_string(s));
	printf("\nexpect: expecting %s, unexpected %s %s\n", get_token_string(s), get_token_string(symbol), buf);
	return 0;
}

/* ======= */

int constant(void) {
	printf("<CONSTANT>\n");

	if(accept(TOKEN_IDENTIFIER)) {
		;
	} else if(accept(TOKEN_INTCON)) {
		;
	} else if(accept(TOKEN_REALCON)) {
		;
	} else if(accept(TOKEN_CHARCON)) {
		;
	} else if(accept(TOKEN_STRINGT)) {
		;
	} else {
		printf("\nsyntax error: constant\n");
		return 0;
	}

	return 1;
}

int type(void) {
	printf("<TYPE>\n");

	if(accept(TOKEN_TYPECHAR)) {
		;
	} else if(accept(TOKEN_TYPESTRING)) {
		;
	} else if(accept(TOKEN_TYPEINT)) {
		;
	} else if(accept(TOKEN_TYPEREAL)) {
		;
	} else {
		printf("\nsyntax error: type\n");
		return 0;
	}


	return 1;
}

int variable(void) {
	printf("<VARIABLE>\n");

	if(accept(TOKEN_IDENTIFIER)) {
		if(accept(TOKEN_LBRACK)) {
			do {
				expression();
			} while(accept(TOKEN_COMMA));
			expect(TOKEN_RBRACK);
		} else if(accept(TOKEN_PERIOD)) {
			expect(TOKEN_IDENTIFIER);
		}

		return 1;
	}

	return 0;
}

void factor(void) {
	printf("<FACTOR>\n");

	if(variable()) {
		;
	} else if(constant()) {
		;
	} else if(accept(TOKEN_IDENTIFIER)) {
		if(accept(TOKEN_LPARENT)) {
			do {
				expression();
			} while(accept(TOKEN_COMMA));
			expect(TOKEN_RPARENT);
		}
	} else if(accept(TOKEN_LPARENT)) {
		expression();
		expect(TOKEN_RPARENT);
	} else if(accept(TOKEN_NOTSY)) {
		factor();
	}
}

void term(void) {
	printf("<TERM>\n");

	factor();
	if(accept(TOKEN_TIMES)) {
		factor();
	} else if(accept(TOKEN_RDIV)) {
		factor();
	} else if(accept(TOKEN_MODSY)) {
		factor();
	} else if(accept(TOKEN_ANDSY)) {
		factor();
	}
}

void simple_expression(void) {
	printf("<SIMPLE_EXPRESSION>\n");

	if(accept(TOKEN_PLUS)) {
		;
	} else if(accept(TOKEN_MINUS)) {
		;
	}

	term();

	if(accept(TOKEN_PLUS)) {
		term();
	} else if(accept(TOKEN_MINUS)) {
		term();
	} else if(accept(TOKEN_ORSY)) {
		term();
	}
}

void expression(void) {
	printf("<EXPRESSION>\n");

	simple_expression();
	if(accept(TOKEN_EQL)) {
		simple_expression();
	} else if(accept(TOKEN_LSS)) {
		simple_expression();
	} else if(accept(TOKEN_GTR)) {
		simple_expression();
	} else if(accept(TOKEN_NEQ)) {
		simple_expression();
	} else if(accept(TOKEN_LEQ)) {
		simple_expression();
	} else if(accept(TOKEN_GEQ)) {
		simple_expression();
	}
}

void parameter_list(void) {
	printf("<PARAMETER_LIST>\n");

	if(accept(TOKEN_LPARENT)) {
		do {
			accept(TOKEN_VARSY);
			expect(TOKEN_IDENTIFIER);
			while(accept(TOKEN_COMMA)) {
				expect(TOKEN_IDENTIFIER);
			}
			expect(TOKEN_COLON);
			type();
		} while(accept(TOKEN_SEMICOLON));
		expect(TOKEN_RPARENT);
	}
}

void statement(void) {
	printf("<STATEMENT>\n");

	if(accept(TOKEN_IDENTIFIER)) {
		expect(TOKEN_BECOMES);
		expression();
	} else if(accept(variable())) {
		expect(TOKEN_BECOMES);
		expression();
	} else if(accept(TOKEN_IDENTIFIER)) {
		if(accept(TOKEN_LPARENT)) {
			do {
				expression();
			} while(accept(TOKEN_COMMA));
			expect(TOKEN_RPARENT);
		}
	} else if(accept(TOKEN_BEGINSY)) {
		do {
			statement();
		} while(accept(TOKEN_SEMICOLON));
		expect(TOKEN_ENDSY);
	} else if(accept(TOKEN_IFSY)) {
		expression();
		expect(TOKEN_THENSY);
		statement();
		if(accept(TOKEN_ELSESY)) {
			statement();
		}
	} else if(accept(TOKEN_CASESY)) {
		expression();
		expect(TOKEN_OFSY);
		while(constant()) {
			while(accept(TOKEN_COMMA)) {
				constant();
			}
			expect(TOKEN_COLON);
			statement();
		}
		expect(TOKEN_ENDSY);
	} else if(accept(TOKEN_WHILESY)) {
		expression();
		expect(TOKEN_DOSY);
		statement();
	} else if(accept(TOKEN_REPEATSY)) {
		do {
			statement();
		} while(accept(TOKEN_SEMICOLON));
		expect(TOKEN_UNTILSY);
		expression();
	} else if(accept(TOKEN_FORSY)) {
		expect(TOKEN_IDENTIFIER);
		expect(TOKEN_BECOMES);
		expression();
		if(accept(TOKEN_TOSY) || accept(TOKEN_DOWNTOSY)) {
			expression();
			expect(TOKEN_DOSY);
			statement();
		} else {
			printf("\nsyntax error: for\n");
		}
	}
}

void block(void) {
	printf("<BLOCK>\n");

	if(accept(TOKEN_CONSTSY)) {
		expect(TOKEN_IDENTIFIER);
		do {
			expect(TOKEN_EQL);
			constant();
			expect(TOKEN_SEMICOLON);
		} while(accept(TOKEN_IDENTIFIER));
		block();
	} else if(accept(TOKEN_TYPESY)) {
		expect(TOKEN_IDENTIFIER);
		do {
			expect(TOKEN_EQL);
			type();
			expect(TOKEN_SEMICOLON);
		} while(accept(TOKEN_IDENTIFIER));
		block();
	} else if(accept(TOKEN_VARSY)) {
		expect(TOKEN_IDENTIFIER);
		do {
			while(accept(TOKEN_COMMA)) {
				expect(TOKEN_IDENTIFIER);
			}
			expect(TOKEN_COLON);
			type();
			expect(TOKEN_SEMICOLON);
		} while(accept(TOKEN_IDENTIFIER));
		block();
	} else if(accept(TOKEN_PROCEDURESY)) {
		expect(TOKEN_IDENTIFIER);
		parameter_list();
		expect(TOKEN_SEMICOLON);
		block();
		expect(TOKEN_SEMICOLON);
		block();
	} else if(accept(TOKEN_FUNCTIONSY)) {
		expect(TOKEN_IDENTIFIER);
		parameter_list();
		expect(TOKEN_COLON);
		type();
		expect(TOKEN_SEMICOLON);
		block();
		expect(TOKEN_SEMICOLON);
		block();
	} else if(accept(TOKEN_BEGINSY)) {
		do {
			statement();
		} while(accept(TOKEN_SEMICOLON));
		expect(TOKEN_ENDSY);
	} else {
		printf("\nblock: syntax error\n");
	}
}

void program(void) {
	printf("<PROGRAM>\n");
	get_symbol();
	expect(TOKEN_PROGRAMSY);
	expect(TOKEN_IDENTIFIER);
	expect(TOKEN_LPARENT);
	do {
		expect(TOKEN_IDENTIFIER);
	} while(accept(TOKEN_COMMA));
	expect(TOKEN_RPARENT);
	expect(TOKEN_SEMICOLON);
	block();
	expect(TOKEN_PERIOD);
}

#endif
