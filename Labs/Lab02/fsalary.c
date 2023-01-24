
/* Gordon Rose

 * 1/24 @ 1pm

 * lab 02 - salary.c

 * compile with: $ make salary

 * notes: none

 */

#include <stdio.h>

 

int main(void) 

{

    float hourly_wage = 0.0;
    int num_of_weeks = 0;
    printf("Enter hourly wage (float): ");
    scanf("%f",&hourly_wage);
    printf("Enter number of weeks (integer): ");
    scanf("%d",&num_of_weeks);
    printf("Annual salary is: ");

    printf("%.2f", hourly_wage * 40.0 * (double) num_of_weeks);

    printf("\n");

 

    return 0;

}


