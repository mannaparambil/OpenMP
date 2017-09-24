#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

	int a=6, b=3;

	omp_set_num_threads(4);
	printf("The number of threads allocated are %d\n", omp_get_num_threads());

	
	#pragma omp parallel
	{
		int id = omp_get_thread_num();

		/* The program can be divided into different sections. Each of this
		   section can be done by a separate thtread. This is especially usefull when 
		   the section is independent of one another. */

		#pragma omp sections
		{
			#pragma omp section
			{
				printf("Sum = %d\n", a+b);
			}
	
			#pragma omp section 
			{
				printf("Difference = %d \n", a-b);
			}
		}

				
	}
}


