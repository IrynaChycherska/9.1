#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Special { KN, SA, IS, KB };
string specialStr[] = { "����'����� �����", "��������� �����", "����������� ��������", "ʳ����������" };
struct Student
{
	string prizv;
	int kurs;
	Special special;
	union
	{
		int physic;
		int math;
		int inform;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double CountMarks(Student* p, const int N);
double physics_and_math_five(Student* p, const int N);
void Sort(Student* p, const int N);
int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	int N;
	cout << "������ ������� ���������� N: "; cin >> N;

	Student* p = new Student[N];
	double proc;
	
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ������� ��������, �� �������� � ������ �� ���������� 5:" << endl;
		cout << " [4] - ������� ������������� �����" << endl;
		cout << " [5] - ������� ������ ������ � ������� ��������:" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			proc = physics_and_math_five(p, N);
			cout << " ������� ��������, �� �������� � ������ �� ���������� 5: " << endl;
			cout << proc << "%" << endl;
		case 4:
			Sort(p, N);
			break;
		case 5:
			proc = CountMarks(p,N);
			cout << "������� ������ ������ � ������� ��������:" << endl;
			cout << proc << "%" << endl;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int special, kurs;
	for (int i = 0; i < N; i++)
	{
		cout << " ������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������ (0 -����'����� �����, 1-��������� �����, 2-����������� ��������, 3-ʳ���������� ): ";
		cin >> special;
		p[i].special = (Special)special;
		switch (p[i].special)
		{
		case 0:
		case 1:
		case 2:
		case 3:
			cout << " ������ : "; cin >> p[i].physic;
			cout << " ���������� : "; cin >> p[i].math;
			cout << " ����������� : "; cin >> p[i].inform;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| � | ������� | ���� | ������������ | Գ���� | ���������� | ����������� |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(11) << left << specialStr[p[i].special];
		switch (p[i].special)
		{
		case 0:
		case 1:
		case 2:
		case 3:
			cout << "| " << setw(9) << setprecision(2) << fixed << right
				<< p[i].physic << " |" << setw(13) << right << "|" << endl;
			cout << "| " << setw(11) << right << "|" << " " << setw(8) << right
				<< p[i].math << " |" << endl;
			cout << "| " << setw(15) << right << "|" << " " << setw(5) << right
				<< p[i].inform << " |" << endl;
			break;
		}
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}

double physics_and_math_five(Student* p, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
		if (p[i].physic == 5 && p[i].math == 5)
			k++;
	return 100.0 * k / N;

}
double CountMarks(Student* p, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
		if (p[i].physic == 5 && p[i].math == 5 && p[i].inform == 5)
			k++;
	return 100.0 * k / N;

}
void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].special > p[i1 + 1].special)
				||
				(p[i1].special == p[i1 + 1].special &&
					p[i1].prizv > p[i1 + 1].prizv))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}

