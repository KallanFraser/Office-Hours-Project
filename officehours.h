#include <iostream>
#include <queue>

using namespace std;

class officeHours
{
public:
    officeHours(int seed)
    {
        srand(seed);
        int timeLeft = 60;
        professorBusy = false;
        arrivalRate = 0.2;
        serviceRate = 0.25;
        totalStudentWaitTime = totalProfessorStudentTime = totalStudents = afterHours = 0;
    }

    void startOfficeHour();

private:
    queue<int> students;

    int timeLeft;

    bool professorBusy;

    double arrivalRate, serviceRate;

    double totalStudentWaitTime, totalStudents, totalProfessorStudentTime;

    int afterHours;
};