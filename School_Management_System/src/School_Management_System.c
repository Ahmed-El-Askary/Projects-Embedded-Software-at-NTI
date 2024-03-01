/*
 ============================================================================
 Name        : School_Management_System.c
 Author      : Ahmed Abdel-Monem El-Askary
 Description : This project is focused on student record services in
               school, so it is named “School Management System”.
 Date        : 16/10/2023
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "School_Management_System.h"
/*******************************************************************************
 *                        Main School Management System Functions                           *
 *******************************************************************************/

int main()
{
	while (1)
	{
		main_menu();
	}
	return 0;
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * This function displays the welcome screen and targeted activates
 */
void main_menu()
{
	int choice;
	printf("Welcome to the School Management System\n");
	fflush(stdout);
	printf("1. New Student\n");
	printf("2. Delete Student\n");
	printf("3. Student List\n");
	printf("4. Edit Student\n");
	printf("5. Rank Students\n");
	printf("6. Update Student Score\n");
	printf("0. Exit\n");
	printf("Enter your choice: ");
	fflush(stdout);
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		new_student();
		break;
	case 2:
		delete_student();
		break;
	case 3:
		student_list();
		break;
	case 4:
		student_edit();
		break;
	case 5:
		rank_student();
		break;
	case 6:
		student_score();
		break;
	case 0:
		printf("Exiting the program...\n");
		fflush(stdout);
		exit (0) ;
	default:
		printf("Invalid choice. Please try again.\n");
		fflush(stdout);
		break;
	}
}

/*
 * Description :
 * This function creates a new student account. it asks about details of the
   student such as name, date of birth, ID, address and phone number.
 */
void new_student()
{
	Student new_student;
	printf("Enter Student Details:\n");
	fflush(stdout);
	printf("Name: ");
	fflush(stdout);
	scanf("%s", new_student.name);
	printf("Date of Birth: ");
	fflush(stdout);
	scanf("%s", new_student.date_birth);
	printf("ID: ");
	fflush(stdout);
	scanf("%d", &new_student.student_id);
	printf("Address: ");
	fflush(stdout);
	scanf("%s", new_student.address);
	printf("Phone Number: ");
	fflush(stdout);
	scanf("%s", new_student.phone_number);

	new_student.score = 0;

	students[num_students] = new_student;
	num_students++;

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->student = new_student;
	new_node->next = NULL;

	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		Node* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}

	printf("New student added successfully.\n");
	fflush(stdout);
}

/*
 * Description :
 * This function is for deleting a customer account.
 */
void delete_student()
{
	int id;
	printf("Enter the ID of the student to delete: ");
	fflush(stdout);
	scanf("%d", &id);

	int i, found = 0;
	for (i = 0; i < num_students; i++)
	{
		if (students[i].student_id == id)
		{
			found = 1;
			break;
		}
	}

	if (found)
	{
		int j;
		for (j = i; j < num_students - 1; j++)
		{
			students[j] = students[j + 1];
		}
		num_students--;

		Node* current = head;
		Node* prev = NULL;
		while (current != NULL) {
			if (current->student.student_id == id)
			{
				if (prev == NULL)
				{
					head = current->next;
				}
				else
				{
					prev->next = current->next;
				}
				free(current);
				break;
			}
			prev = current;
			current = current->next;
		}

		printf("Student deleted successfully.\n");
		fflush(stdout);
	}
	else
	{
		printf("Student not found.\n");
		fflush(stdout);

	}
}

/*
 * Description :
 * This function, you can view the students information such as name, date of
   birth, ID, address and phone number in table form (alphabetically ascending).

 */

void student_list()
{
	int i, j;
	for (i = 0; i < num_students - 1; i++)
	{
		for (j = 0; j < num_students - i - 1; j++)
		{
			if (strcmp(students[j].name, students[j + 1].name) > 0)
			{
				Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}

	printf("Student List:\n");
	fflush(stdout);
	printf("---------------------------------------------------------------------------------------\n");
	fflush(stdout);
	printf("ID\tName\t\tDOB\t\tAddress\t\tPhone Number\t\tScore\t\t\n");
	fflush(stdout);

	for (i = 0; i < num_students; i++)
	{
		printf("%d\t%s\t\t%s\t%s\t\t%s\t\t%d\t\t\n", students[i].student_id, students[i].name,students[i].date_birth ,students[i].address ,students[i].phone_number , students[i].score);
	}

	printf("---------------------------------------------------------------------------------------\n");
	fflush(stdout);
}

/*
 * Description :
 * This function has been used for updating a particular student account.
 */

void student_edit()
{
	int id;
	printf("Enter the ID of the student to edit: ");
	fflush(stdout);
	scanf("%d", &id);

	int i, found = 0;
	for (i = 0; i < num_students; i++)
	{
		if (students[i].student_id == id)
		{
			found = 1;
			break;
		}
	}

	if (found)
	{
		printf("Enter new details for the student:\n");
		fflush(stdout);
		printf("Name: ");
		fflush(stdout);
		scanf("%s", students[i].name);
		printf("Date of Birth: ");
		fflush(stdout);
		scanf("%s", students[i].date_birth);
		printf("Address: ");
		fflush(stdout);
		scanf("%s", students[i].address);
		printf("Phone Number: ");
		fflush(stdout);
		scanf("%s", students[i].phone_number);

		printf("Student details updated successfully.\n");
		fflush(stdout);
	}
	else
	{
		printf("Student not found.\n");
		fflush(stdout);
	}

}
/*
 * Description :
 * This function can sort all students according to computer science score
 */

void rank_student()
{
	int i, j;
	for (i = 0; i < num_students - 1; i++)
	{
		for (j = 0; j < num_students - i - 1; j++)
		{
			if (students[j].score < students[j + 1].score)
			{
				Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}

	printf("Ranked Students:\n");
	fflush(stdout);
	printf("-----------------------------------------------------\n");
	fflush(stdout);
	printf("ID\tName\t\tScore\n");
	fflush(stdout);
	printf("-----------------------------------------------------\n");
	fflush(stdout);

	for (i = 0; i < num_students; i++)
	{
		printf("%d\t%s\t\t%d\n", students[i].student_id, students[i].name, students[i].score);
	}
	printf("-----------------------------------------------------\n");
	fflush(stdout);
}

/*
 * Description :
 * This function has been used for updating score of all students.
 */
void student_score()
{
	int id;
	printf("Enter the ID of the student to update score: ");
	fflush(stdout);
	scanf("%d", &id);

	int i, found = 0;
	for (i = 0; i < num_students; i++)
	{
		if (students[i].student_id == id)
		{
			found = 1;
			break;
		}
	}

	if (found)
	{
		printf("Enter the new score for the student: ");
		fflush(stdout);
		scanf("%d", &students[i].score);

		printf("Student score updated successfully.\n");
		fflush(stdout);
	}
	else
	{
		printf("Student not found.\n");
		fflush(stdout);
	}
}
