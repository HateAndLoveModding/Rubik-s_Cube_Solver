TARGET = RCS
SRC_FILES = main.cpp Cube.cpp

# NO EDITS NEEDED BELOW THIS LINE
CXX = g++
CXXFLAGS = -O2
CXXFLAGS_DEBUG = -g
CXXFLAGS_ERRORS = -Werror -Wall -Wextra -Wconversion -Wdouble-promotion -Wunreachable-code -Wshadow -Wpedantic -pedantic-errors
CPPVERSION = -std=c++17

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm -f
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) $(CPPVERSION) $(CXXFLAGS_DEBUG) $(CXXFLAGS_ERRORS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)