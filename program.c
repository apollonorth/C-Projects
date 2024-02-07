//Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Constant declarations
#define TRUE 1
#define FALSE 0

//Function declarations
void display_menu();
void execute_menu_choice(int choice);
double compute_pi(int n);
double compute_sqrt(double x);
int is_prime(int n);
void display_primes(int n);
void process_scores();
double compute_tax(int income, char *status, char state);
int quadratic(double a, double b, double c, double *solution1, double *solution2);
int sum_squares(int n);
void file_count(char *file, int *characters, int *blanks, int *lines);
void file_sort(char *infile, char *outfile);
void file_student(char *infile);


//main
int main()
{
    printf("First Program\n");
 
    int choice = 0;
    //do while loop so it always executes unconditionally the first loop
    do {
        //Display menu
        display_menu();

        //Get input 1-11 and store in choice
        do {
            scanf("%d", &choice);
            //If input is outside menu options, give message and retry
            if(choice < 1 || choice > 11)
                printf("Please input an integer 1-11:\n");
            //Clear input buffer
            char buffer[100];
            gets(buffer);
        } while(choice < 1 || choice > 11);

        //Call function to execute menu choices 1-10
        if(choice != 11)
            execute_menu_choice(choice);
    }
    while(choice != 11); //When user inputs 11, program ends
}

//Print interactive menu
void display_menu() {
    printf("Menu (input an integer 1-11): \n");
    printf("1-computing pi\n2-computing square root\n3-displaying primes\n4-processing grades\n5-computing tax\n");
    printf("6-solving quadratic\n7-computing sum squares\n8-counting file\n9-sorting file\n10-student file\n11-quit\n");
}

void execute_menu_choice(int choice) {
    //Switch statement to handle choices 1-10
    switch(choice) {
        case 1: { //Prompt and scan input
                printf("How many terms should be used to compute pi? ");
                int n = 0;
                scanf("%d", &n);
                //Store the return double into pi variable and print it
                double pi = compute_pi(n);
                printf("Pi is approximately %lf\n\n", pi);
                break;
        }

        case 2: { //Prompt and scan input
                printf("What number do you want the square root of? ");
                double x;
                scanf("%lf", &x);
                //Get result from compute_sqrt function and return it
                double sqrt = compute_sqrt(x);
                printf("The approximate square root of %lf is %lf\n\n", x, sqrt);
                break;
        }

        case 3: { //Prompt and scan input
                printf("Primes should be found through what number? ");
                int n = 0;
                scanf("%d", &n);
                //Get results and print
                display_primes(n);
                break;
        }

        case 4: { //Call function, it handles input and output
                process_scores();
                break;
        }

        case 5: { //Prompt and scan input
                int income = 0;
                char status[30];
                char state;
                printf("Income (positive integer): ");
                scanf("%d", &income);
                getchar (); // Eat extra space or other char
                printf("Married or single? ");
                scanf("%s", status);
                getchar();
                printf("In or out of state? (i or o): ");
                scanf("%c", &state);
                double tax_amount = compute_tax(income, status, state);
                printf("Tax amount: %lf\n\n", tax_amount);
                break;
        } 

        case 6: { //Prompt and scan input
                double a, b, c;
                printf("Enter a, b, and c seperated by spaces for the equation ax^2 + bx + c = 0: ");
                scanf("%lf %lf %lf", &a, &b, &c);

                //Create pointers to doubles
                double solution1, solution2;
            
                //Pass correct arguments, including addresseses of solution 1 and 2 and store whether answers exist in int
                int answers = quadratic(a, b, c, &solution1, &solution2);
                //If there are answers (answers == TRUE) print correct output
                if(answers == 1) {
                    printf("\nReal solutions exist\n");
                    printf("Solution 1: %lf\nSolution 2: %lf", solution1, solution2);
                }
                //Else no real answers exist, output that
                else {
                    printf("\nNo real solutions exist\n");
                    printf("Solution 1: %lf\nSolution 2: %lf", solution1, solution2);
                }
                //Print new lines before menu
                printf("\n\n");
                break;
        }

        case 7: { //Prompt and scan input
                int n;
                printf("Find the sum of squares up to what number? ");
                //Make sure input is a positive integer
                do{
                    scanf("%d", &n);
                    if(n < 1)
                        printf("Please input a positive integer: ");
                } while(n < 1);

                //Get answer and output
                int sum = sum_squares(n);
                printf("\nSum of squares from 1 to %d: %d", n, sum);

                //Print new lines
                printf("\n\n");
                break;
        }

        case 8: { //Prompt and scan input
                char file[30];
                printf("What is the file name? (file must be in same dir as program): ");
                scanf("%s", file);
                
                //Create variables to pass address of to function
                int characters = 0;
                int blanks = 0;
                int lines = 0;

                //Call function
                file_count(file, &characters, &blanks, &lines);
                //Print output:
                printf("Characters: %d\nBlanks: %d\nLines: %d", characters, blanks, lines);
                printf("\n\n");
                break;
        }

        case 9: { //Prompt and scan input
                char input[30];
                char output[30];
                printf("Files should be in the same directory as the program\n");
                printf("What is the name of the input file? ");
                scanf("%s", input);
                printf("What is the name of the output file? ");
                scanf("%s", output);
                
                //Call function
                file_sort(input, output);
                break;
        }

        case 10: { //Prompt and scan input
                char file[30];
                printf("File must be in same directory as program.\nWhat is the name of the input file? ");
                scanf("%s", file);
                //Call function
                file_student(file);
                break;
        }               
    }    
}

