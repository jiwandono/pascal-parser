#ifndef TOKEN_H
#define	TOKEN_H

#define n_elems(x)			(sizeof(x) / sizeof(x[0]))
#define append_buffer(c)	buf[bufp++] = (c)
#define set_symbol(sym)		symbol = (sym)

#define TOKEN_INVALID		-1

#define TOKEN_INTCON		101
#define TOKEN_REALCON		102
#define TOKEN_CHARCON		103
#define TOKEN_STRINGT		104

#define TOKEN_PLUS			201
#define TOKEN_MINUS			202
#define TOKEN_TIMES			203
#define TOKEN_RDIV			204

#define TOKEN_EQL			301
#define TOKEN_LSS			302
#define TOKEN_LEQ			303
#define TOKEN_NEQ			304
#define TOKEN_GTR			305
#define TOKEN_GEQ			306

#define TOKEN_LPARENT		401
#define TOKEN_RPARENT		402
#define TOKEN_LBRACK		403
#define TOKEN_RBRACK		404

#define TOKEN_COMMA			501
#define TOKEN_PERIOD		502
#define TOKEN_SEMICOLON		503
#define TOKEN_COLON			504
#define TOKEN_BECOMES		505

#define TOKEN_IDENTIFIER	901
#define TOKEN_ANDSY			902
#define TOKEN_ARRAYSY		903
#define TOKEN_BEGINSY		904
#define TOKEN_CASESY		905
#define TOKEN_TYPECHAR		906
#define TOKEN_CONSTSY		907
#define TOKEN_DOSY			908
#define TOKEN_DOWNTOSY		909
#define TOKEN_ELSESY		910
#define TOKEN_ENDSY			911
#define TOKEN_FORSY			912
#define TOKEN_FUNCTIONSY	913
#define TOKEN_IFSY			914
#define TOKEN_TYPEINT		915
#define TOKEN_NOTSY			916
#define TOKEN_OFSY			917
#define TOKEN_ORSY			918
#define TOKEN_PROCEDURESY	919
#define TOKEN_PROGRAMSY		920
#define TOKEN_TYPEREAL		921
#define TOKEN_RECORDSY		922
#define TOKEN_REPEATSY		923
#define TOKEN_TYPESTRING	924
#define TOKEN_THENSY		925
#define TOKEN_TOSY			926
#define TOKEN_TYPESY		927
#define TOKEN_UNTILSY		928
#define TOKEN_VARSY			929
#define TOKEN_WHILESY		930
#define TOKEN_MODSY			931

#define TOKEN_EOF			2001

FILE *f;
int c;
int symbol;
int char_not_consumed = 0;

char buf[128];
int bufp;
int identifier_id;

char identifier_table[128][128];
int identifier_table_length = 0;

int tokens[] = {
	TOKEN_INTCON,
	TOKEN_REALCON,
	TOKEN_CHARCON,
	TOKEN_STRINGT,

	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_TIMES,
	TOKEN_RDIV,

	TOKEN_EQL,
	TOKEN_LSS,
	TOKEN_LEQ,
	TOKEN_NEQ,
	TOKEN_GTR,
	TOKEN_GEQ,

	TOKEN_LPARENT,
	TOKEN_RPARENT,
	TOKEN_LBRACK,
	TOKEN_RBRACK,

	TOKEN_COMMA,
	TOKEN_PERIOD,
	TOKEN_SEMICOLON,
	TOKEN_COLON,
	TOKEN_BECOMES,

	TOKEN_IDENTIFIER,
	TOKEN_ANDSY,
	TOKEN_ARRAYSY,
	TOKEN_BEGINSY,
	TOKEN_CASESY,
	TOKEN_TYPECHAR,
	TOKEN_CONSTSY,
	TOKEN_DOSY,
	TOKEN_DOWNTOSY,
	TOKEN_ELSESY,
	TOKEN_ENDSY,
	TOKEN_FORSY,
	TOKEN_FUNCTIONSY,
	TOKEN_IFSY,
	TOKEN_TYPEINT,
	TOKEN_NOTSY,
	TOKEN_OFSY,
	TOKEN_ORSY,
	TOKEN_PROCEDURESY,
	TOKEN_PROGRAMSY,
	TOKEN_TYPEREAL,
	TOKEN_RECORDSY,
	TOKEN_REPEATSY,
	TOKEN_TYPESTRING,
	TOKEN_THENSY,
	TOKEN_TOSY,
	TOKEN_TYPESY,
	TOKEN_UNTILSY,
	TOKEN_VARSY,
	TOKEN_WHILESY,
	TOKEN_MODSY,

	TOKEN_EOF
};

