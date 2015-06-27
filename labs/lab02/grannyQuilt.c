/* Section 03 */
/* Lonnie Bissmeyer */

#include <stdio.h>
#include <math.h>

#define PI 3.141593
#define BUTTON_COST 2.0
#define FRINGE_COST 20.0

int main(void)
{
  int diameter, fabric_cost, num_people, radius, circumference, circle_area;
  double total_cost, cost_per_person;
  
  printf("Enter integer diameter of circle in feet: ");
  scanf("%d", &diameter);
  printf("Enter fabric cost per square foot in cents: ");
  scanf("%d", &fabric_cost);
  printf("Enter number of people sewing: ");
  scanf("%d", &num_people);
  
  radius = (diameter/2);  
  circle_area = (PI * pow((radius/2), 2));
  circumference = (2 * PI * (radius/2));
  ceil(total_cost = ((fabric_cost * circle_area) + (BUTTON_COST * 12 * (radius *4)) +
  (FRINGE_COST * circumference)));
  ceil(cost_per_person = (total_cost/num_people));
  
  printf("The circle area is %f square feet.\n", circle_area);
  printf("The circumference is %f square feet.\n", circumference);
  printf("Total cost is %f cents.\n", total_cost);
  printf("Cost per person is %f cents.\n", cost_per_person);

  return (0);
}
