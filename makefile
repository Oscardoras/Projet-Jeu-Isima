debug: src/main.c bin/game.o bin/level.o bin/matrix.o bin/viewport.o
	gcc -g -Wall -Wextra src/main.c bin/game.o bin/level.o bin/matrix.o bin/viewport.o -o game -lSDL2 -lSDL2_image -lm

bin/game.o: src/game.c
	gcc -g -Wall -Wextra -c src/game.c -o bin/game.o
bin/level.o: src/level.c
	gcc -g -Wall -Wextra -c src/level.c -o bin/level.o
bin/matrix.o: src/matrix.c
	gcc -g -Wall -Wextra -c src/matrix.c -o bin/matrix.o
bin/viewport.o: src/viewport.c
	gcc -g -Wall -Wextra -c src/viewport.c -o bin/viewport.o

release:
	gcc -O3 src/main.c src/game.c src/level.c src/matrix.c src/viewport.c -o game -lSDL2 -lSDL2_image -lm
	
clean:
	rm -r bin/*.o game 
