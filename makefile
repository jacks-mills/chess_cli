CC := gcc
CFLAGS := -std=c99 -Wall -pedantic

SRC_DIR := ./src
BLD_DIR := ./bld
BIN_DIR := ./bin

SRCS := $(shell find $(SRC_DIR) -name *.[ch])
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(filter %.c, $(SRCS)))
TARG := $(BIN_DIR)/chess

.PHONY: all clean install uninstall

all: $(TARG)

clean:
	rm -rf $(BLD_DIR)
	rm -rf $(BIN_DIR)

install: $(TARG)
	cp $(TARG) $(HOME)/.local/bin/

uninstall:
	rm -f $(HOME)/.local/bin/$(notdir $(TARG))



$(TARG): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS)   -o $@ $(filter %.o, $^)

$(OBJS): $(BLD_DIR)/%.o: $(SRC_DIR)/%.c | $(BLD_DIR)
	$(CC) $(CFLAGS)   -o $@ -c $<

$(BLD_DIR) $(BIN_DIR):
	mkdir -p $@
