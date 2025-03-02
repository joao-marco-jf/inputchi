CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = 
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/inputchi

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -MMD -c -o $@ $<

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

-include $(DEPS)

.PHONY: all clean
