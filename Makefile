CC=gcc
CFLAGS=

CPP=g++
CPPFLAGS=

target: zhsr

zhsr:
	$(CPP) $(CPPFLAGS) -o zhsr src/test.cc -lallegro -lallegro_main

clean:
	rm zhsr
