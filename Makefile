CPPFLAGS = -std=c++1z
SFML_FLAGS = -lsfml-window -lsfml-graphics -lsfml-system
EXEC = tic_tac_toe.exec
MKDIR_P= mkdir -p build

output: ./build/main.o
	 g++ $(CPPFLAGS) build/main.o -o $(EXEC) $(SFML_FLAGS) -g -Wall

./build/main.o: ./src/main.cpp
	${MKDIR_P} &&  g++ $(CPPFLAGS) -c ./src/main.cpp -o  build/main.o -g -Wall

clean:
	rm build/*.o ./$(EXEC) 

