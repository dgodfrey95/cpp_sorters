PROJECT=selection_sort

all: $(PROJECT)

$(PROJECT): $(PROJECT).cxx
	g++ -Wall -g -Og -pedantic -std=c++11 $^ -o $@

etags:
	rm -rf ./TAGS
	find . -name '*.cxx' | xargs etags -a
	find . -name '*.h'   | xargs etags -a

run: $(PROJECT)
ifeq ($(OS),Windows_NT)
	./$(PROJECT).exe
else
	./$(PROJECT)
endif
