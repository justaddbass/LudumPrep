INCLUDE=/usr/include/
LOCAL_INCLUDE=/usr/local/include/
LIB_DIR=/usr/lib/
LOCAL_LIB_DIR=/usr/local/lib/
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs)
CC=g++
CPPFLAGS+=-g $(SDL_CFLAGS) -I$(INCLUDE) -I$(LOCAL_INCLUDE) -I$(LIB_DIR) -I$(LOCAL_LIB_DIR)
#CPPFLAGS+=-g -O2 -I$(DIR) -I$(LUA_INC) -L$(LUA_LIB)
TARGET = LudumPrep

UNIX_LIBS=-lSDL2 -lGL -lGLEW -llua
MAC_LIBS=-framework OpenGL $(SDL_LIBS)

OBJ := $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))
OS := $(shell uname -s)

all: $(TARGET)
ifeq ($(OS),Linux)
LIBS := $(UNIX_LIBS)
endif
ifeq ($(OS),Darwin)
LIBS := $(MAC_LIBS)
endif


$(TARGET): bin $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o bin/$@

#linux:
#	LIBS+=-lSDL2 -lGL -lGLEW -llua

#macosx:
#	LIBS+=-framework OpenGL -framework SDL2 -framework BulletDynamics -framework BulletCollision -framework LinearMath -llua

bin:
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) bin/$(TARGET)
