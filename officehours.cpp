#include "officehours.h"

void officeHours::startOfficeHour()
{
    int temp = 0;

    while (!students.empty() || professorBusy || timePassed <= 60)
    {
        if (timePassed <= 60) // is there a new student?
        {
            if (newStudent())
            {
                students.push(timePassed);
                totalStudents++;
            }
        }
        else
        {
            afterHours++;
        }

        if (!students.empty() && !professorBusy) // is professor free and there is at least one student outside?
        {
            temp = timePassed - students.front();
            students.pop();
            totalStudentWaitTime += temp;
            professorBusy = true;
        }

        if (professorBusy) // is current student finished with professor yet?
        {
            totalProfessorStudentTime++;
            if (studentFinished())
            {
                professorBusy = false;
            }
        }
        timePassed++;
    }
    averageProfessorStudentTime = totalProfessorStudentTime;
    averageProfessorStudentTime /= totalStudents;
    averageWait = totalStudentWaitTime;
    averageWait /= totalStudents;
}