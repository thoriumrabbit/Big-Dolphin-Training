TARGET := function

.PHONY: all clean
.DEFAULT_GOAL:= all

SRC := src
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(OBJECTS))

CC := gcc
CXX := g++
CFLAGS := -Wall -Werror
CXXFLAGS := #(CFLAGS)

all: $(TARGET)
	@echo make complete

$(TARGET): $(OBJECTS)
	@$(CXX) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	@$(CXX) -I$(SRC) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.c
	@$(CC) -I$(SRC) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) -f *.gch
