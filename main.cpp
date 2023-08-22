#include "officehours.h"
#include <ctime> // used to get system time to be passed in as a seed to seed the rand function

int main()
{
    double averageWait, averageStudentProfessorTime, averageAfterHours = 0;

    for (size_t i = 0; i < 100; i++)
    {
        officeHours tester(time(nullptr));

        tester.startOfficeHour();

        averageWait += tester.getAverageWait();

        averageStudentProfessorTime += tester.getAverageProfessorTime();

        averageAfterHours += tester.getAfterHours();
    }
    averageWait /= 100;
    averageStudentProfessorTime /= 100;
    averageAfterHours /= 100;

    cout << "Average Wait = " << averageWait;
    cout << "\nAverage Student Professor Time = " << averageStudentProfessorTime;
    cout << "\nAverage After Hour Time Spent = " << averageAfterHours;
}
