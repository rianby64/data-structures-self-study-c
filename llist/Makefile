
test:
	if [ ! -f acutest.h ] ; then \
		curl https://raw.githubusercontent.com/mity/acutest/master/include/acutest.h > acutest.h; \
	fi && \
	gcc test.c -o test --coverage && \
	./test -v && \
	gcovr  -r . --html --html-details -o coverage/index.html;
	rm -f test test.gcda test.gcno;