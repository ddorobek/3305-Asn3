/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* scheduler.c 
*
******************************************************************************/

#include "scheduler.h"

#define FCFS 0
#define LIFO 1
#define SJF 2
#define RR 3

job_t *get_next_job(int mode, d_linked_list_t* jobs) {
	
	// if the jobs list still has remaining jobs, execute this code.
	if(jobs->size != 0) {
		
		switch(mode) {
			case(FCFS) : // if First Come First Served, dequeue job at the head of jobs list and return job.
				
				return dequeue(jobs);
				
			case(LIFO) : // if Last In First Out, pop job at the tail of jobs list and return job.
				return pop(jobs);
				
			case(SJF) : // if Shortest Job First, return job from shortestJobFirst method.
				return shortestJobFirst(jobs);
				
			case(RR) : // if Round Robin, dequeue job at the head of jobs list and return job.		
				return dequeue(jobs);
			
			default : // otherwise return NULL.
				return NULL;
		}
		
	}
	
	return NULL; // if jobs list is empty return NULL.
	
}

job_t *shortestJobFirst(d_linked_list_t* jobs) {
		struct d_node *currentNode = jobs->head; // set currentNode to first node in jobs list.
		struct d_node *shortestNode = jobs->head; // set shortestNode to first node in jobs list.
		job_t *shortestJob = jobs->head->value; // set shortestJob to first job in jobs list.
		
		// while there are still jobs in jobs list to compare time to shortest node, execute this code.
		while(currentNode != NULL) {
			job_t *currentJob = currentNode->value;
			
			// if the current job has a shorter time than shortestJob, set this job to shortestJob and node to shortestNode.
			if((shortestJob->required_time > currentJob->required_time)) {
				shortestJob = currentJob;
				shortestNode = currentNode;
			}
			
			currentNode = currentNode->next; // check next job.
		}
		
		erase(jobs, shortestNode); // remove shortest job from jobs list.
		return shortestJob;
}