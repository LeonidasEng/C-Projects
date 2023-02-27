#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* --- Prototyping --- */

/* Menus (plus Future Menus) */
void menu_load();
void menu_Angle();
void menu_Area();
void menu_Lengths();

/* Clear Screen */
void clearScreen();

/* Conversion Functions */
// Angle
double degrees_2_radians(double degrees);
double radians_2_degrees(double radians); 

// Area
double sqmiles_2_sqkilometres(double sqmiles);
double sqkilometres_2_sqmiles(double sqkilometres);
double sqmetres_2_sqfeet(double sqmetres);
double sqfeet_2_sqmetres(double sqfeet);
double sqmetres_2_sqinches(double sqmetres);
double sqinches_2_sqmetres(double sqinches);
double sqmeters_2_sqcentimetres(double sqmetres);
double sqcentimetres_2_sqmetres(double sqcentimetres);
double convertArea(double area, char unit, char output_unit); 

// Distance
double miles_2_kilometres(double miles);
double kilometres_2_miles(double kilometres);
double metres_2_feet(double metres);
double feet_2_metres(double feet);
double convertDistance(double distance, char unit, char output_unit);

/*******************************************************************/

/* --- Main --- */

int main(int argc, char **argv)
{
    menu_load();
    return 0;
}

void menu_load() {
    char choice;
    do {
        printf("-------------------- Conversion Tool - For Engineers --------------------\n");
        printf("*************************************************************************\n");
        
        printf("\n--- Main Menu ---\n");
        printf("1. Angle Conversions\n");
        printf("2. Area Conversions\n");
        printf("3. Length Conversions\n");
        printf("h. Help\n");
        printf("x. Exit\n");
        printf("Please enter your choice: ");
        
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                menu_Angle();
                break;
            case '2':
                menu_Area();
                break;
            case '3':
                menu_Lengths();
                break;
            case 'x':
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'x');
}

/*******************************************************************/

/* --- Menu Functions --- */

void menu_Angle() {
    int choice;
    double angle;
    char unit;

    do {
        printf("\n--Angle Conversions--\n");
        printf("1. Angle Conversion\n");
        printf("0. Return to Main Menu: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter an angle (e.g. 30d or 3r): ");
            scanf("%lf%c", &angle, &unit);

            if (unit == 'd') 
            {
                double radians = degrees_2_radians(angle);
                printf("%.3lf degrees is equal to %.3lf radians.\n", angle, radians);
                break;
            } else if (unit == 'r') 
            {
                double degrees = radians_2_degrees(angle);
                printf("%.3lf radians is equal to %.3lf degrees.\n", angle, degrees);
                break;
            } else 
            {
                printf("Invalid unit.\n");
            }    
            break;
        case 0:
            printf("Returning to Main Menu...");
        default:
            printf("Invalid choice. Please try again. \n");
            break;
        }
    } while (choice != 0);
}


void menu_Area() {
    int choice;
    double area, result;
    char unit, output_unit;
    do {
        printf("\n--Area Conversions--\n");
        printf("1. Area Conversions\n");
        printf("0. Return to Main Menu: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the area: ");
            scanf("%lf", &area);
            printf("Enter the input unit of measurement (M/m/f/i/c): ");
            scanf(" %c", &unit);
            printf("Enter the output unit of measurement (M/m/f/i/c): ");
            scanf(" %c", &output_unit);

            result = convertArea(area, unit, output_unit);
            printf("Area: %.3lf%c^2 is equal to %.3lf%c^2\n", area, unit, result, output_unit);
            break;
        case 0:
            printf("Returning to Main Menu...");
        default:
            printf("Invalid choice. Please try again. \n");
            break;
        }
    } while (choice != 0);
}

