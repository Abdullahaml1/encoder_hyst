#Compiler variable
GXX := g++

# Executabel name
EXC_NAME := encoder.run

# Enable debugging sympols
GXX_DEBUG_FLAGS := -g

# Adding warring flags
GXX_FLAGS := -Wall

# Adding optemization flags (for size)
GXX_FLAGS += -s

# source files list 
SRC_FILES_LIST := encoding_main.cpp


build: 
	@echo "Building the project."
	$(GXX) $(SRC_FILES_LIST)  $(GXX_FLAGS) -o $(EXC_NAME)


run: build
	@echo "-----Running-----"
	@./$(EXC_NAME)

debug:
	$(GXX) $(SRC_FILES_LIST) $(GXX_DEBUG_FLAGS) $(GXX_FLAGS) -o $(EXC_NAME)	


