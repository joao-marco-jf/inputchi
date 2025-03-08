CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
ASSETS_DIR = assets
TARGET = $(BIN_DIR)/inputchi

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET) assets

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -MMD -c -o $@ $<

$(OBJ_DIR) $(BIN_DIR) $(ASSETS_DIR):
	mkdir -p $@

assets: | $(ASSETS_DIR)
	@echo "Certifique-se de copiar os arquivos de fonte e imagens para a pasta $(ASSETS_DIR)"
	@echo " - Necessário: arial.ttf, happy.png, sad.png"

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

-include $(DEPS)

.PHONY: all clean assets