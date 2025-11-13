
# .SILENT: # You can uncomment this if you prefer a quieter build process

# --- 1. CONFIGURATION VARIABLES ---

NAME = gol

SRCDIR := src
INCDIR := includes
BUILDDIR := build

CXX = clang++

STD_FLAGS := -Wall -Wextra -Werror -std=c++17 -MMD -MP

INC_PATHS := -I$(INCDIR)
INC_PATHS += -I$(INCDIR)/info
INC_PATHS += -I$(INCDIR)/lib/avdp_ui

COMMON_FLAGS := $(STD_FLAGS) $(INC_PATHS)

CFLAGS := $(COMMON_FLAGS) -O3
CXXFLAGS := $(COMMON_FLAGS) -O3

LD_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL -lglfw

# --- 2. FILE DEFINITIONS ---

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
SOURCES += $(wildcard $(SRCDIR)/*/*.cpp)
SOURCES += $(wildcard $(SRCDIR)/*/*/*.cpp)

OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

DEPENDS := $(patsubst %.o, %.d, $(OBJECTS))

# --- 3. COLORS & UTILITY TARGETS ---

PURPLE = \033[0;34m
GREEN = \033[0;32m
RESET = \033[0m

.PHONY: all
all: $(BUILDDIR) $(NAME)

.PHONY: clean
clean:
	@echo "--- Cleaning up build artifacts ---"
	@rm -rf $(BUILDDIR) $(NAME)
	@echo "Clean complete."

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug: CFLAGS := $(COMMON_FLAGS) -g -O0
debug: CXXFLAGS := $(COMMON_FLAGS) -g -O0
debug: $(BUILDDIR) $(NAME)

.PHONY: release
release: all

.PHONY: dev
dev: all
	@./$(NAME)

.PHONY: valgrind
valgrind: all
	@valgrind --leack-check=full show-leak-kinds=all --log-file="log/valgrind.log" ./$(NAME)


.PHONY: info_monitor
info_monitor: all
	@./$(NAME) --info-monitor

.PHONY: info_window
info_window: all
	@./$(NAME) --info-window


.PHONY: test
test: $(NAME)
	./$(NAME) --run-tests


# --- 4. BUILD RULES ---

$(NAME): $(OBJECTS)
	@echo "--- Linking executable: $@ ---"
	$(CXX) $^ $(LD_FLAGS) -o $(NAME)
	@printf "$(GREEN)Success!$(RESET)\n\n"

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)/%/
	@printf "$(PURPLE)Compiling $<...$(RESET)\n"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/%/:
	@mkdir -p $@

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

# --- 5. AUTOMATIC DEPENDENCY INCLUSION ---

#-include $(DEPENDS)