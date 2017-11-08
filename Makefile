CPPFLAGS = -std=c++14
SFML_FLAGS = -lsfml-window -lsfml-graphics -lsfml-system
EXEC = tic_tac_toe.exec



output: ./build/main.o
	g++ $(CPPFLAGS) ./build/main.o -o $(EXEC) $(SFML_FLAGS) -fsanitize=address -g -Wall

./build/main.o: ./src/main.cpp
	g++ $(CPPFLAGS) -c ./src/main.cpp -o  ./build/main.o -g -Wall

clean:
	rm ./build/*.o ./$(EXEC) 

