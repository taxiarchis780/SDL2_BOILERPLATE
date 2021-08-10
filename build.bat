g++ -c src/*.* -std=c++14 -g -Wall -m64 -I include -I D:\\SDL2\\include && g++ *.o -o bin/debug/main -L D:\\SDL2\\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
