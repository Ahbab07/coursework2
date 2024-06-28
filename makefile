# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
LDFLAGS = 

# Targets
TARGET = test

# Source files
SRCS = Directory.cpp File.cpp FileDescriptor.cpp FileSystem.cpp test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Dependency files
DEPS = $(SRCS:.cpp=.d)

# Rules
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Pattern rule for generating object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include dependency files
-include $(DEPS)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)

