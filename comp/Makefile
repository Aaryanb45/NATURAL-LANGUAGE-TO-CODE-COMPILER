# # Compiler and Flags
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall

# # Output Executable
# OUTPUT = compiler

# # Source Files
# SRCS = main.cpp parser.cpp ast.cpp codegen.cpp
# OBJS = $(SRCS:.cpp=.o)

# # Default Build
# all: $(OUTPUT)

# # Build Executable
# $(OUTPUT): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(OBJS)

# # Compile Object Files
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Clean Build Files
# clean:
# 	rm -f $(OBJS) $(OUTPUT)








# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -O2
LDFLAGS = 

# Output Executable
OUTPUT = compiler

# Source Files
SRCS = main.cpp parser.cpp ast.cpp codegen.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

# Default Build
all: $(OUTPUT)

# Build Executable
$(OUTPUT): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(OUTPUT) $(OBJS)

# Compile Object Files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include Dependencies
-include $(DEPS)

# Clean Build Files
clean:
	rm -f $(OBJS) $(DEPS) $(OUTPUT)

# Run Compiler
run: $(OUTPUT)
	./$(OUTPUT)

# Debug Build
debug: CXXFLAGS += -DDEBUG -g
debug: clean all
