CXX = g++

TARGET = ciphers
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iheaders

SRCS = $(wildcard src/*.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean: 
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean