all:
	gcc -o example example.cpp `sdl2-config --cflags --libs`
run:	
	./example