CXX      = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -Iinclude

SRC   = $(wildcard src/*.cpp)
OBJ   = $(patsubst src/%.cpp,build/%.o,$(SRC))
BINS  = bin/reducao_transitiva bin/gerador bin/verificador

all: $(BINS)

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin/reducao_transitiva: apps/reducao_main.cpp $(OBJ) | bin
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/gerador: apps/gerador_main.cpp $(OBJ) | bin
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/verificador: apps/verificador_main.cpp $(OBJ) | bin
	$(CXX) $(CXXFLAGS) -o $@ $^

build bin:
	mkdir -p $@

test: all
	@./bin/reducao_transitiva tests/t1.txt /tmp/t1.out && ./bin/verificador tests/t1.txt /tmp/t1.out
	@./bin/reducao_transitiva tests/t2.txt /tmp/t2.out && ./bin/verificador tests/t2.txt /tmp/t2.out
	@./bin/gerador 200 0.1 7 > /tmp/g.txt && ./bin/reducao_transitiva /tmp/g.txt /tmp/gr.txt && ./bin/verificador /tmp/g.txt /tmp/gr.txt

clean:
	rm -rf build bin

.PHONY: all test clean
