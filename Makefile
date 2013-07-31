CFLAGS = `pkg-config opencv --cflags`
LIBS = `pkg-config opencv --libs`

% : src/%.cpp src/%.h
	$(CXX) $(CFLAGS) -g -o bin/$@ $< -O3 $(LIBS)
	
clean:
	rm -rf bin/*
