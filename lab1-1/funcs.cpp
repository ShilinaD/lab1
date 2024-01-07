#include"funcs.h"

namespace Prog1 {
	//������� �����
	Matrix input() 
	{
		Matrix matrix; //��������� ������ ��� �������
		std::cout << "������� ����������� �������:" << std::endl;

		try {
			matrix.m = GetNum<int>(1, 1000);
			matrix.lines = new Line[matrix.m]; // �������� ������ ��� ������ �������� - ����� �������

			for (int i = matrix.m - 1; i >= 0; i--) {
				matrix.lines[i].a = new int[(matrix.m - i)];
			}
		}
		catch (const std::bad_alloc& ba) // � ������ ������ ��������� ������ 
		{
			throw std::runtime_error("������ ��������� ������ ��� ������� ");
		}

		for (int i = 0; i < matrix.m  ; i++) { // ���� ������� �� ������� ���������
			
			for (int j = 0; j <= i; j++) {

				std::cout << "������� �������  �������:" << i << "." << j << ":" << std::endl;
				matrix.lines[i].a[j] = GetNum<int>();
			}
		}
		return matrix;
	}

	bool IsIncreasing(int num)
	{
		if (num >= 0 && num < 10) {
			return false;
		}

		if (num < 0) {
			num *= (-1);
		}

		int prev_num = num % 10;
		num /= 10;
		while (num > 0 ) {
			int current_num = num % 10;
			if (current_num >= prev_num) {
				return false;
			}
			prev_num = current_num;
			num /= 10;
		}
	return true;
	}

	bool IsDecreasing(int num)
	{
		if (num >= 0 && num < 10) {
			return false;
		}

		if (num < 0) {
			num *= (-1);
		}

		int prev_num = num % 10;
		num /= 10;
		while (num > 0) {
			int current_num = num % 10;
			if (current_num <= prev_num) {
				return false;
			}
			prev_num = current_num;
			num /= 10;
		}
	return true;
	}


	//�������� ����� �������
	Matrix NewMatrix(const Matrix& matrix)
	{
		Matrix new_matrix; //��������� ������ ��� �������
		try {
			new_matrix.m = matrix.m;
			new_matrix.lines = new Line[new_matrix.m]; // �������� ������ ��� ������ �������� - ����� �������

			for (int i = new_matrix.m - 1; i >= 0; i--) {
				new_matrix.lines[i].a = new int[(new_matrix.m - i)];
			}
		}
		catch (const std::bad_alloc& ba) // � ������ ������ ��������� ������ 
		{
			throw std::runtime_error("������ ��������� ������ ��� ������� ");
		}
		

		for (int i = matrix.m - 1; i >= 0; i--) {
			for (int j = 0; j < matrix.m - i; j++) {
				if ( IsIncreasing(matrix.lines[matrix.m - (i + 1)].a[j]) || IsDecreasing(matrix.lines[matrix.m - (i + 1)].a[j]) )
				{
					new_matrix.lines[j].a[matrix.m - (i + 1)] = matrix.lines[matrix.m - (i + 1)].a[j];
				}
				else {
					new_matrix.lines[j].a[matrix.m - (i + 1)] = 0;

				}
			} 

			for (int j = 0; j < (matrix.m - (matrix.m - i)); j++) {
				if (IsIncreasing(matrix.lines[matrix.m - i + j].a[matrix.m - (i + 1)]) || IsDecreasing(matrix.lines[matrix.m - i + j].a[matrix.m - (i + 1)]))
				{
					new_matrix.lines[matrix.m - i + j].a[matrix.m - (i + 1)] = matrix.lines[matrix.m - i + j].a[matrix.m - (i + 1)];
				}
				else {
					new_matrix.lines[matrix.m - i + j].a[matrix.m - (i + 1)] = 0;
				}
			}
		}

		//��������� �� ����������� 
		for (int i = 0; i < new_matrix.m; i++) // ����� �������
		{
			int index = 0;
			int new_el = 0;
			for (int j = 0; j < new_matrix.m; j++)
			{
				if (new_matrix.lines[i].a[j] == NULL) 
				{
					new_el = new_matrix.lines[i].a[index];
					new_matrix.lines[i].a[index] = new_matrix.lines[i].a[j];
					new_matrix.lines[i].a[j] = new_el;
					index += 1;
				}
				if (IsIncreasing(new_matrix.lines[i].a[j]))
				{
					new_el = new_matrix.lines[i].a[index];
					new_matrix.lines[i].a[index] = new_matrix.lines[i].a[j];
					new_matrix.lines[i].a[j] = new_el;
					index += 1;
				}
			}
		}
		return new_matrix;
	}

	void PrintMatrix(const Matrix& matrix) { // ����� �������
		std::cout << "�������� �������:" << std::endl;
		for (int i = matrix.m -1; i >= 0; i--) {
			for (int j = 0; j < (matrix.m - i); j++) {

				std::cout << std::setw(6) << std::setprecision(8) << matrix.lines[matrix.m - (i+1)].a[j] << " ";
				//setw ������������� ������ ����  ��� ������� �������� setprecision ������������� �������� ������ 
			}   // ����� ������� ���� �������� ��� ���� 

			for (int j = 0; j < (matrix.m - (matrix.m - i)); j++) {
				std::cout << std::setw(6) << std::setprecision(8) << matrix.lines[matrix.m - i + j ].a[matrix.m - (i+1)] << " ";

			}
			std::cout << std::endl;
		}
	}

	void PrintNewMatrix(const Matrix& new_matrix) { // ����� �������
		std::cout << "����� �������:" << std::endl;
		for (int i = 0; i < new_matrix.m; i++) // ����� �������
		{
			for (int j = 0; j < new_matrix.m; j++)
			{
				if (new_matrix.lines[i].a[j] == NULL) {
					std::cout <<"";
				}
				else {
					std::cout << new_matrix.lines[i].a[j] << " ";
				}
			}
			std::cout << std::endl;
		}
	}

	void FreeMemoryMatrix(Matrix& matrix) {
		if (matrix.lines != nullptr) {
			for (int i = 0; i < (matrix.m - i); i++) {
				delete[] matrix.lines[i].a;
			}
		}
		delete[] matrix.lines;
		matrix.lines = nullptr;
		matrix.m = 0;
	}


	void FreeMemoryNewMatrix(Matrix& new_matrix) {
		if (new_matrix.lines != nullptr) {
			for (int i = new_matrix.m - 1; i >= 0; i--) {
				new_matrix.lines[i].a=0;
					delete[]new_matrix.lines[i].a;
				
			}
		}
		delete[] new_matrix.lines;
		new_matrix.lines = nullptr;
		new_matrix.m = 0;
	}
}
