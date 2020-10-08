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
			if(line[i] != ' ')
			{
				matr[col][row++] = line[i] - '0';
			}
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