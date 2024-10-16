CC = gcc
CFLAGS = -Werror -Wextra -Wall -c -std=c11
ifeq ($(shell uname -s),Linux)
	CFLAGS += -lm
endif

TEST_FLAGS = -lcheck
ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lrt -lsubunit -lpthread -lm
endif

RUN_TEST = ./s21_test/s21_test.c
TEST_FUNC = $(wildcard ./s21_test/test_func/*.c)

SOURCE = s21_*.c
#OBJECTS = $(patsubst %.c,%.o, ${SOURCE}) # на маке может не работать корректно
OBJECTS = s21_*.o

FILES_TO_CHECK = $(wildcard ./s21_test/test_func/*.c) $(wildcard ./s21_test/test_func/*.h) \
				$(wildcard ./s21_test/*.c) $(wildcard ./s21_test/*.h) $(wildcard *.c) $(wildcard *.h)

all: s21_string.a

# Оформи решение как статическую библиотеку с названием s21_string.a 
# (с заголовочным файлом s21_string.h);
s21_string.a: 
	$(CC) $(CFLAGS) $(SOURCE)
	ar rcs s21_string.a $(OBJECTS)
	ranlib s21_string.a
	rm -rf *.o

# Подготовь полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check;
# Unit-тесты должны проверять результаты работы твоей реализации путём сравнения ее 
# с реализацией стандартной библиотеки string.h;
# Unit-тесты должны покрывать не менее 80% каждой функции;
test: clean s21_string.a
	$(CC) $(RUN_TEST) $(TEST_FUNC) s21_string.a $(TEST_FLAGS) -o test
	./test

# В цели gcov_report должен формироваться отчёт gcov в виде html страницы. 
# Для этого unit-тесты должны запускаться с флагами gcov;
gcov_report: clean
	gcc --coverage $(SOURCE) $(RUN_TEST) $(TEST_FUNC) -o s21_test_gcov $(TEST_FLAGS)
	./s21_test_gcov
	lcov -t "s21_test_gcov" -o s21_test_gcov.info -c -d .
	genhtml -o report s21_test_gcov.info
	open ./report/index.html

rebuild: clean all

clean:
	rm -rf *.o *.out *.a
	rm -rf *.gcno *.gcda *.gcov
	rm -rf *.info
	rm -rf s21_test_gcov
	rm -rf ./report/
	rm -rf test

clang:
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -i ./s21_test/*.c ./s21_test/*.h
	clang-format -style=Google -i ./s21_test/test_func/*.c 

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILES_TO_CHECK)
