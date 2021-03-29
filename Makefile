HEADER_DIR = headers
HEADER_FILES = eg.h
HEADERS = $(HEADER_FILES:%=$(HEADER_DIR)/%)

UTILS_SRCS = utils.c
UTILS_DIR = utils
UTILS_SRCS := $(UTILS_SRCS:%=$(UTILS_DIR)/%)



SRCS += $(UTILS_SRCS)

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -I$(HEADER_DIR) -g 

eg: main.c $(OBJS) $(HEADERS)
	gcc $(CFLAGS)  main.c $(OBJS) -o $@
