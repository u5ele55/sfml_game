
CC = g++ -ID:/Programming/packages/cpp/SFML-2.5.1/include -LD:/Programming/packages/cpp/SFML-2.5.1/lib
SFML_FLAGS = -lsfml-graphics-d -lsfml-window-d -lsfml-system-d
# SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

EXECUTABLE = run.exe

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
