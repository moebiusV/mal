/* (c) 2019, moebius@a-lang.org -- make-a-lisp step0 */

#include "arrow.h"

void     aw_prompt(void);
string_t aw_getline(void);
string_t aw_read(string_t);
string_t aw_eval(string_t);
string_t aw_print(string_t);
string_t aw_read_eval_print(string_t);

void
aw_prompt(void) {
	printf("user> ");
}

/* must exit on EOF */
string_t
aw_getline(void) {
	ssize_t r;
	string_t s = { 0, NULL };

	r = getline(&s.val, &s.len, stdin);
	if (r == -1) {
		if (errno == EINVAL) {
			printf("aw_read:getline => EINVAL\n");
		} else if (errno == ENOMEM) {
			printf("aw_read:getline => ENOMEM\n");
		} else if (feof(stdin)) {
			printf("\n");
		} else {
			printf("aw_read:getline => unknown error %d\n", errno);
		}
		exit(0);
	}
	s.len = r;
	return s;
}

string_t
aw_read(string_t el) {
	return el;
}

string_t
aw_eval(string_t el) {
	return el;
}

string_t
aw_print(string_t el) {
	return el;
}

string_t
aw_read_eval_print(string_t el) {
	return aw_print(aw_eval(aw_read(el)));
}

int
main(int argc, char** argv) {
	string_t s, r;
	while(true) {
		aw_prompt();
		r = aw_read_eval_print(s = aw_getline());
		printf("%*s", r.len, r.val);

		free(r.val);
		if (r.val != s.val) { // avoid a double free
			free(s.val);
		}
	}
	return 0;
}
