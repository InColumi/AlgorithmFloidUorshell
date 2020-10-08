#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ShowMatrix(int** matr, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cout << matr[i][j] << ' ';
		}
		cout << '\n';
	}
}



void ReadFromFile(int**& matr, int &size, string fileName)
{
	ifstream in;
	in.open(fileName);
	if(in.is_open() == false)
	{
		cout << "Файл не найден.\n";
	}

	string line;
	getline(in, line);
	size = stoi(line);
	matr = new int* [size];
	for(int i = 0; i < size; i++)
	{
		matr[i] = new int[size];
	}

	int col = 0;
	while(getline(in, line))
	{
		int row = 0;
		for(int i = 0; i < line.size(); i++)
		{
			int endNumbmer = line.find(' ');
			if(endNumbmer == -1)
			{
				endNumbmer = line.size();
			}
			string s;
			for(int i = 0; i < endNumbmer; i++)
			{
				s.push_back(line[i]);
			}
			matr[col][row++] = stoi(s);
			string newLine;
			for(int i = endNumbmer + 1; i < line.size(); i++)
			{
				newLine.push_back(line[i]);
			}
			line = newLine;
			if(line.size() == 1)
			{
				matr[col][row++] = stoi(line);
			}
			i = 0;
		}
		++col;
	}
	in.close();
}

void Algorithm(int**& matr, int size)
{
	for(int i = 0; i < size; i++)
	{
		matr[i][i] = 0;
	}

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			for(int k = 0; k < size; k++)
			{
				if(matr[j][i] && matr[i][k] && j != k)
				{
					if(matr[j][i] + matr[i][k] < matr[j][k] || matr[j][k] == 0)
					{
						matr[j][k] = matr[j][i] + matr[i][k];
					}
				}
			}
		}
	}
	
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	int** matr;

	ReadFromFile(matr, size, "matrix.txt");
	ShowMatrix(matr, size);

	cout << "Ответ:" << endl;
	Algorithm(matr, size);
	ShowMatrix(matr, size);
	return 0;
}

// Матрицы для тестов

//3
//0 9 2
//1 0 4
//2 4 0
//ответ
//0 6 2
//1 0 3
//2 4 0

//6
//0 10 18 8 31 20
//10 0 16 9 21 21
//26 16 0 25 37 15
//7 9 25 0 30 12
//64 54 38 63 0 23
//41 31 15 40 23 0
//ответ
//0 10 18 8 31 20
//10 0 16 9 21 21
//26 16 0 25 37 15
//7 9 25 0 30 12
//64 54 38 63 0 23
//41 31 15 40 23 0