char *token_string[] = {
	"INTCON",
	"REALCON",
	"CHARCON",
	"STRINGT",

	"PLUS",
	"MINUS",
	"TIMES",
	"RDIV",

	"EQL",
	"LSS",
	"LEQ",
	"NEQ",
	"GTR",
	"GEQ",

	"LPARENT",
	"RPARENT",
	"LBRACK",
	"RBRACK",

	"COMMA",
	"PERIOD",
	"SEMICOLON",
	"COLON",
	"BECOMES",

	"IDENT",
	"ANDSY",
	"ARRAYSY",
	"BEGINSY",
	"CASESY",
	"TYPECHAR",
	"CONSTSY",
	"DOSY",
	"DOWNTOSY",
	"ELSESY",
	"ENDSY",
	"FORSY",
	"FUNCTIONSY",
	"IFSY",
	"TYPEINT",
	"NOTSY",
	"OFSY",
	"ORSY",
	"PROCEDURESY",
	"PROGRAMSY",
	"TYPEREAL",
	"RECORDSY",
	"REPEATSY",
	"TYPESTRING",
	"THENSY",
	"TOSY",
	"TYPESY",
	"UNTILSY",
	"VARSY",
	"WHILESY",
	"MODSY",

	"EOF"
};

char *keyword[] = {
	"and",
	"array",
	"begin",
	"case",
	"char",
	"const",
	"do",
	"downto",
	"else",
	"end",
	"for",
	"function",
	"if",
	"integer",
	"not",
	"of",
	"or",
	"procedure",
	"program",
	"real",
	"record",
	"repeat",
	"string",
	"then",
	"to",
	"type",
	"until",
	"var",
	"while",
	"mod"
};

int token_keyword[] = {
	TOKEN_ANDSY,
	TOKEN_ARRAYSY,
	TOKEN_BEGINSY,
	TOKEN_CASESY,
	TOKEN_TYPECHAR,
	TOKEN_CONSTSY,
	TOKEN_DOSY,
	TOKEN_DOWNTOSY,
	TOKEN_ELSESY,
	TOKEN_ENDSY,
	TOKEN_FORSY,
	TOKEN_FUNCTIONSY,
	TOKEN_IFSY,
	TOKEN_TYPEINT,
	TOKEN_NOTSY,
	TOKEN_OFSY,
	TOKEN_ORSY,
	TOKEN_PROCEDURESY,
	TOKEN_PROGRAMSY,
	TOKEN_TYPEREAL,
	TOKEN_RECORDSY,
	TOKEN_REPEATSY,
	TOKEN_TYPESTRING,
	TOKEN_THENSY,
	TOKEN_TOSY,
	TOKEN_TYPESY,
	TOKEN_UNTILSY,
	TOKEN_VARSY,
	TOKEN_WHILESY,
	TOKEN_MODSY
};

char * get_token_string(int token_id) {
	int i = 0;
	int found = 0;

	while(!found && i < n_elems(tokens)) {
		if(token_id == tokens[i]) {
			found = 1;
		} else {
			i++;
		}
	}

	if(found) {
		return token_string[i];
	} else {
		return "INVALID";
	}
}

int get_keyword_id(char *ident) {
	int i = 0;
	int found = 0;

	while(!found && i < n_elems(token_keyword)) {
		if(strcasecmp(keyword[i], ident) == 0) {
			found = 1;
		} else {
			i++;
		}
	}

	if(found) {
		return token_keyword[i];
	} else {
		return TOKEN_IDENTIFIER;
	}
}

int get_identifier_id(char identifier_table[128][128], char *identifier, int identifier_table_length) {
	int found = 0;
	int i = 0;

	while(!found && i < identifier_table_length) {
		if(strcasecmp(identifier_table[i], identifier) == 0) {
			found = 1;
		} else {
			i++;
		}
	}

	if(found) {
		return i;
	} else {
		return -1;
	}
}

void init_tokenizer() {
	memset(identifier_table, 0, 128*128);
}