//Approximate pi: 4(1-(1/3)+(1/5)-(1/7)+(1/9)-(1/11)+...)
double compute_pi(int n) {
    //Declare variables to keep track of pi and denominator for the function throughout loop
    double pi = 0.0;
    double denominator = 1;
    for(int i = 0; i < n; i++) {
        //If index is even (ex: 0, 2, 4), perform addition
        if(i % 2 == 0) 
            pi += 1.0 / denominator;
        //If index is odd (ex: 1, 3, 5), perform subtraction
        else
            pi -= 1.0 / denominator;
        //Increment denominator by 2
        denominator += 2;
    }
    //Multiply result of n addtions/subtractions by 4 for final result
    pi = pi * 4;
    return pi;
}

//Compute the approximate square root of a number x
double compute_sqrt(double x) {
    //Start with last = 1.0 and declare next
    double last = 1.0;
    double next;
    //Follow formula of 10 repetitions of next = 0.5(last + x / last)
    for(int i = 0; i < 10; i++) {
        next = 0.5*(last + x / last);
        //Update last variable
        last = next;
    }
    //Return approximate square root
    return next;
}

void display_primes(int n) {
    //First print variable to correctly output comma seperated values
    int first_print = TRUE;
    printf("Primes from 1 to %d: ", n);
    //Traverse from 2 to n, calling is_prime(i) each loop
    for(int i = 2; i <= n; i++) {
        //If prime, go to print, if false, end this loop iteration and go to next i
        if(is_prime(i) == TRUE) {
            //If this is the first prime printed, just print prime
            if(first_print == TRUE) {
                printf("%d", i);
                //Set first_print to false so we can add commas/spaces to future outputs
                first_print = FALSE;
            }
            //After first print, print comma and space before each output
            else {
                printf(", %d", i);
            }
        }
    }
    //Print new lines before menu is reprinted
    printf("\n\n");
}

int is_prime(int n) {
    //Loop from 2 to n-1 attempting to evenly divide n, return false if n modulo i = 0
    for(int i = 2; i < n; i++) {
        if (n % i == 0)
            return FALSE;
    }
    //Return TRUE if we traverse loop without finding an evenly divisble number in this range
    return TRUE;
}

void process_scores() {
    //Declare variables to store name and score of students and min/max
    char name[30];
    int score;
    char name_max[30];
    char name_min[30];
    //Set max to below minimum to always be updated on first loop, min to very high num
    int score_max = -1;
    int score_min = 999999;
    //Get count variable for dividing to find average, and sum variable
    int count = 0;
    int sum = 0;
    //Variable to see if it is first iteration, exit without printing if so
    int first_loop = TRUE;
    do {
        //Reset variables, name with null character
        name[0] = '\0';
        score = 0;

        //Prompt and scan input
        printf("Please enter a student name and score (enter 'q' or 'Q' to quit): ");
        scanf("%s", name);
        //Only continue if user did not input Q or q
        if(name[0] == 'q' || name[0] == 'Q') {
            if(first_loop == TRUE) {
                printf("No scores entered.\n\n");
                return;
            }    
            else
                break;
        }
        scanf("%d", &score);

        //Add score to sum and increment count variable
        sum += score;
        count++;

        //Check for max and update if it is higher than max
        if(score > score_max) {
            score_max = score;
            strcpy(name_max, name);
        }
        //Check for min and update if lower than min
        if(score < score_min) {
            score_min = score;
            strcpy(name_min, name);
        }

        //Update first_loop
        first_loop = FALSE;
    } while(TRUE); //Infinite loop, break condition inside loop
    
    //Calculate average and output average, min, and max scores
    double average = (double)sum / count;
    printf("\nAverage Score: %lf\nMinimum Score: %s - %d\nMaximum Score: %s - %d", average, name_min, score_min, name_max, score_max);
    //Print new lines before menu is reprinted
    printf("\n\n");
}

