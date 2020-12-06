#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>

using namespace std;

#pragma pack(push, 1)

struct Exam_List
{
    string surname;
    string initials;
    int grade_physics;
    int grade_math;
    int grade_computer_science;
    int grade_history;
    int grade_english;
};

#pragma pack(pop)

void Create(Exam_List* S, int N_start, const int N);
void Print(Exam_List* S, const int N);
void SaveToFile(Exam_List* S, const int N, const char* filenЬщame);
void LoadFromFile(Exam_List*& S, int& N, const char* filename);
void List_of_students_with_5(Exam_List* S, const int N);
void List_of_students_with_3(Exam_List* S, const int N);
void List_of_students_with_2(Exam_List* S, const int N);


int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    do
    {
        cout << "Введіть кількість студентів: ";
        cin >> N;
    } while (N < 1);
    Exam_List* S = new Exam_List[N];

    int action;

    char filename[100];

    do
    {
        cout << endl
            << endl;
        cout << "Виберіть дію: " << endl;
        cout << "1 - Введення даних з клавіатури" << endl;
        cout << "2 - Виведення інформації на екран" << endl;
        cout << "3 - Запис інформації у файл" << endl;
        cout << "4 - Зчитування даних із файлу" << endl;
        cout << "5 - Корегування списку з клавіатури" << endl;
        cout << "6 - Список студентів, що склали іспити тільки на «5»" << endl;
        cout << "7 - Cписок студентів, що мають трійки" << endl;
        cout << "8 - Cписок студентів, що мають двійки." << endl;
        cout << "0 - Завершити роботу програми" << endl;
        cout << "Введіть: ";
        cin >> action;
        cout << endl
            << endl;

        switch (action)
        {
        case 1:
            Create(S, 0, N);
            break;
        case 2:
            Print(S, N);
            break;
        case 3:
            cin.get();
            cin.sync();

            cout << "Введіть назву файлу: ";
            cin.getline(filename, 99);
            SaveToFile(S, N, filename);
            break;
        case 4:
            cin.get();
            cin.sync();

            cout << "Введіть назву файлу: ";
            cin.getline(filename, 99);
            LoadFromFile(S, N, filename);
            break;
        case 5:
            
        case 6:
            List_of_students_with_5(S, N);
        case 7:
            List_of_students_with_3(S, N);
        case 8:
            List_of_students_with_2(S, N);
        case 0:
            return 0;


            return 0;
        }
    } while (action != 0);
}
void Create(Exam_List* S, int N_start, const int N)
{
    for (N_start; N_start < N; N_start++)
    {
        cout << "Студент №" << N_start + 1 << endl;
        cout << "Прізвище: ";
        cin >> S[N_start].surname;
        cout << "Ініціали студента: ";
        cin >> S[N_start].initials;
        cout << "Оцінка з фізики: ";
        cin >> S[N_start].grade_physics;
        cout << "Оцінка з математики: ";
        cin >> S[N_start].grade_math;
        cout << "Оцінка з ІОТ: ";
        cin >> S[N_start].grade_computer_science;
        cout << "Оцінка з історії: ";
        cin >> S[N_start].grade_history;
        cout << "Оцінка з англійської мови: ";
        cin >> S[N_start].grade_english;
        cout << endl;
    }
}
void Print(Exam_List* S, const int N)
{
    cout << "===========================================================================================================================================" << endl;
    cout << "| № |  Прізвище  |  Ініціали  |  Оцінка з фізики  |  Оцінка з математики  |   Оцінка з ІОТ  |   Оцінка з історії  |  Оцінка з англійської мови  |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(2) << i + 1 << setw(2);
        cout << "|" << setw(10) << S[i].surname << setw(9);
        cout << "|" << setw(8) << S[i].initials << setw(9);
        cout << "|" << setw(10) << S[i].grade_physics << setw(10);
        cout << "|" << setw(10) << S[i].grade_math << setw(11);
        cout << "|" << setw(10) << S[i].grade_computer_science << setw(11);
        cout << "|" << setw(10) << S[i].grade_history << setw(11);
        cout << "|" << setw(10) << S[i].grade_english << setw(11);
    }
    cout << endl <<"==================================================================================" << endl
        << endl;
}
void SaveToFile(Exam_List* S, const int N, const char* filename)
{
    ofstream fout(filename, ios::binary);

    fout.write((char*)&N, sizeof(N));

    for (int i = 0; i < N; i++)
        fout.write((char*)&S[i], sizeof(Exam_List));

    fout.close();
}
void LoadFromFile(Exam_List*& S, int& N, const char* filename)
{
    delete[] S;

    ifstream fin(filename, ios::binary);

    fin.read((char*)&N, sizeof(N));

    S = new Exam_List[N];

    for (int i = 0; i < N; i++)
        fin.read((char*)&S[i], sizeof(Exam_List));

    fin.close();
}
void List_of_students_with_5(Exam_List* S, const int N)
{
    cout << "Список студентів, що склали іспити тільки на «5»:" << endl;
    for(int i=0;i<N;i++)
    {
        if(S[i].grade_computer_science==5 && S[i].grade_english == 5 && S[i].grade_history==5 && S[i].grade_math==5 && S[i].grade_physics==5)
        {
            cout<<S[i].surname<<" "<<S[i].initials<<endl;
        }
    }
}
void List_of_students_with_3(Exam_List* S, const int N)
{
    cout << "Список студентів, що мають трійки:" << endl;
    for (int i = 0; i < N; i++)
    {
        if (S[i].grade_computer_science == 3 || S[i].grade_english == 3 || S[i].grade_history == 3 || S[i].grade_math == 3 || S[i].grade_physics == 3)
        {
            cout << S[i].surname << " " << S[i].initials << endl;
        }
    }
}
void List_of_students_with_2(Exam_List* S, const int N)
{
    int IF = 0;
    cout << "Список студентів, що мають двійки:" << endl;
    for (int i = 0; i < N; i++)
    {
        if (S[i].grade_computer_science == 2)
        {
            IF++;
            cout << S[i].surname << " " << S[i].initials << endl;
        }
        if(S[i].grade_english == 2)
        {
            IF++;
        }
        if (S[i].grade_history == 2 == 2)
        {
            IF++;
        }
        if (S[i].grade_math == 2)
        {
            IF++;
        }
        if (S[i].grade_physics == 2)
        {
            IF++;
        }
        if (IF == 1)
        {
            cout << S[i].surname << " " << S[i].initials << endl;
        }

    }
}

