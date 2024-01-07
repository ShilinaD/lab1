#include "funcs.h"
using namespace Prog1;

int main() {
	setlocale(0, ""); //подключение русского языка
	while(true){
		int choice;
		std::cout << "1: Создать матрицу.\n0: Выйти из приложения." << std::endl;
		choice = GetNum<int>(0, 1);

		switch (choice)
		{
		case 1:
		{
			Matrix matrix;  
			Matrix new_matrix; 

			try
			{
				matrix = input(); // ввод и проверка корректности ввода и выделения памяти для исходной матрицы
				new_matrix = NewMatrix(matrix);

				PrintMatrix(matrix); // вывод исходной матрицы
				PrintNewMatrix(new_matrix); // вывод исходной матрицы
				FreeMemoryMatrix(matrix); // освобождение памяти исходной матрицы
				FreeMemoryNewMatrix(new_matrix); // освобождение памяти исходной матрицы
				return 1;
			}
			catch (const std::bad_alloc& ba)
			{
				std::cerr << ba.what() << std::endl;
				FreeMemoryMatrix(matrix); 
				FreeMemoryNewMatrix(matrix);
				return 1;
			}

			catch (const std::exception& e) { // в случае прочих исключений
				std::cerr << e.what() << std::endl;
				FreeMemoryMatrix(matrix); 
				FreeMemoryNewMatrix(matrix);
				return 1;
			}
			break;
		}
		
		case 0:
			return 1; // выход
		default:
			std::cout << " Ошибка. Введите еще раз " << std::endl;
			break;
		}
	}
	
	return 0;
}