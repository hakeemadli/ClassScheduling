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

/*
    this function is used for sorting all
    processes in increasing order of burst time
*/
bool comparison(Process a, Process b)
{
    return (a.duration < b.duration);
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].duration + wt[i];
}
//waiting time of all process
void findWaitingTime(Process proc[], int n, int wt[]) {
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].duration;
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].arrival_time <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if (check == false) {
            t++;
            continue;
        }
        // decrementing the remaining time
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;
        // If a process gets completely
        // executed
        if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            // Calculate waiting time
            wt[shortest] = finish_time -
                           proc[shortest].duration -
                           proc[shortest].arrival_time;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        // Increment time
        t++;
    }
}
// Function to calculate average time
void findAverageTime(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0,
            total_tat = 0;
    // Function to find waiting time of all
    // processes
    findWaitingTime(proc, n, wt);
    // Function to find turn around time for
    // all processes
    findTurnAroundTime(proc, n, wt, tat);
    cout << "\nCourses " << " Burst time " << " Waiting time " << " Turn around time\n";
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].ccode << "\t\t\t" << proc[i].duration << "\t\t\t " << wt[i] << "\t\t\t " << tat[i] << endl;
    }
    cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}


// main function
int main()
{
    // process ids & burst time of all processes
    Process proc[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};

    int n = sizeof proc/ sizeof proc[0];

    sort(proc, proc + n, comparison);

    cout << "The order of scheduling for the courses\n";

    for (int i = 0 ; i < n; i++)
    {
        cout << proc[i].ccode <<", ";
    }

    findAverageTime(proc, n);

    return 0;
}