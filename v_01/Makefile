# COMPILER
CC=gcc

# FILES
CONFIG_FILE= config/settings.c
UI_FILE= lib/ui/ui.c
UF_FILE= lib/uf/uf.c
FP_FILE= lib/fp/fp.c
SEV_FILE= event/secondary/secondary_event.c
PEV_FILE= event/principal/principal_event.c
MAIN_FILE= main.c

FILES= $(CONFIG_FILE) $(UI_FILE) $(UF_FILE) $(FP_FILE) $(MAIN_FILE) $(SEV_FILE) $(PEV_FILE)

# FLAGS
NORME_FLAGS= -std=c89 -pedantic
DEBUG_FLAGS= -Wall -Werror
BEFORE_FLAGS= $(NORME_FLAGS) $(DEBUG_FLAGS) 
AFTER_FLAGS= -lncurses -lconfig

debug:$(FILES)
	$(CC) $(BEFORE_FLAGS) $(FILES) $(AFTER_FLAGS) -odebug

build:$(FILES)
	$(CC) $(NORME_FLAGS) $(FILES) $(AFTER_FLAGS) -omake_out
