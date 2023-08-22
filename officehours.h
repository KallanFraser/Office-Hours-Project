#ifndef OFFICEHOURS
#define OFFICEHOURS

#include <iostream> //for rand, else it would have been put in main
#include <queue>

using namespace std;

class officeHours
{
public:
    officeHours(int seed)
    {
        srand(seed);
        timePassed = 0;
        professorBusy = false;
        arrivalRate = 0.2;
        serviceRate = 0.25;
        totalStudentWaitTime = totalProfessorStudentTime = totalStudents = afterHours = 0;
        averageWait = averageProfessorStudentTime = 0;
    }

    bool newStudent()
    {
        if (rand() < (arrivalRate * RAND_MAX))
        {
            return true;
        }
        return false;
    }

    bool studentFinished()
    {
        if (rand() < (serviceRate * RAND_MAX))
        {
            return true;
        }
        return false;
    }

    void startOfficeHour();

    double getAverageWait() { return averageWait; }

    double getAverageProfessorTime() { return averageProfessorStudentTime; }

    int getAfterHours() { return afterHours; }

private:
    queue<double> students;

    int timePassed, afterHours;

    bool professorBusy;

    double arrivalRate, serviceRate;

    int totalStudentWaitTime, totalStudents, totalProfessorStudentTime;

    double averageWait, averageProfessorStudentTime;
};

#endif