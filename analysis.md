# Introduction

To be put into perspective of CPU scheduling, we've been assigned with task that was to find and analyzing the best scheculing alogrithm that will fits the references of scheduling the courses for students.

# Consideration

In order to find the best scheduling alogrithm for the given problem I've decided to chose Priorty scehduling as the main choices for solving the problem which will choose the best way of scheduling a class/courses according to students preference that's important courses with short duration are the first to be put into the class schedule (to be priortized). But, there is couple alogorithm that has been put into consideration that is "First come first serve" algorithm and also "Shortest job first" algorithm which will be compare to the Priorty scheduling based on its efficiency (running time/duration) and result produced (order of courses).

# Analysis

## FCFS (First Come First Serve)

FCFS also know as "first in, first out" which a batch system based algorithm that allow first process that has been queue to finish first (First requesting the CPU allocations).

**Advantages**

* It is a non-preemptive, pre-emptive scheduling algorithm.

* Easy to understand and implement.

**Disadavtages**

* Does not have optimal  average waiting times.
* Causing convoy effects where a process with short burst times has a to wait for long time which causing poor CPU utilization.
* It is an non-premptive alogrithm which its process priority is not the upmost important for the process to end but will resulitng in system crash if a high priority process comes through but have to wait for long time. In perspective of class scheduling, choosing the most important class first are the way to go, so, choosing this will make the importantance of the courses to be disregard.

**Result**

Below are the FCFS.cpp, given input and its output:

`Process processes[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};`

Output:

![Result](/Result/fcfs.png)



## SJF (Shortest Job First)

**Advatages**

* Best approach to minimize waiting time.

* Easy to implement in Batch systems where required CPU time is known in advance.

* The processer should know in advance how much time process will take.



**Disadvantages**

* Impossible to implement in interactive systems where required CPU time is not known.
* Can cause process starvations, where, the process with higher burst time had to wait for long time in the ready queue.

**Result**

Below are the SJF.cpp, given input and its output:

`Process processes[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};`

Output:

![result](/Result/sjf.png)


## Priority Scheduling

Priority scehduling is an alogrithm that is commonly used in batch system , where, each process was compared with each other arrival time but if the process has the same value of arrival time, it will used the highest number of process priorty. Meanwhile, if process also have a same value of priority it will consider based on the process burst time values ( lowest on will be choose first).

**Disadvantages**

* A ready process sometimes will block by CPU if there is still a process currently running.
* A low priority process has to wait for a long time to run, if there is incoming number of higher priorty processs in the ready queue which can cause a process starvations.

**Advantages**

* Can implement Aging Technique to prevent starvation to happen by increasing the priority value of the process that is already wait in the ready queue.

**Result**

Below are the Priority.cpp, given input and its output:

`Process processes[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};`

Output:

![result](/Result/Priority.png)




## Comparison

As given result that has been shown above, the most suitable algorithm that meet the students preferences in choosing a courses will be "Priorty Scheduling". the reason being, this algorithm has the most box checked for the student requirement that is:

1. Importantance of the courses 
2. The durations for the courses (shortest will be priortized)

For the FCFS alogtihm is the most suitable when processes are short and there is no need for the processes to execute in a specific order.  While for SJF algorithm, the best use cases is to be implement in a situation where the process waiting time should be minimized in order to get a specific process to run.



MADE BY:

MUHAMMAD HAKEEM ADLI BIN ABDUL RAHIM - 1817151

SECTION 1
