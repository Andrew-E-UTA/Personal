#include <stdio.h>

#define NMEMAX 20

typedef int thousands;

typedef struct
{
	int x;
	int y;

}point;

typedef struct
{
	char name[NMEMAX];
	thousands population;
	point location;
}city;

int main(void)
{
	point dallasLoc = {9, 8};
	point houstonLoc = {2, 6};

	city Dallas = {"Dallas", 134, {dallasLoc.x, dallasLoc.y}};
	city Houston ={"Houston", 278, {houstonLoc.x,houstonLoc.y}};

	printf("%s is at (%d,%d) with population size of %d,000 people\n", Dallas.name, 
												dallasLoc.x, dallasLoc.y, Dallas.population);
	printf("%s is at (%d,%d) with population size of %d,000 people\n", Houston.name, 
												houstonLoc.x, houstonLoc.y, Houston.population);	

	return(0);
}