void get_symbol(void) {
	memset(buf, 0, 128);
	bufp = 0;

	if(char_not_consumed > 0) {
		char_not_consumed = 0;
	} else {
		c = fgetc(f);
	}

	if(isspace(c)) {
		do {
			c = fgetc(f);
		} while(isspace(c) && !feof(f));
	}

	if(isdigit(c)) {
		while(isdigit(c)) {
			append_buffer(c);
			c = fgetc(f);
		}
		set_symbol(TOKEN_INTCON);

		if(c == '.') {
			append_buffer(c);
			set_symbol(TOKEN_INVALID);

			c = fgetc(f);
			while(isdigit(c)) {
				append_buffer(c);
				c = fgetc(f);
				set_symbol(TOKEN_REALCON);
			}

			if(c == 'e' || c == 'E') {
				append_buffer(c);
				set_symbol(TOKEN_INVALID);

				c = fgetc(f);
				if(c == '+' || c == '-') {
					append_buffer(c);

					c = fgetc(f);
					while(isdigit(c)) {
						append_buffer(c);
						c = fgetc(f);
						set_symbol(TOKEN_REALCON);
					}
				}
			}
		}

		char_not_consumed = 1;
	}
	else if(c == '\'') {
		int length = 0;
		append_buffer(c);

		c = fgetc(f);
		while(c != '\'') {
			append_buffer(c);
			c = fgetc(f);
			length++;
		}
		append_buffer(c);
		set_symbol(length > 1 ? TOKEN_STRINGT : TOKEN_CHARCON);
	}
	else if(c == '+') {
		set_symbol(TOKEN_PLUS);
		append_buffer(c);
	}
	else if(c == '-') {
		set_symbol(TOKEN_MINUS);
		append_buffer(c);
	}
	else if(c == '*') {
		set_symbol(TOKEN_TIMES);
		append_buffer(c);
	}
	else if(c == '/') {
		set_symbol(TOKEN_RDIV);
		append_buffer(c);
	}
	else if(c == '=') {
		set_symbol(TOKEN_EQL);
		append_buffer(c);
	}
	else if(c == '<') {
		set_symbol(TOKEN_LSS);
		append_buffer(c);

		c = fgetc(f);
		if(c == '=') {
			set_symbol(TOKEN_LEQ);
			append_buffer(c);
		} else if(c == '>') {
			set_symbol(TOKEN_NEQ);
			append_buffer(c);
		} else {
			char_not_consumed = 1;
		}
	}
	else if(c == '>') {
		set_symbol(TOKEN_GTR);
		append_buffer(c);

		c = fgetc(f);
		if(c == '=') {
			set_symbol(TOKEN_GEQ);
			append_buffer(c);
		} else {
			char_not_consumed = 1;
		}
	}
	else if(c == '(') {
		set_symbol(TOKEN_LPARENT);
		append_buffer(c);
	}
	else if(c == ')') {
		set_symbol(TOKEN_RPARENT);
		append_buffer(c);
	}
	else if(c == '[') {
		set_symbol(TOKEN_LBRACK);
		append_buffer(c);
	}
	else if(c == ']') {
		set_symbol(TOKEN_RPARENT);
		append_buffer(c);
	}
	else if(c == ',') {
		set_symbol(TOKEN_COMMA);
		append_buffer(c);
	}
	else if(c == '.') {
		set_symbol(TOKEN_PERIOD);
		append_buffer(c);
	}
	else if(c == ';') {
		set_symbol(TOKEN_SEMICOLON);
		append_buffer(c);
	}
	else if(c == ':') {
		set_symbol(TOKEN_COLON);
		append_buffer(c);

		c = fgetc(f);
		if(c == '=') {
			set_symbol(TOKEN_BECOMES);
			append_buffer(c);
		} else {
			char_not_consumed = 1;
		}
	}
	else if(isalpha(c) || c == '_') {
		set_symbol(TOKEN_IDENTIFIER);
		append_buffer(c);

		c = fgetc(f);
		while(isalnum(c) || c == '_') {
			append_buffer(c);
			c = fgetc(f);
		}
		set_symbol(get_keyword_id(buf));

		if(symbol == TOKEN_IDENTIFIER) {
			if((identifier_id = get_identifier_id(identifier_table, buf, identifier_table_length)) < 0) {
				identifier_id = identifier_table_length;
				strcpy(identifier_table[identifier_table_length++], buf);
			}
		}

		char_not_consumed = 1;
	} else if(feof(f)) {
		set_symbol(TOKEN_EOF);
	} else {
		append_buffer(c);
		set_symbol(TOKEN_INVALID);
	}
}

#endif	/* TOKEN_H */
