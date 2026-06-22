NAME = ScalarConverter

# Archivos fuente y objetos
SRC = main.cpp ScalarConverter.cpp
OBJ_DIR = obj
OBJ = $(SRC:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

# Compilador y flags
C++ = c++
RM = rm -f
RMDIR = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# ==================================== BANNER =================================== #

define banner
	@echo "\033[0;34m"
	@echo " _____        ___ ___ "
	@echo "|   __|_ _   |   |   |"
	@echo "|   __|_'_|  | | | | |"
	@echo "|_____|_,_|  |___|___|"
	@echo "\033[0m"
endef

# ================================ REGLA PRINCIPAL ============================= #

all: $(NAME)

$(NAME): $(OBJ)
	$(banner)
	@$(C++) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# ============================ COMPILACIÓN DE ARCHIVOS ========================== #

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "\033[0;34m⚙️  Compilando $<...\033[0m"
	@$(C++) $(CPPFLAGS) -c $< -o $@

# =============================== REGLAS DE LIMPIEZA ============================ #

clean:
	@echo "\033[0;35m🧹 Limpiando archivos objeto...\033[0m"
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@echo "\033[0;35m🗑️  Eliminando ejecutable...\033[0m"
	@$(RM) $(NAME)
	@$(RM) $(NAME)_asan

re: fclean all

# =============================== REGLA DE EJECUCIÓN ============================ #

run: all
	@echo "\033[0;36m🚀 Ejecutando programa...\033[0m"
	@./$(NAME)

# ============================== REGLAS ADDRESSSANITIZER ========================= #

asan:
	@echo "\033[0;33m🧪 Compilando con AddressSanitizer...\033[0m"
	$(banner)
	@$(C++) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address $(SRC) -o $(NAME)_asan
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

runasan:
	@echo "\033[0;33m🧪 Compilando con AddressSanitizer...\033[0m"
	$(banner)
	@$(C++) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address $(SRC) -o $(NAME)_asan
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"
	@echo "\033[0;36m🚀 Ejecutando con ASan...\033[0m"
	@./$(NAME)_asan

.PHONY: all clean fclean re run asan runasan
