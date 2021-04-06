CC = cl
SRC_FILES = src\value.c \
			src\hashmap.c \
			src\utils.c \
		   src\main.c

OBJ_FILES = value.obj \
			hashmap.obj \
			utils.obj \
			main.obj

all:
	$(CC) /I includes $(SRC_FILES)
	del $(OBJ_FILES)