CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb
NASM	  := nasm
NASM_FLAGS:= -f elf64

BIN     := bin
SRC     := src
INCLUDE := include

CSRC	:= $(SRC)/*.cpp  $(SRC)/*.o
ASMSRC  := $(SRC)/asm.asm

EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(SRC)/asm.o: $(ASMSRC)
	$(NASM) $(NASM_FLAGS) $^ -o $@

$(BIN)/$(EXECUTABLE): $(CSRC)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*