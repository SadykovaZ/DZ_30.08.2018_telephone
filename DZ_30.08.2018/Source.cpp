#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;

void add(int *[], int&);
void copy(int*, int*, const int);
int find(int *[], const int);
void out(int *[], const int);
void rand_in(int *[], const int);
void remove(int *[], int&);
void sort(int*, int*, const int);
void sort_key(int *[], const int);
void sort_number(int *[], const int);


void add(int *p[], int& s)
{
	int *k = p[0];
	int *n = p[1];
	int *k_add = new int[++s];
	int *n_add = new int[s];
	copy(k, k_add, s - 1);
	copy(n, n_add, s - 1);
	int key, number;
	cout << "Введите код города : ";
	cin >> key;
	cout << "Введите номер телефона : ";
	cin >> number;
	cout << "\n";
	*(k_add + s - 1) = key;
	*(n_add + s - 1) = number;

	p[0] = k_add;
	p[1] = n_add;
}

void copy(int *a, int *b, const int s)
{
	for (int i = 0; i < s; i++)
		*(b + i) = *(a + i);
}
int find(int *p[], const int s)
{
	int *k = p[0];
	int *n = p[1];
	int key, number;
	cout << "Введите код города : ";
	cin >> key;
	cout << "Введите номер телефона : ";
	cin >> number;
	cout << "\n";
	for (int i = 0; i < s; i++)
		if (*(k + i) == key)
			if (*(n + i) == number)
				return i;
	return -1;
}

void out(int *p[], const int s)
{
	cout << "Код Телефон\n";
	for (int i = 0; i < s; i++)
	{
		cout << setw(3) << p[0][i];
		cout << setw(8) << p[1][i] << endl;
	}
}

void rand_in(int *p[], const int s)
{
	int *k = p[0];
	int *n = p[1];
	for (int i = 0; i < s; i++)
	{
		*(k + i) = rand() % 20;
		*(n + i) = (rand() % 200);
	}
	p[0] = k;
	p[1] = n;
}
void remove(int *p[], int& s)
{
	int *k = p[0];
	int *n = p[1];
	int n_r = find(p, s);
	if (n_r > -1)
	{
		int *k_new = new int[--s];
		int *n_new = new int[s];
		int i;
		for (i = 0; i < n_r; i++)
		{

			*(k_new + i) = *(k + i);
			*(n_new + i) = *(n + i);
		}
		for (i; i < s; i++)
		{
			*(k_new + i) = *(k + i + 1);
			*(n_new + i) = *(n + i + 1);
		}

		p[0] = k_new;
		p[1] = n_new;
	}
	else
		cout << "Такого номера нет\n";

}

void sort(int *a, int *b, const int s)
{
	for (int i = 1; i < s; i++)
	{
		int ins = *(a + i);
		int temp = *(b + i);
		int j = i - 1;
		while (j >= 0 && ins < *(a + j))
		{
			*(a + j + 1) = *(a + j);
			*(b + j + 1) = *(b + j);
			j--;
		}
		*(a + j + 1) = ins;
		*(b + j + 1) = temp;
	}
}

void sort_key(int *p[], const int s)
{
	int *k = p[0];
	int *n = p[1];

	sort(k, n, s);

	p[0] = k;
	p[1] = n;
}

void sort_number(int *p[], const int s)
{
	int *k = p[0];
	int *n = p[1];

	sort(n, k, s);

	p[0] = k;
	p[1] = n;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int nSize = 5;
	int *pKey, *pNumber;
	srand(time(NULL));

	pKey = new int[nSize];
	pNumber = new int[nSize];
	int *masP[] = { pKey, pNumber };

	rand_in(masP, nSize);
	out(masP, nSize);

	bool f = true;
	while (f)
	{
		int c;
		
		cout << "Выберите действие :\n1 - поиск по номеру\n2 - добавить номер\n3 - удалить номер"
			<< "\n4 - сортировка по коду города\n5 - сортировка по номеру\n6 - выход\n";
		cin >> c;
		switch (c)
		{
		case 1:
		{
			int n = find(masP, nSize);
			if (n > -1)
				cout << "Введенный номер в списке на " << n + 1 << " месте\n";
			else cout << "Такого номера в списке нет\n";
		}
		break;
		case 2: 
		{
			add(masP, nSize);
			out(masP, nSize);
		}
				break;
		case 3:
		{
			remove(masP, nSize);
			out(masP, nSize);
		}
			break;
		
		case 4:
		{
			sort_key(masP, nSize);
			out(masP, nSize);
		}
			break;
		case 5: 
		{
			sort_number(masP, nSize);
			out(masP, nSize);
		}
			break;
		case 6: f = false;
			break;
		default: cout << "Некорректный ввод\n";
			break;
		}
	}

	cout << endl;
	delete[] pKey, pNumber;
	
	system("pause");
	return 0;
}
