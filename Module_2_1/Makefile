CXXFLAGS = -std=c++11

# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

SOURCES=$(wildcard *.cpp)
OBJECTS=$(wildcard *.o)

# the build target executable:
TARGET = jogoForca

$(info $$var is [${OBJECTS}])

# The linker commands first
$(TARGET): $(SOURCES)
	$(CC) $(CXXFLAGS) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Compilation Command
$(OBJECTS): $(SOURCES) 
	$(CC) $(CFLAGS) -c $(SOURCES) -o $(OBJECTS)


clean:
	$(RM) $(TARGET)