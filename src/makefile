
CC = g++
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system 

EXECUTABLE = run

SOURCES = main.cpp   \
	  game/game.cpp   \
	  game/level_painter.cpp      \
	  graphics/texture_manager.cpp \
	  graphics/sprite_manager.cpp   \
	  objects/object.cpp  \
	  objects/player.cpp   \
	  objects/creature.cpp  \
	  map/map.cpp   \
	  map/cell.cpp   \
	  map/static_cell.cpp 

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE) clean
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(SFML_FLAGS)

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	rm $(OBJECTS)
