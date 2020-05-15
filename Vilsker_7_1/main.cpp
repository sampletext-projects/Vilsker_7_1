#include <iomanip>
#include <iostream>

using namespace std;

void write_mas(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << "\n";
}

void randomize(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		//рандом чисел от -25 до 25 с точностью 0.01
		mas[i] = rand() % (50 * 100) / 100. - 25;
	}
}

double sred(double* mas, int size)
{
	double sred = 0;
	for (int i = 0; i < size; i++)
	{
		sred += mas[i];
	}
	sred /= size;
	return sred;
}

double* shift(double* mas, int size)
{
	double* m = new double[size];
	double s = sred(mas, size);
	for (int i = 0; i < size; i++)
	{
		m[i] = mas[i] - s;
	}
	return m;
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));
	cout << "Выполнила студентка группы УТН-111 Кришпенц Александра\n";
	cout << "Программа для работы с массивом\n";

	int size;
	cout << "Введите размер массива: ";
	cin >> size;

	double* mas = new double[size];

	randomize(mas, size);

	cout << "Массив: \n";
	write_mas(mas, size);

	double s = sred(mas, size);
	cout << "Среднее арифметическое массива: \n" << s << "\n";

	double* shifts = shift(mas, size);
	cout << "Массив отклонений: \n";
	write_mas(shifts, size);

	system("pause");

	return 0;
}
