# the compiler: gcc for C program, define as g++ for C++
CC = g++
REMOVE = rm -rf
CREATE_DIR = MKDIR -p
MOVE_FILE = MV
API_FOLDER= ./api
SOURCE_FOLDER = ./src
OUT_FOLDER = ./_out
OUT_BUILD_FOLDER = $(OUT_FOLDER)/bin
OUT_OBJ_FOLDER = $(OUT_FOLDER)/obj

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -std=c++11 -g -Wall -I$(API_FOLDER)

SOURCES=$(wildcard $(SOURCE_FOLDER)/*.cpp)
OBJECTS_REF=$(subst .cpp,.o,$(SOURCES))
OBJECTS=$(subst $(SOURCE_FOLDER),$(OUT_OBJ_FOLDER),$(OBJECTS_REF))

# the build target executable:
TARGET = _out/bin/main

# The linker commands first
$(TARGET): $(OBJECTS)
	$(CREATE_DIR) $(OUT_BUILD_FOLDER)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET).exe

# Compilation Command
$(OBJECTS): $(SOURCES)
	$(CREATE_DIR) $(OUT_OBJ_FOLDER)
	$(CC) $(CFLAGS) -c $(SOURCES)
	$(MOVE_FILE) *.o _out/obj

clean:
	$(REMOVE) $(OUT_FOLDER)
	$(REMOVE) *.o