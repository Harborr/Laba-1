CXX = g++
CXXFLAGS = -Wall -std=c++11

# Все объектные файлы
OBJS = main.o rectangle.o triangle.o

# Цель по умолчанию
all: geometry_calculator

# Сборка программы
geometry_calculator: $(OBJS)
	$(CXX) $(CXXFLAGS) -o geometry_calculator $(OBJS)

# Компиляция main.cpp
main.o: main.cpp rectangle.h triangle.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Компиляция rectangle.cpp
rectangle.o: rectangle.cpp rectangle.h
	$(CXX) $(CXXFLAGS) -c rectangle.cpp

# Компиляция triangle.cpp
triangle.o: triangle.cpp triangle.h
	$(CXX) $(CXXFLAGS) -c triangle.cpp

# Очистка
clean:
	rm -f *.o geometry_calculator

# Запуск программы
run: geometry_calculator
	./geometry_calculator