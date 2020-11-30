
test:
	if [ ! -f acutest.h ] ; then \
		curl https://raw.githubusercontent.com/mity/acutest/master/include/acutest.h > acutest.h; \
	fi && \
	gcc test.c -o test && \
	./test -v;
	rm -f test;