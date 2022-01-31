/*
 program 1 :
 speed1 = 40miles/hr
 speed2 = 1.5*speed1 = 60 miles/hr
 speed3 = 2.25*speed1 = 90 miles/hr
 
 time = distance/speed
 average speed = (total distance / total time)
*/
#include<stdio.h>

int main(){
	float d1, d2, d3, t1, t2, t3;
	float avgSpeed;
	printf("(Enter distance in miles)\n");
	printf("\nEnter the distance from A to B:");
	scanf("%f", &d1);
	
	printf("\nEnter the distance from B to C:");
	scanf("%f", &d2);
	
	printf("\nEnter the distance from C to D:");
	scanf("%f", &d3);
	
	//	calculate time in hours
	t1 = d1/40;
	t2 = d2/60;
	t3 = d3/90;
	
	float time = t1 + t2 + t3;
	float dist = d1 + d2 + d3;
	
	// calculate speed 
	avgSpeed = dist / time;
	printf("\nThe average speed taken to travel from A to D is %f miles/hr", avgSpeed);
	
	return 0;
}
