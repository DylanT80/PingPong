CXX = g++
CXXFLAGS = -std=c++11 \
           -Iinclude -Ienet/build/include \
           -Llib -lraylib \
           -Lenet/build/lib -lenet \
           -framework CoreVideo -framework IOKit -framework Cocoa \
           -framework GLUT -framework OpenGL

SRC = src/main.cpp \
      src/Game.cpp \
      src/Ball.cpp \
      src/Paddle.cpp \
      src/CpuPaddle.cpp

OUT = main

default:
	$(CXX) $(SRC) -o $(OUT) $(CXXFLAGS)

clean:
	rm -f main