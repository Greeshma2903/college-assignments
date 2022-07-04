/*
  	Tina has been assigned the task of preparing the term end results of the students
	of Std VI. She has to accept the marks from the respective subject teacher, total
	the marks and assign the grades based on their percentage. Grade assignment: <40:
	F; 40 – 49: E; 50 –59:D; 60 – 69: C; 70 – 79: B; 80 – 89: A; 90 and above: A+. Develop
	a C program to aid Tina in this task.
	
	6 subjects, outof 100 marks
*/
#include<stdio.h>

int main()
{
 	float sub1, sub2, sub3, sub4, sub5, sub6, totalMark, percent;
 	char grade;
	
	// read marks
	printf("Enter student's subject marks in each of the 6 subjects(out of 100)--\n");
	
	printf("Subject 1: ");
	scanf("%f", &sub1);
    printf("Subject 2: ");
	scanf("%f", &sub2);
    printf("Subject 3: ");
	scanf("%f", &sub3);
    printf("Subject 4: ");
	scanf("%f", &sub4);
    printf("Subject 5: ");
	scanf("%f", &sub5);
    printf("Subject 6: ");
	scanf("%f", &sub6);


 	//calculate total marks and percentage
 	totalMark = sub1 + sub2 + sub3 + sub4 + sub5 + sub6;
 	percent = (totalMark/600) * 100;
		
    // assign grades based on percentage
 	if(percent>= 90 && percent <= 100) {
         grade = 'A';
     } 
     else if (percent >= 80 && percent<= 89)
     {
         grade = 'A';
     }
     else if(percent >= 70 && percent <= 79)
     {
         grade = 'B';
     }
     else if(percent >= 60 && percent<= 69)
     {
         grade = 'C';
     }
     else if (percent >= 50 && percent <= 59)
     {
         grade = 'D';
     }
     else if (percent >= 40 && percent <= 49)
     {
         grade = 'E';
     }
     else {
         grade = 'F';
     }
     
     
     printf("\nThe student's, \nTotal Marks(of 600):%f \nPercentage:%f \nGrade:%c", totalMark, percent, grade);
 	
	return 0;
}