void menu_Lengths() {
    int choice;
    double distance, result;
    char unit, output_unit;
    do {
        printf("\n--Length Conversions--\n");
        printf("1. Length Conversions\n");
        printf("0. Return to Main Menu: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a distance: ");
            scanf("%lf", &distance);
            printf("Enter the input unit of measurement (M/k/m/f): ");
            scanf(" %c", &unit);
            printf("Enter the output unit of measurement (M/k/m/f): ");
            printf(" %c", &output_unit);

            result = convertDistance(distance, unit, output_unit);
            printf("Distance: %.3lf%c is equal to %.3lf%c", distance, unit, result);
            break;
        case 0:
            printf("Returning to Main Menu...");
        default:
            printf("Invalid choice. Please try again. \n");
            break;
        }
    } while (choice != 0);
}

/*******************************************************************/

/* To be used when  everything else is complete */
void clearScreen() 
{
    #ifdef _WIN32 // For Windows-base
        system("cls");
    #endif
}

/*---------------- Angle functions ----------------*/

double degrees_2_radians(double degrees)
{
    return degrees * M_PI / 180.0;
}

double radians_2_degrees(double radians)
{
    return radians * 180.0 / M_PI;
}

/*---------------- Area functions ----------------*/

double sqmiles_2_sqkilometres(double sqmiles) {
    return sqmiles * 2.59;
}

double sqkilometres_2_sqmiles(double sqkilometres) {
    return sqkilometres / 2.59;
}

double sqmetres_2_sqfeet(double sqmetres) {
    return sqmetres * 10.7639;
}

double sqfeet_2_sqmetres(double sqfeet) {
    return sqfeet / 10.7639;
}

double sqmetres_2_sqinches(double sqmetres) {
    return sqmetres * 1550;
}

double sqinches_2_sqmetres(double sqinches) {
    return sqinches / 1550;
}

double sqmeters_2_sqcentimetres(double sqmetres) {
    return sqmetres * 10000;
}

double sqcentimetres_2_sqmetres(double sqcentimetres) {
    return sqcentimetres * 10000;
}

double convertArea(double area, char unit, char output_unit) {
    double result;

    if (unit == output_unit) {
        return area;
    } 
    else if (unit == 'k' && output_unit == 'M') {
        result = sqkilometres_2_sqmiles(area);
    } else if (unit == 'M' && output_unit == 'k') {
        result = sqmiles_2_sqkilometres(area);
    } else if (unit == 'm' && output_unit == 'f') {
        result = sqmetres_2_sqfeet(area);
    } else if (unit == 'f' && output_unit == 'm') {
        result = sqfeet_2_sqmetres(area);
    } else if (unit == 'm' && output_unit == 'i') {
        result = sqmetres_2_sqinches(area);
    } else if (unit == 'i' && output_unit == 'm') {
        result = sqinches_2_sqmetres(area);
    } else if (unit == 'm' && output_unit == 'c') {
        result = sqmeters_2_sqcentimetres(area);
    } else if (unit == 'c' && output_unit == 'm') {
        result = sqcentimetres_2_sqmetres(area);
    } else {
        result = area;
    }

    return result;
}

/*---------------- Distance functions ----------------*/

double miles_2_kilometres(double miles) {
    return miles * 1.60934;
}

double kilometres_2_miles(double kilometres) {
    return kilometres / 1.60934;
}

double metres_2_feet(double metres) {
    return metres * 3.281;
}

double feet_2_metres(double feet) {
    return feet / 3.281;
}

double convertDistance(double distance, char unit, char output_unit) {
    double result;

    if (unit == output_unit) {
        return distance;
    } else if (unit == 'M' && output_unit == 'k') {
        result = miles_2_kilometres(distance);
    } else if (unit == 'k' && output_unit == 'M') {
        result = kilometres_2_miles(distance);
    } else if (unit == 'm' && output_unit == 'f') {
        result = metres_2_feet(distance);
    } else if (unit == 'f' && output_unit == 'm') {
        result = feet_2_metres(distance);
    } else {
        result = distance;
    }

    return result;
}

