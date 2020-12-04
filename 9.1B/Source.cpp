#include <iostream>
#include<iomanip>
#include<string>
#include<Windows.h>
using namespace std;
enum Specialty {КН, ІФ, МЕ, ФІ, ТН};
string s_specialty[] = { "КН", "ІФ", "МЕ", "ФІ", "ТН" };

struct Student
{
	string prizv;
	int kurs;
	Specialty specialtion;
	int physics;
	int math;
	int programming;
	int methods;
	int pedagogy;
};
void Create(Student* p, const int kilkist);
void Print(Student* p, const int kilkist);
int CountMark(Student* p, const int kilkist);
double physics_and_math_five(Student* p, const int N);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kil_student;
	cout << "Введіть кількість студентів: "; cin >> kil_student;
	cout << endl;
	Student* p = new Student[kil_student];
	Create(p, kil_student);
	cout << endl;
	Print(p, kil_student);
	cout << endl;
	cout << "| Процент оцінок відмінно: " << setprecision(2) << CountMark(p, kil_student) << "%" << endl << endl;
	cout << "| Процент студентів які отримали з фізики і математики 5:" << physics_and_math_five(p,kil_student) << "%" << endl;
	cout << "=========================================================================" << endl;
	if (physics_and_math_five(p, kil_student));
	else
		cout << "Студенти які не отимали 5: " << endl << endl;
	delete[] p;
}
void Create(Student* p, const int kilkist)
{
	int kurs, specialty;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync(); 

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " спеціальність(0-КН, 1-ІФ, 2-МЕ, 3-ФІ, 4-ТН): ";
		cin >> specialty;
		p[i].specialtion = (Specialty)specialty;
		switch (specialty)
		{
		case 0:
			cout << " програмування : "; cin >> p[i].programming;
			break;
		case 1:
			cout << " чисельння методів : "; cin >> p[i].methods;
			break;
		case 2:
		case 3:
		case 4:
			cout << " педагогіка : "; cin >> p[i].pedagogy;
			break;
		default:
			cout << "Помилкове значення!" << endl;
		}
		cout << "фізика: "; cin >> p[i].physics;
		cout << "математика: "; cin >> p[i].math;
	}
}
void Print(Student* p, const int kilkist)
{
	cout << "========================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Програмування |  Числовий метод | Педагогіка |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(3) << right << p[i].kurs << " "
			<< "| " << setw(22) << right << s_specialty[p[i].specialtion] << "    "
			<< "| " << setw(4) << right << p[i].physics << " "
			<< "| " << setw(6) << right << p[i].math;
		switch (p[i].specialtion)
		{
		case 0:
			cout << "| " << setw(7) << right << p[i].programming << " |" << setw(18) << "|" << setw(13) << "|" << endl;
			break;
		case 1:
			cout << "| " << setw(15) << " |" <<  setw(10) << right << p[i].methods << " |" << setw(13)  << "|" << endl;
			break;
		case 2:
		case 3:
		case 4:
			cout << "| " << setw(15)  << "|"  << setw(18) << "|" << right << setw(7) << p[i].pedagogy << " |" << endl;
			break;
		}
	}
	cout << "========================================================================="
		<< endl;
}

int CountMark(Student* p, const int kilkist)
{
	int k = 0;
	for (int i = 0; i < kilkist; i++)
	{
		switch (p[i].specialtion)
		{
		case 0:
			if (p[i].physics == 5 && p[i].math == 5 && p[i].programming == 5)
				k++;
			break;
		case 1:
			if (p[i].physics == 5 && p[i].math == 5 && p[i].methods == 5)
				k++;
			break;
		case 2:
		case 3:
		case 4:
			if (p[i].physics == 5 && p[i].math == 5 && p[i].pedagogy == 5)
				k++;
			break;
		
		}
	}
	return 100.0 * k / kilkist;
}
double physics_and_math_five(Student* p, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
		if (p[i].physics == 5 && p[i].math == 5)
			k++;
	return 100.0 * k / N;
}