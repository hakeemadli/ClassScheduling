/* MUHAMMAD HAKEEM ADLI BIN ABDUL RAHIM - 1817151 - SECTION 1 */

#include<iostream>
using namespace std;

struct Process
{
    int ccode;     // course code
    int duration;      // class duration
    int priority;  //priority
    int arrival_time;   //prefered arrival time
};

// sort the processes based on priority
bool sortProcesses(Process a, Process b)
{
    return (a.priority > b.priority);
}

// Function to find the waiting time for all processes
void findWaitingTime(Process proc[], int n,
                     int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int  i = 1; i < n ; i++ )
        wt[i] =  proc[i-1].duration + wt[i-1] ;
}

// Function to calculate turn around time
void findTurnAroundTime( Process proc[], int n,
                         int wt[], int tat[])
{
    // calculating turnaround time by adding
    // duration[i] + wt[i]
    for (int  i = 0; i < n ; i++)
        tat[i] = proc[i].duration + wt[i];
}

//Function to calculate average time
void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    //Function to find waiting time of all processes
    findWaitingTime(proc, n, wt);

    //Function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);

    //Display processes along with all details
    cout << "\nCourses  "<< " Burst time  "
         << " Waiting time  " << " Turn around time " << " Priority \n";

    // Calculate total waiting time and total turn
    // around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].ccode << "\t\t\t"
             << proc[i].duration << "\t\t    " << wt[i]
             << "\t\t\t  " << tat[i] <<"\t\t\t\t\t"<< proc[i].priority <<endl;
    }

    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n)
{
    // Sort processes by priority
    sort(proc, proc + n, sortProcesses);

    cout<< "The order of scheduling for the courses \n";
    for (int  i = 0 ; i <  n; i++)
        cout << proc[i].ccode <<", " ;

    findavgTime(proc, n);
}

// Driver code
int main()
{
    // process ids & burst time of all processes
    Process proc[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};

    int n = sizeof proc/ sizeof proc[0];

    priorityScheduling(proc, n);
    return 0;
}