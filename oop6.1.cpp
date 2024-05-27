#include <iostream>
#include <string>
using namespace std;
class part
{
    int year;
public:
    part() { year = 1970; }
    part(int input) { year = input; };
    ~part() {};

    void setyear(int input) { year = input; }
    int getyear() { return year; }
    void printyear() { cout << "Year: " << year << endl; }
};

class hdd : private part
{
    int capacity;
    string name;
public:
    hdd() : part() { capacity = 0; }
    hdd(int year, int cap, string inpname) : part(year) { capacity = cap; name = inpname; }
    ~hdd() {};

    void setcap(int input) { capacity = input; }
    int getycap() { return capacity; }
    void setname(const string& input) { name = input; }
    const string* getname() { return &name; }
    void print() { cout << "Capacity: " << capacity << ", Name: " << name << ", "; printyear(); }
};

class ssd : private part
{
    int capacity;
    int written;
public:
    ssd() : part() { capacity = 0; }
    ssd(int year, int cap, int totalwritten) : part(year) { capacity = cap; written = totalwritten; }
    ~ssd() {};

    void setcap(int input) { capacity = input; }
    int getcap() { return capacity; }
    void setwritten(int input) { written = input; }
    int getwritten() { return written; }
    void print() { cout << "TBW: " << capacity << ", Currently written: " << written << ", "; printyear(); }
};

class monitor : private part
{
    int diagonal;
    int resX;
    int resY;
    int freq;
    int written;
public:
    monitor() : part() { diagonal = 0; resX = 0; resY = 0; freq = 0; }
    monitor(int year, int diagonalinp, int resolutionX, int resolutionY, int frequency) : part(year) { diagonal = diagonalinp; resX = resolutionX; resY = resolutionY; freq = frequency; }
    ~monitor() {};

    void setdiag(int input) { diagonal = input; }
    int getdiag() { return diagonal; }
    void setfreq(int input) { freq = input; }
    int getfreq() { return freq; }
    void setres(int& inpX, int& inpY) { resX = inpX; resY = inpY; }
    void getres(int& inpX, int& inpY) { inpX = resX; inpY = resY; }
    void print() { cout << "Diagonal: " << diagonal << ", Resolution: " << resX << "x" << resY << ", Frequency: " << freq << ", "; printyear(); }
};

class processor : private part
{
    string model;
    int cores;
    int freq;
public:
    processor() : part() { cores = 0; freq = 0; }
    processor(int year, int ncores, int frequency, string name) : part(year) { model = name;  cores = ncores; freq = frequency; }
    ~processor() {};

    void setmodel(string input) { model = input; }
    const string& getmodel() { return model; }
    void setfreq(int input) { freq = input; }
    int getfreq() { return freq; }
    void setcores(int ncores) { cores = ncores; }
    int getcores() { return cores; }
    void print() { cout << "Model: " << model << ", Cores: " << cores << ", Frequency: " << freq << ", "; printyear(); }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    hdd HDD(2015, 128, (string)"Kingston");
    HDD.print();
    ssd SSD(2017, 512, 321);
    SSD.print();
    monitor Screen(2022, 17, 1050, 720, 144);
    Screen.print();
    processor AMD(2072, 16, 6, (string)"INTEL");
    AMD.print();
}