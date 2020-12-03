
test:
	if [ ! -f acutest.h ] ; then \
		curl https://raw.githubusercontent.com/mity/acutest/master/include/acutest.h > acutest.h; \
	fi && \
	gcc -W -Wbad-function-cast -Wcast-align -Wcast-qual -Wmissing-declarations -Wnested-externs -Wpointer-arith -Wwrite-strings -pedantic -Wformat -Werror=format-security -fstack-protector-strong test.c -o test --coverage && \
	./test -v && \
	gcovr  -r . --html --html-details -e "acutest.h" -o coverage/index.html;
	rm -f test test.gcda test.gcno;