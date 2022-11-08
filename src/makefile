
CC = g++ -ID:/Programming/packages/cpp/SFML-2.5.1/include -LD:/Programming/packages/cpp/SFML-2.5.1/lib -std=c++17
SFML_FLAGS = -lsfml-graphics-d -lsfml-window-d -lsfml-system-d
# SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

EXECUTABLE = run.exe

SOURCES = main.cpp   \
	  game\game.cpp   \
	  game\game_mediator.cpp    \
	  game\controls\event_reader.cpp \
	  game\controls\sfml_event_reader.cpp \
	  game\controls\sfml_key_binder.cpp \
	  game\controls\controls_storage.cpp \
	  graphics\level_painter.cpp  \
	  graphics\texture_manager.cpp \
	  graphics\sprite_manager.cpp   \
	  graphics\dialogs\choose_map_dialog.cpp  \
	  objects\object.cpp  \
	  objects\player.cpp   \
	  objects\creature.cpp  \
	  map\map.cpp \
	  map\cell.cpp \
	  map\events\event.cpp \
	  map\events\map_event.cpp \
	  map\events\win_event.cpp \
	  map\events\lose_event.cpp \
	  map\events\state_event.cpp \
	  map\events\player_event.cpp \
	  map\events\change_map_event.cpp \
	  map\events\player_heal_event.cpp \
	  map\events\change_cell_event.cpp  \
	  map\events\damage_player_event.cpp \
	  map\events\player_speed_multiplier_event.cpp \
	  log\message.cpp \
	  log\logger.cpp   \
	  log\observable.cpp \
	  log\file_logger.cpp \
	  log\logger_pool.cpp  \
	  log\console_logger.cpp \
	  log\messages\event_messages.cpp \
	  log\messages\player_messages.cpp \
	  log\messages\game_states_messages.cpp


OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(SFML_FLAGS)

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	del $(OBJECTS)