double compute_tax(int income, char *status, char state) {
    double tax_rate;
    //Change state to lower and check if input is valid
    state = tolower(state);
    if(state != 'o' && state != 'i') {
        printf("Invalid state staus.\n");
        return -1;
    }

    //Check for valid input
    if(income < 0) {
        printf("Invalid income.\n");
        return -1;
    }

    //Change status to lowercase and check if valid
    int length = strlen(status);
    for(int i = 0; i < length; i++) {
        *(status+i) = tolower(*(status+i));
    }
    if(strcmp(status, "married") != 0 && strcmp(status, "single") != 0) {
        printf("Invalid marital status.\n");
        return -1;
    }
    
    //Married and income greater than or equal $60,000 means 25% tax, less means 20% tax
    if(strcmp(status, "married") == 0) {
        if(income >= 60000)
            tax_rate = 0.25;
        else
            tax_rate = 0.20;
    }
    //Only other option is that status = "SINGLE" bc we already checked it was one of the two
    else {
        if(income >= 40000) 
            tax_rate = 0.35;
        else
            tax_rate = 0.30;
    }

    //Check for in or out of state, subtract 3% if out of state
    if(state == 'o')
        tax_rate -= 0.03;
    
    //Calculate tax amount with income and rate, return
    double tax_amount = income * tax_rate;
    return tax_amount;
}

int quadratic(double a, double b, double c, double *solution1, double *solution2) {
    //Calculate discriminant b^2 -4ac to check for num of solutions
    double d = b * b - 4 * a * c;
    //If d is less than 0, assign -1 to output parameters and return false
    if(d < 0) {
        *solution1 = -1.0;
        *solution2 = -1.0;
        return FALSE;
    }

    //Otherwise execute quadratic equation, store in the variables that solution1 and 2 point to
    else {
        *solution1 = (-b + sqrt(d))/(2 * a);
        *solution2 = (-b - sqrt(d))/(2 * a);
        return TRUE;
    }
}

int sum_squares(int n) {
    //Base case n = 1, return 1
    if(n == 1)
        return 1;
    //Otherwise return (n*n + recursively call sum_squares)
    else {
        return n * n + sum_squares(n - 1);
    }
}

void file_count(char *file, int *characters, int *blanks, int *lines) {
    //Create file pointer and open file with read privilege
    FILE *fp;
    fp = fopen(file, "r");

    //Create char variable to hold each individual character while traversing
    char ch;
    while((ch = getc(fp)) != EOF) {
        //Increment characters var
        (*characters)++; 

        //Check if it is white space or new line and increment if so
        if(ch == ' ') 
            (*blanks)++;
        
        if(ch == '\n')
            (*lines)++;
    }
    //Increment lines again as there is one more line than new line characters
    (*lines)++;
}

