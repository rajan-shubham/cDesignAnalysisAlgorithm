#include <stdio.h>
#include <stdlib.h>
typedef struct {
int id;
int deadline;
int profit;
} Job;
int compareJobs(const void *a, const void *b) { Job
*jobA = (Job *)a;
Job *jobB = (Job *)b;
return jobB->profit - jobA->profit;
}
int findMaxDeadline(Job jobs[], int n) {
int max = jobs[0].deadline;
for (int i = 1; i < n; i++) {
if (jobs[i].deadline > max)
{ max = jobs[i].deadline;
}
}
return max;
}
void jobSequencing(Job jobs[], int n) {
qsort(jobs, n, sizeof(Job), compareJobs);
int maxDeadline = findMaxDeadline(jobs, n);
int result[maxDeadline + 1];
for (int i = 0; i <= maxDeadline; i++)
{ result[i] = -1;
}
int totalProfit = 0;
for (int i = 0; i < n; i++) {
for (int j = jobs[i].deadline; j > 0; j--) {
if (result[j] == -1)
{ result[j] =
jobs[i].id;
totalProfit += jobs[i].profit;
break;
}
}
}
printf("Scheduled Jobs:\n");
for (int i = 1; i <= maxDeadline; i++) {
if (result[i] != -1) {
printf("Job %d at slot %d\n"
, result[i], i);
}
}
printf("Total Profit: %d\n"
, totalProfit);
}
int main() {
int n;
printf("Enter the number of jobs: "); scanf("%d",
&n);
Job jobs[n];
for (int i = 0; i < n; i++) {
printf("Enter the details for job %d (deadline and profit): "
, i + 1); jobs[i].id =
i + 1;
scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
}
printf("Given jobs:\n");
for (int i = 0; i < n; i++) {
printf("Job %d: Deadline = %d, Profit = %d\n"
, jobs[i].id, jobs[i].deadline, jobs[i].profit);
}
jobSequencing(jobs, n);
return 0;
}

/*
Enter the number of jobs: 5
Enter the details for job 1 (deadline and profit): 2 20
Enter the details for job 2 (deadline and profit): 2 15
Enter the details for job 3 (deadline and profit): 1 10
Enter the details for job 4 (deadline and profit): 3 5
Enter the details for job 5 (deadline and profit): 3 1
Given jobs:
Job 1: Deadline = 2, Profit = 20
Job 2: Deadline = 2, Profit = 15
Job 3: Deadline = 1, Profit = 10
Job 4: Deadline = 3, Profit = 5
Job 5: Deadline = 3, Profit = 1
Scheduled Jobs:
Job 2 at slot 1
Job 1 at slot 2
Job 4 at slot 3
Total Profit: 40
*/