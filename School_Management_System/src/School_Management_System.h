/*
 ============================================================================
 Name        : School_Management_System.h
 Author      : Ahmed Abdel-Monem El-Askary
 Description : This project is focused on student record services in
               school, so it is named “School Management System”.
 Date        : 16/10/2023
 ============================================================================
 */

#ifndef SCHOOL_MANAGEMENT_SYSTEM_H_
#define SCHOOL_MANAGEMENT_SYSTEM_H_


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef struct {
	int student_id;
	int score;
	char address[100];
	char name[50];
	char date_birth[20];
	char phone_number[20];
} Student;

typedef struct Node {
	Student student;
	struct Node* next;
} Node;

/*******************************************************************************
 *                               Global variables                              *
 *******************************************************************************/

Student students[100];
int num_students = 0;
Node* head = NULL;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * This function displays the welcome screen and targeted activates
 */
void main_menu();

/*
 * Description :
 * This function creates a new student account. it asks about details of the
   student such as name, date of birth, ID, address and phone number.
 */
void new_student();

/*
 * Description :
 * This function is for deleting a customer account.
 */
void delete_student();

/*
 * Description :
 * This function, you can view the students information such as name, date of
   birth, ID, address and phone number in table form (alphabetically ascending).

 */
void student_list();

/*
 * Description :
 * This function has been used for updating a particular student account.
 */
void student_edit();

/*
 * Description :
 * This function can sort all students according to computer science score
 */
void rank_student();

/*
 * Description :
 * This function has been used for updating score of all students.
 */
void student_score();



#endif /* SCHOOL_MANAGEMENT_SYSTEM_H_ */
