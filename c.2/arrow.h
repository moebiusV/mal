/* (c) 2019, moebius@a-lang.org -- make-a-lisp step1 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

const int true = 1;
const int false = 0;

const int aw_type_nil = 0;
const int aw_type_list = 1;
const int aw_type_quote = 2;
const int aw_type_symbol = 3;
const int aw_type_string = 4;
const int aw_type_number = 5;

typedef struct {
	size_t len;
	char* val;
} string_t;

typedef struct {
	int type;
	ast_node_t *next;
	union {
		int64_t i;
		double f;
		string_t s;
		ast_node_t *n;
	} value;
} ast_node_t;
