#ifndef FUNCTION
#define FUNCTION

#include<iostream>
#include<iomanip>
#include<stdexcept> // ��� std::runtime_error � strerror
#include<limits> // ��� std::numeric_limits

namespace Prog1 {

	// ��������� ��� ������� ������ �������
	struct Line {
		int n = 0; // ���-�� ��������� � ������
		int* a = nullptr; // ������ ���������
	};

	// ��������� �������
	struct Matrix {
		int m = 0; // ���-�� �����
		Line* lines = nullptr; // ������ �����
	};

	// ��������� ������� ��� ����� 1 �����
	template <class T>
	T GetNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max())
	{
		T a;
		while (true) {
			std::cin >> a;
			if (std::cin.bad()) // ���������� ��������������� ������ �������� ������
				throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
			else if (std::cin.eof())
				throw std::runtime_error("Failed EOF");
			// ������ ������ (������������ ������ �����) ���� ����� �� ������ � �������� ��������
			else if (std::cin.fail() || a < min || a > max) {
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "�������� ����. ��������� ��� ���." << std::endl;
			}
			else // �������� ����
				return a;
		}
	}

	Matrix input(); // ���� ������� � ��������� ������
	Matrix NewMatrix(const Matrix& matrix);
	void PrintMatrix(const Matrix& matrix);
	void PrintNewMatrix(const Matrix& new_matrix);

	void FreeMemoryMatrix(Matrix& matrix);
	void FreeMemoryNewMatrix(Matrix& new_namrix);
}

#endif