/* Gordon Rose

 * 1/24 @ 1pm

 * lab 02 - salary.c

 * compile with: $ make salary

 * notes: none

 */

#include <stdio.h>

 

int main(void) 

{

    int hourly_wage = 20;
    printf("Enter hourly wage (integer): ");
    scanf("%d",&hourly_wage);
 
    printf("Annual salary is: ");

    printf("%d", hourly_wage * 40 * 50);

    printf("\n");

 

    return 0;

}