void file_sort(char *infile, char *outfile) {
    //Create file pointer and open file with read privilege
    FILE *input = fopen(infile, "r");
    //Create another filepointer for outputing
    FILE *output = fopen(outfile, "w");

    //Avoid program errors by returning if input or output file is null
    if(input == NULL || output == NULL) {
        printf("Incorrect input or output file name.\n\n");
        return;
    }

    //Get num of students variable and scan number from first line of file
    int number_students;
    fscanf(input, "%d", &number_students);

    //Dynammically allocate memory to arrays
    int *ids = (int *) (malloc(number_students * sizeof(int)));
    char *grades = (char *) (malloc(number_students * sizeof(char)));
    double *gpas = (double *) (malloc(number_students * sizeof(double))); 

    //Use fscanf for every student, collecting information in order of input
    for(int i = 0; i < number_students; i++) {
        fscanf(input, "%d %c %lf", &ids[i], &grades[i], &gpas[i]);
    }

    //Use selection sort to sort students by ids 
    int min;
    int temp_int;
    char temp_ch;
    double temp_double;
    for(int i = 0; i < number_students; i++) {
        min = i;
        //Find index of next minimum in array
        for(int j = i + 1; j < number_students; j++) {
            if(ids[j] < ids[min]) {
                min = j;
            }
        }
        //Swap student information
        //Swap IDs
        temp_int = ids[i];
        ids[i] = ids[min];
        ids[min] = temp_int;
        //Swap Grades
        temp_ch = grades[i];
        grades[i] = grades[min];
        grades[min] = temp_ch;
        //Swap GPAS
        temp_double = gpas[i];
        gpas[i] = gpas[min];
        gpas[min] = temp_double;
    }

    //Output the now formatted students to output file
    //Start with number of students, like input file format
    fprintf(output, "%d\n", number_students);

    //Loop as many times as there are students, printing sorted output line by line
    for(int i = 0; i < number_students; i++) {
        fprintf(output, "%d %c %lf\n", ids[i], grades[i], gpas[i]);
    }

    //Free Arrays
    free(ids);
    free(grades);
    free(gpas);

    //Close files
    fclose(input);
    fclose(output);

    //Print to notify of output
    printf("Successfully outputted to \"%s\"\n\n", outfile);
}

void file_student(char *infile) {
    //Create student structure with necessary fields
    struct student {
        char name[30];
        int id;
        int age;
        double gpa;
    };

    //Open input file and read number of students
    int number_students;
    FILE *fp = fopen(infile, "r");
    //Check if file is valid
    if(fp == NULL) {
        printf("File Error.");
        return;
    }
    fscanf(fp, "%d", &number_students);

    //Create array of structures and dynammically allocate memory
    struct student *array;
    array = (struct student *) malloc(number_students * sizeof(struct student));

    //Read info from file into structures
    for(int i = 0; i < number_students; i++) {
        fscanf(fp, "%s %d %d %lf", array[i].name, &array[i].id, &array[i].age, &array[i].gpa);
    }

    //Find sum of gpas for average
    double sum = 0;
    for(int i = 0; i < number_students; i++) {
        sum += array[i].gpa;
        
    }
    //Calculate average and print
    double average = sum / number_students;
    printf("\nAverage GPA: %lf", average);

    //Print students with 3.0 or less GPA
    printf("\nStudents with a GPA less than or equal to 3.00: ");
    //For formatting the comma seperation
    int first_print = TRUE;
    for(int i = 0; i < number_students; i++) {
        //Check if gpa below 3 and print, print comma before value if not the first value
        if(array[i].gpa <= 3.00) {
            if(first_print == FALSE)
                printf(", ");
            printf("%s", array[i].name);
            first_print = FALSE;
        }
    }

    //Sort id in ascending order
    //Use selection sort to sort students
    int min;
    char temp_str[30];
    int temp_int;
    char temp_ch;
    double temp_double;
    for(int i = 0; i < number_students; i++) {
        min = i;
        //Find index of next minimum in array
        for(int j = i + 1; j < number_students; j++) {
            if(array[j].id < array[min].id) {
                min = j;
            }
        }
        //Swap student information
        //Swap Names
        strcpy(temp_str, array[i].name);
        strcpy(array[i].name, array[min].name);
        strcpy(array[min].name, temp_str);
        //Swap IDs
        temp_int =array[i].id;
        array[i].id = array[min].id;
        array[min].id = temp_int;
        //Swap Ages
        temp_ch = array[i].age;
        array[i].age = array[min].age;
        array[min].age = temp_ch;
        //Swap GPAS
        temp_double = array[i].gpa;
        array[i].gpa = array[min].gpa;
        array[min].gpa = temp_double;
    }

    //Print now sorted student information
    printf("\nSorted Student Information: \n");
    for(int i = 0; i < number_students; i++) {
        printf("%s %d %d %lf\n", array[i].name, array[i].id, array[i].age, array[i].gpa);
    }

    printf("\n");

    //Close file and free allocated memory
    fclose(fp);
    free(array);
}