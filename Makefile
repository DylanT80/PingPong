default:
	g++ -std=c++11 \
	    -framework CoreVideo -framework IOKit -framework Cocoa \
	    -framework GLUT -framework OpenGL \
	    -Llib -Iinclude -lraylib \
	    src/main.cpp src/Game.cpp src/Ball.cpp src/Paddle.cpp src/CpuPaddle.cpp -o main
