
CC = g++
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system 

EXECUTABLE = run

SOURCES = main.cpp        \
	  game/game.cpp   \
	  graphics/texture_manager.cpp \
	  objects/object.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE) clean
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(SFML_FLAGS)

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	rm $(OBJECTS)
