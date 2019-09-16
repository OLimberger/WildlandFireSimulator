BUILDDIR?=build
CMAKE?=cmake

all:	test
.PHONY:	all

build:
	${CMAKE} --build ${BUILDDIR}
.PHONY:	build

test:	build
	cd ${BUILDDIR} && ctest -V
	./testing.sh
.PHONY:	test

clean:
	rm burn_map*.asc burndata*.csv
.PHONY:	clean
