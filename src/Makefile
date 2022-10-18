FLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -ldl -lpthread -lX11 -lXrandr -lGLEW -lGL

ByteX: *.cpp *.hpp
	g++ $(FLAGS) -o ByteXBuild *.cpp $(LDFLAGS) -I ./dependencies

test: ByteX
	./ByteXBuild

clean:
	rm -f ByteX
