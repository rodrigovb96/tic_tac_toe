CPPFLAGS = -std=c++14
SFML_FLAGS = -lsfml-window -lsfml-graphics -lsfml-system
EXEC = tic_tac_toe.exec



output: main.o
	g++ $(CPPFLAGS) ./build/main.o -o $(EXEC) $(SFML_FLAGS) -fsanitize=address

main.o: ./src/main.cpp
	g++ $(CPPFLAGS) -c ./src/main.cpp  && mv ./main.o ./build

clean:
	rm ./build/*.o ./$(EXEC) 

