#ifndef FUNCTION
#define FUNCTION

#include<iostream>
#include<iomanip>
#include<stdexcept> // для std::runtime_error и strerror
#include<limits> // для std::numeric_limits

namespace Prog1 {

	// структура для задания строки матрицы
	struct Line {
		int n = 0; // кол-во элементов в строке
		int* a = nullptr; // массив элементов
	};

	// структура матрицы
	struct Matrix {
		int m = 0; // кол-во строк
		Line* lines = nullptr; // массив строк
	};

	// шаблонная функция для ввода 1 числа
	template <class T>
	T GetNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max())
	{
		T a;
		while (true) {
			std::cin >> a;
			if (std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
				throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
			else if (std::cin.eof())
				throw std::runtime_error("Failed EOF");
			// прочие ошибки (неправильный формат ввода) либо число не входит в заданный диапазон
			else if (std::cin.fail() || a < min || a > max) {
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Неверный ввод. Повторите еще раз." << std::endl;
			}
			else // успешный ввод
				return a;
		}
	}

	Matrix input(); // ввод матрицы и выделение памяти
	Matrix NewMatrix(const Matrix& matrix);
	void PrintMatrix(const Matrix& matrix);
	void PrintNewMatrix(const Matrix& new_matrix);

	void FreeMemoryMatrix(Matrix& matrix);
	void FreeMemoryNewMatrix(Matrix& new_namrix);
}

#endif