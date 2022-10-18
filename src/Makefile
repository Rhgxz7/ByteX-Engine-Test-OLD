FLAGS = -std=c++20 -O2
LDFLAGS = -lglfw -ldl -lpthread -lX11 -lXrandr

ByteX: *.cpp *.hpp
	g++ $(FLAGS) -o ByteXBuild *.cpp $(LDFLAGS)

test: ByteX
	./ByteXBuild

clean:
	rm -f ByteX
