CC = gcc
WWW = -Wall -Werror -Wextra -std=c11 -pedantic
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
TEST_FLAGS = -lcheck -lm

SRC_DIR = .
OBJ_DIR = ./objs
TEST_DIR = ./test
TEST_OBJ_DIR = ./test/objs

SRC_C_FILES := $(wildcard s21_*.c)
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_C_FILES:.c=.o)))

TEST_C_FILES := $(wildcard $(TEST_DIR)/test_*.c)
OBJ_TEST_FILES := $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_C_FILES:.c=.o)))

all: s21_decimal.a test gcov_report

rebuild: clean all

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

# -c = компиляция в объектный файл (*.o)
# $@ = ссылка на цель, используется для присваивания имени объектному файлу
# $< = ссылка на первую зависимость, она содержит исходный *.c файл для компиляции
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(WWW) -c -o $@ $<

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(TEST_OBJ_DIR)
	$(CC) $(WWW) -c -o $@ $<

test: $(OBJ_TEST_FILES) s21_decimal.a main.o
	$(CC) $(WWW) $(OBJ_TEST_FILES) $(OBJ_FILES) main.o $(TEST_FLAGS)

# ar = утилита для работы с архивами, используемая для создания статических библиотек
# r = добавляет файлы в архив (или заменяет их, если они уже существуют)
# c = создает архив, если он не существует
# s = создает индекс для библиотеки, что ускоряет процесс связывания
# ranlib = Это утилита, которая создает или обновляет индекс для статической библиотеки. 
s21_decimal.a: $(OBJ_FILES)
	ar rcs s21_decimal.a $(OBJ_FILES)
	ranlib s21_decimal.a

main.o: main.c
	$(CC) $(WWW) -c -o $@ $<

gcov_report: s21_decimal.a
	$(CC) $(WWW) $(GCOV_FLAGS) main.c $(TEST_C_FILES) $(SRC_C_FILES) s21_decimal.a $(TEST_FLAGS) -o test_program
	./test_program
	lcov -t "Report" -c -d ./ --output-file ./coverage.info --exclude 'main.c' --exclude 's21_help.c' --exclude 'test/*'
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

clean:
	rm -rf *.gcno *.gcda
	rm -rf *.a *.o *.info *.out
	rm -rf test_program
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(TEST_OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_OBJ_DIR)
	rm -rf report/

