/*
DIMOND PRBLEM
BASE     class student ---> data members rn, name[20]
DERIVED  class internalexam ----> data members marks
DERIVED class Final exam ----> data members marks

*/

#include<iostream>

using namespace std;

class Student{
    int rn;
    char name[20];

    public:
        void getData(){
            cout << "Enter student roll no.: ";
            cin >> rn;
            cout << "Enter student name: ";
            cin >> name;
        }

        void showData(){
            cout << "Roll No.: " << rn << endl;
            cout << "Name: " << name << endl;
        }
};

class InternalExam : virtual public Student{       //Virtual inheritance is used to handle multiple inheritance scenarios where a class is derived from multiple base classes that have a common ancestor.
    protected: 
        int m[7];

    public:
        void getExamData(){
            cout << "Enter the marks student got in 7 subjects in internal exam: ";
            for(int i=0; i<7; i++){
                cin >> m[i];
            }
        }

        void showData(){
            for(int i=0; i<7; i++){
                cout << m[i] << endl;
            }
            cout << endl;
        }
};

class FinalExam : virtual public Student{
    protected:
        int m[7];
    
    public:
        void getExamData(){
            cout << "Etner the marks student got in 7 subjects in final exam: ";
            for(int i=0; i<7; i++){
                cin >> m[i];
            }
        }

        void showData(){
            for(int i=0; i<7; i++){
                cout << m[i] << endl;
            }
            cout << endl;
        }
};

class avgMark : public InternalExam, public FinalExam{
    float marks;

    public:
        
        void calculate(){
            int total;
            float avg;

            for(int i=0; i<7; i++){
                total += (InternalExam::m[i] + FinalExam::m[i]);
            }

            avg = (int)(total)/14;
            marks = avg;
        }

        void showData(){
            Student::showData();
            cout << "Internal exam marks: " << endl;
            InternalExam::showData();
            cout << "Final exam marks: " << endl;
            FinalExam::showData();
            cout << "Average Marks: " << marks;
        }
};

int main(){
    avgMark A;

    A.getData();
    A.InternalExam::getExamData();
    A.FinalExam::getExamData();
    A.calculate();
    A.showData();

    return 0;
}