CPPFLAGS = -std=c++14
SFML_FLAGS = -lsfml-window -lsfml-graphics -lsfml-system

EXEC = tic_tac_toe.exec

output: main.o
	g++ $(CPPFLAGS) main.o -o $(EXEC) $(SFML_FLAGS)

main.o: main.cpp
	g++ $(CPPFLAGS) -c main.cpp

clean:
	rm *.o $(EXEC) 

