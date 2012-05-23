PROGNAME = indexer
OBJECTS = src/main.o src/FileIndexer.o src/LexComparator.o src/Parser.o src/Timer.o src/Controller.o
HEADERS = src/FileIndexer.hpp src/LexComparator.h src/Types.h src/Parser.hpp src/Timer.hpp src/Controller.hpp
CC = g++
PARAMS = -Wall -std=c++0x
#VFLAGS = -g -O0
VALGRIND = valgrind --tool=memcheck --leak-check=full -v --dsymutil=yes
PROGARGS = Testdaten/Euler.txt Ausgabe.txt
DOXYGEN = doxygen
DOXYFILE = Doxyfile

LIBRARIES = #-l/opt/local/lib
INCLUDES = #-I/opt/local/include/gcc45/c++

all: ${OBJECTS} ${HEADER}
	${CC} ${CFLAGS} ${PARAMS} ${OBJECTS} ${INCLUDES} -o ${PROGNAME} ${LIBRARIES}

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

