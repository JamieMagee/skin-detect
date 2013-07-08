CFLAGS = `pkg-config opencv --cflags`
LIBS = `pkg-config opencv --libs`

% : src/%.cpp src/%.h
	g++ $(CFLAGS) -o bin/$@ $< -std=c++0x -O3 $(LIBS)
	
clean:
	rm -rf bin/*.o bin/YUV
