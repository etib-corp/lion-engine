CXX = g++
CXXFLAGS = -Iinclude/SFML
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src/SFML
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ_FILES) main.o
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) main.o $(TARGET)

fclean: clean

.PHONY: all clean