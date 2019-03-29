//Author: Steven Williams
//CSCI 6011
//Mid term problem 2 
#include<stdio.h>
#include<string.h>

//Student info to include name, code(position in the array +1), and the number grade.
struct student{
	char name[10];
	char code[3];
	int grade;
};

//Definition for populate (see below main)
void populate(struct student stuArray[]);

void sorting_of_grades(struct student stuArray[]){
	//Sort students in the array of structures in ascending order using a temp structure
	struct student a;

	//Compare ith element with ith + 1 element and put the lowest grade first
	//Uses student a as a placeholder to switch if necessary
	for(int i = 0; i < 20; i++){
		for(int j = i + 1; j < 20; ++j){
			if(stuArray[i].grade > stuArray[j].grade){
				strcpy(a.name, stuArray[i].name);
				strcpy(a.code, stuArray[i].code);
				a.grade = stuArray[i].grade;
				
				strcpy(stuArray[i].name, stuArray[j].name);
				strcpy(stuArray[i].code, stuArray[j].code);
				stuArray[i].grade = stuArray[j].grade;
				
				strcpy(stuArray[j].name, a.name);
				strcpy(stuArray[j].code, a.code);
				stuArray[j].grade = a.grade;
			}
		}
	}
}

//Calculate the average of student grades and print out the students who have a grade higher than the average.
void display_students(struct student stuArray[]){
	int sum = 0;
	int avg = 0;

	for(int i = 0; i < 20; i++){
		sum += stuArray[i].grade;
	}
	avg = sum / 20;
	
	for(int i = 0; i < 20; i++){
		if(stuArray[i].grade > avg){
			printf("%s received a grade of %d, which is hihger than the average of %d.\n", stuArray[i].name, stuArray[i].grade, avg);
			printf("\n");
		}
	}
}

//Main function, 20 students in the array. Call functions to populate, sort, and print.
int main(void)
{
	int size = 20;
	
	struct student stuArray[size];

	populate(stuArray);
	sorting_of_grades(stuArray);
	display_students(stuArray);
	

	return 0;
}

//Manually populate insted of taking user input. Repetive but easier. Program functionality is the same.
void populate(struct student stuArray[]){
	strcpy(stuArray[0].name, "John");
	strcpy(stuArray[0].code, "01");
	stuArray[0].grade = 77;

	strcpy(stuArray[1].name, "Sam");
	strcpy(stuArray[1].code, "02");
	stuArray[1].grade = 67;

	strcpy(stuArray[2].name, "Gillie");
	strcpy(stuArray[2].code, "03");
	stuArray[2].grade = 70;

	strcpy(stuArray[3].name, "Ed");
	strcpy(stuArray[3].code, "04");
	stuArray[3].grade = 55;

	strcpy(stuArray[4].name, "Liza");
	strcpy(stuArray[4].code, "05");
	stuArray[4].grade = 80;

	strcpy(stuArray[5].name, "Sansa");
	strcpy(stuArray[5].code, "06");
	stuArray[5].grade = 50;

	strcpy(stuArray[6].name, "Aya");
	strcpy(stuArray[6].code, "07");
	stuArray[6].grade = 90;

	strcpy(stuArray[7].name, "Bran");
	strcpy(stuArray[7].code, "08");
	stuArray[7].grade = 85;

	strcpy(stuArray[8].name, "Riccon");
	strcpy(stuArray[8].code, "09");
	stuArray[8].grade = 66;

	strcpy(stuArray[9].name, "Geoffrey");
	strcpy(stuArray[9].code, "10");
	stuArray[9].grade = 71;

	strcpy(stuArray[10].name, "Jaime");
	strcpy(stuArray[10].code, "11");
	stuArray[10].grade = 84;

	strcpy(stuArray[11].name, "Steven");
	strcpy(stuArray[11].code, "12");
	stuArray[11].grade = 99;

	strcpy(stuArray[12].name, "Robert");
	strcpy(stuArray[12].code, "13");
	stuArray[12].grade = 89;

	strcpy(stuArray[13].name, "Dani");
	strcpy(stuArray[13].code, "14");
	stuArray[13].grade = 25;

	strcpy(stuArray[14].name, "Jora");
	strcpy(stuArray[14].code, "15");
	stuArray[14].grade = 82;

	strcpy(stuArray[15].name, "Taiwen");
	strcpy(stuArray[15].code, "16");
	stuArray[15].grade = 91;

	strcpy(stuArray[16].name, "Faris");
	strcpy(stuArray[16].code, "17");
	stuArray[16].grade = 63;

	strcpy(stuArray[17].name, "Bruce");
	strcpy(stuArray[17].code, "18");
	stuArray[17].grade = 44;

	strcpy(stuArray[18].name, "Gregory");
	strcpy(stuArray[18].code, "19");
	stuArray[18].grade = 87;

	strcpy(stuArray[19].name, "Searcy");
	strcpy(stuArray[19].code, "20");
	stuArray[19].grade = 94;
	
}