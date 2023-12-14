# Variáveis para os compiladores e flags
CC=g++
CFLAGS=-Wall -lSDL2 -lSDL2_image -Wno-invalid-memory-model -Wno-unused-variable  -Wunused-value -Wunused-value
TARGET=xadrez

# Lista de arquivos fonte
SRC=main.cpp pecas_brancas.cpp pecas_pretas.cpp

# Regra para construir o alvo final
$(TARGET): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Regra para limpar arquivos compilados
clean:
	rm -f $(TARGET)
