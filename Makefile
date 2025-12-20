 .SILENT: # You can uncomment this if you prefer a quieter build process

# --- 1. CONFIGURATION VARIABLES ---

NAME = sim_engine

SRCDIR := src
INCDIR := includes
BUILDDIR := build

CXX = clang++

STD_FLAGS := -Wall -Wextra -Werror -std=c++17 -MMD -MP -g

INC_PATHS := -I$(INCDIR)
INC_PATHS += -I$(INCDIR)/infos
INC_PATHS += -I$(INCDIR)/ui
INC_PATHS += -I$(INCDIR)/menus
INC_PATHS += -I$(INCDIR)/lib/avdp_ui
INC_PATHS += -I$(INCDIR)/tests
INC_PATHS += -I$(INCDIR)/events

COMMON_FLAGS := $(STD_FLAGS) $(INC_PATHS)

CFLAGS := $(COMMON_FLAGS)
CXXFLAGS := $(COMMON_FLAGS)

LD_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL -lglfw -lSDL3 -lSDL3_ttf

# --- 2. FILE DEFINITIONS ---

APP_SOURCES := $(shell find $(SRCDIR) -name "*.cpp")
#TEST_SOURCES = $(wildcard tests/*.cpp)

SOURCES = $(APP_SOURCES) $(TEST_SOURCES)

APP_OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(APP_SOURCES))
TEST_OBJECTS := $(patsubst tests/%.cpp, $(BUILDDIR)/%.o, $(TEST_SOURCES))

OBJECTS = $(APP_OBJECTS) $(TEST_OBJECTS)
DEPENDS := $(patsubst %.o, %.d, $(APP_OBJECTS))

# --- 3. COLORS & UTILITY TARGETS ---

PURPLE = \033[0;35m
GREEN = \033[0;32m
RESET = \033[0m

.PHONY: all clean re debug release dev valgrind info_window test


all: $(BUILDDIR) $(NAME)

clean:
	@echo "--- Cleaning up build artifacts ---"
	@rm -rf $(BUILDDIR) $(NAME)
	@echo "Clean complete."

fclean: clean
	@rm -rf $(NAME)

re: fclean all

debug: CFLAGS := $(COMMON_FLAGS) -g -O0
debug: CXXFLAGS := $(COMMON_FLAGS) -g -O0
debug: $(BUILDDIR) $(NAME)

release: all

dev: all
	@./$(NAME)

valgrind: all
	@valgrind --leak-check=full --log-file="log/valgrind.log" env DISPLAY=:0  ./$(NAME)

info_monitor: all
	@./$(NAME) --info-monitor

info_window: CXXFLAGS += -DDEBUG_MODE=1
info_window: fclean $(NAME)
	@./$(NAME) --info-window

test: CXXFLAGS += -DDEBUG_MODE=2
test:  all
	./$(NAME)

test_valgrind: CXXFLAGS += -DDEBUG_MODE=2
test_valgrind:  all
	@valgrind --leak-check=full --log-file="log/valgrind.log" ./$(NAME)

re_test: CXXFLAGS += -DDEBUG_MODE=2
re_test: fclean all
	./$(NAME)


# --- 4. BUILD RULES ---

$(NAME): $(OBJECTS)
	@echo "--- Linking executable: $@ ---"
	$(CXX) $^ $(LD_FLAGS) -o $(NAME)
	@printf "$(GREEN)Compilation complete.$(RESET)\n\n"


$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)/%/
	@printf "Compiling $<...$(RESET)\n"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/%/:
	@mkdir -p $@

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

# --- 5. AUTOMATIC DEPENDENCY INCLUSION ---

-include $(DEPENDS)

