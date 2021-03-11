SHELL=cmd
ALLEGRO_VERSION=5.0.10
MINGW_VERSION=4.7.0
FOLDER=C:

FOLDER_NAME=\allegro-$(ALLEGRO_VERSION)-mingw-$(MINGW_VERSION)
PATH_ALLEGRO=$(FOLDER)$(FOLDER_NAME)
LIB_ALLEGRO=\lib\liballegro-$(ALLEGRO_VERSION)-monolith-mt.a
INCLUDE_ALLEGRO=\include

MKDIR   := mkdir
TEST    := test
RMDIR   := rmdir /Q /S
CC      := gcc
BIN     := bin
OBJ     := obj
OBJ_INIT:= $(OBJ)/init
INCLUDE := include
SRC     := src
SRCS    := $(wildcard $(SRC)/*.c) $(wildcard $(SRC)/*/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
EXE     := main.exe
CFLAGS  := -g -I
LDLIBS  := -lm

.PHONY: all run clean path

all: $(EXE)

$(EXE): $(OBJS) | $(BIN)
	$(CC) $^ -o $@ $(PATH_ALLEGRO)$(LIB_ALLEGRO)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	if not exist "$(@D)" $(MKDIR) $(subst /,\\,$(@D))
	$(CC) $(CFLAGS) $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c $< -o $@

$(OBJ_INIT) $(BIN) $(OBJ):
	$(MKDIR) $@

run: $(EXE)
	$<

clean:
	$(RMDIR) $(subst /,\\,$(OBJ))
	$(RMDIR) $(subst /,\\,$(BIN))

