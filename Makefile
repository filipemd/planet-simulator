SRC_DIR = src
BUILD_DIR = build

# Nome do executável
TARGET = $(BUILD_DIR)/planet_simulator

RELEASE=

# Caminho para a biblioteca Rust
RUST_LIB = src/rust/physics/target/$(if $(RELEASE),release,debug)/libphysics.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Werror -Wpedantic -std=c99
LIBS = -lraylib

CARGO_FLAGS=

ifeq ($(RELEASE), 1)
	CFLAGS+=-O3
	CARGO_FLAGS=--release
else
	CFLAGS+=-O0
endif

# Busca todos os arquivos .c no diretório /src
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Gera os arquivos objeto no diretório /build
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

all:
	$(MAKE) rust
	$(MAKE) $(TARGET)

# Regra padrão: compilar e ligar
$(TARGET): $(RUST_LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compila os arquivos .c em arquivos .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compila o Rust
rust:
	cd src/rust/physics/; cargo build $(CARGO_FLAGS)

# Cria o diretório /build caso não exista
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpeza
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	cd src/rust/physics/; cargo clean

# Executa o jogo
run:
	./$(TARGET)

.PHONY: all clean run
