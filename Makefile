INCLUDE = Header.h
SRC = Source.cpp Source_m.cpp Source_d.cpp kursach.cpp

all: $(INCLUDE)
	g++ $(SRC)
	./a.out

clear:
	rm -f $(SRCO)

re: clear all

.PHONY: all clear re
