PROG = boxscanner
CC = g++
OBJ = wristscanner.o box.o main.o

main: $(OBJ); $(CC) $(OBJ) -o $(PROG)

wristscanner.o: wristscanner.cpp wristscanner.h ; $(CC) -c wristscanner.cpp

box.o: box.cpp wristscanner.h ; $(CC) -c box.cpp

main.o: main.cpp ; $(CC) -c main.cpp

clean: ; rm $(PROG) *.o
