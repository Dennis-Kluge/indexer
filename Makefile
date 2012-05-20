PROGNAME = indexer
OBJECTS = src/main.o src/FileIndexer.o 
HEADERS = src/FileIndexer.hpp 
CC = g++
PARAMS = -Wall #-std=c++0x
VFLAGS = -g -O0
VALGRIND = valgrind --tool=memcheck --leak-check=full -v
PROGARGS = -i schlossindex.txt DasSchloss/*
DOXYGEN = doxygen
DOXYFILE = Doxyfile

LIBRARIES = #-l/opt/local/lib
INCLUDES = #-I/opt/local/include/gcc45/c++

all: ${OBJECTS} ${HEADER}
	${CC} ${CFLAGS} ${OBJECTS} ${INCLUDES} -o ${PROGNAME} ${LIBRARIES}

.c.o:
	${CC} ${FLAGS} -c $<

clean:
	rm ${OBJECTS} ${PROGNAME}
	rm -rf docs/*

doku:
	${DOXYGEN} ${DOXYFILE}

valgrind:
	${VALGRIND} ./${PROGNAME} ${PROGARGS}

pp:
	 -pp *.h *.cpp && mv *.pdf doc/

