#include<iostream>
#include<fstream>
using namespace std;

struct student
{
    char fullName[100];
    int age;
    int course;
    char gender;  // 'M' - мужской пол, 'F' - женский пол
    double performance;
};

class Student
{
    student STUDENT;

public:
    void read()
    {

        cout << "FIO = ";
        cin.getline(STUDENT.fullName, 100);

        cin.get();
        cout << "Age = ";
        cin >> STUDENT.age;

        cin.get();
        cout << "Course = ";
        cin >> STUDENT.course;

        cin.get();
        cout << "Gender = ";
        cin >> STUDENT.gender;

        cin.get();
        cout << "Perfomance = ";
        cin >> STUDENT.performance;
    }

    void print()
    {
        cout << "FIO = " << STUDENT.fullName << endl;
        cout << "Age = " << STUDENT.age << endl;
        cout << "Course = " << STUDENT.course << endl;
        cout << "Gender = " << STUDENT.gender << endl;
        cout << "Performance = " << STUDENT.performance << endl;
    }

    Student() // not parametrs
    {
        strcpy_s(STUDENT.fullName, 100, " ");
        STUDENT.age = 0;
        STUDENT.course = 0;
        STUDENT.gender = '\0';
        STUDENT.performance = 0.0;
    }

    Student(const char* fullName_n, int age_n, int course_n, char gender_n, double performance_n) // with parametrs
    {
        strcpy_s(STUDENT.fullName, 100, fullName_n);
        STUDENT.age = age_n;
        STUDENT.course = course_n;
        STUDENT.gender = gender_n;
        STUDENT.performance = performance_n;
    }

    Student(const Student& other) // copied
    {
        strcpy_s(STUDENT.fullName, other.STUDENT.fullName);
        STUDENT.age = other.STUDENT.age;
        STUDENT.course = other.STUDENT.course;
        STUDENT.gender = other.STUDENT.gender;
        STUDENT.course = other.STUDENT.course;
        STUDENT.performance = other.STUDENT.performance;
    }

    Student(Student&& other) noexcept // peremeschenie
    {
        strcpy_s(STUDENT.fullName, other.STUDENT.fullName);
        STUDENT.age = other.STUDENT.age;
        STUDENT.course = other.STUDENT.course;
        STUDENT.gender = other.STUDENT.gender;
        STUDENT.course = other.STUDENT.course;
        STUDENT.performance = other.STUDENT.performance;

        strcpy_s(other.STUDENT.fullName, " ");
        other.STUDENT.age = 0;
        other.STUDENT.course = 0;
        other.STUDENT.gender = '\0';
        other.STUDENT.course = 0;
        other.STUDENT.performance = 0.0;
    }

    void loadFile(ifstream& infile)
    {
        infile.read(reinterpret_cast<char*>(&STUDENT), sizeof(student));
    }

    void saveFile(ofstream& outfile)
    {
        outfile.write(reinterpret_cast<char*>(&STUDENT), sizeof(student));
    }

    student get()
    {
        return STUDENT;
    }

    void set(student s)
    {
        STUDENT = s;
    }
};



void filst(Student* arrayStudents, int numStudents)
{
    for (int i = 0; i < numStudents; ++i)
    {
        cout << "Введите данные для студента " << i + 1 << ":" << endl;
        arrayStudents[i].read();
    }
}

void readstd(Student* loadedStudents, int numStudents)
{
    for (int i = 0; i < numStudents; ++i)
    {
        loadedStudents[i].print();
        cout << endl;
    }
}

int loadFileBin(Student* arrayStudents, int numStudents, char* s)
{
    ofstream outFile(s, ios::binary);
    if (!outFile) {
        cout << "error1" << endl;
        return 1;
    }
    for (int i = 0; i < numStudents; ++i) {
        arrayStudents[i].saveFile(outFile);
    }
    outFile.close();
}

int sfbin(Student* students, const int size, char* s)
{

    ifstream inFile(s, ios::binary);
    if (!inFile) {
        cout << "error2" << endl;
        return 1;
    }

    for (int i = 0; i < size; ++i) {
        students[i].loadFile(inFile);
    }
    inFile.close();
}

int countMale(Student* loadedStudents, int numStudents, int course)
{
    int maleCount = 0;

    for (int i = 0; i < numStudents; ++i) {
        if (loadedStudents[i].get().course == course && loadedStudents[i].get().gender == 'M') {
            maleCount++;
        }
    }
    return maleCount;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    const int numStudents = 3;

    Student arrayStudents[numStudents];
    char s[] = "students.bin";
    filst(arrayStudents, numStudents);
    readstd(arrayStudents, numStudents);
    loadFileBin(arrayStudents, numStudents, s);

    Student loadedStudents[numStudents];
    sfbin(loadedStudents, numStudents, s);
    cout << "Данные студентов из файла:" << endl;
    readstd(loadedStudents, numStudents);

    int course;
    cout << "Enter course: ";
    cin >> course;

    int cnt = countMale(loadedStudents, numStudents, course);
    cout << "Количество мужчин на n курсе: " << cnt << endl;
}