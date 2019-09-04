#include <iostream>
using namespace std;

/*
    Equations from: http://mathforum.org/dr.math/faq/faq.calendar.html

    Code Author: Kyle Culp

    I used the Key Value Method. I tried to work with Zeller's Rule, but the negative numbers aspect of it was too complicated for me. 
    Sorry about the abuse of switch statements, but I do not know C++ well, and wanted to complete this project on my own, without any help.

    Also, please note that this program only works between the centuries 1700-2400. I am unsure of how to make it work with any century.
*/

static int getCentury(int century) {
    switch(century) {
        case 17: // 1700s
            return 4;
            break;
        case 18: // 1800s
            return 2;
            break;
        case 19: // 1900s
            return 0;
            break;
        case 20: // 2000s
            return 6;
            break;
        case 21: // 2100s
            return 4;
            break;
        case 22: // 2200s
            return 2;
            break;
        case 23: // 2300s
            return 0;
            break;
        case 24: // 2400s
            return 6;
            break;
        default:
            return 0;
            break;
    }
}

static int getNumOfWeek(int day, int month, int year) {
    int monthKey;
    int century = year / 100;
    switch(month) {
        case 1: // January
            monthKey = 1;
            break;
        case 2: // February
            monthKey = 4;
            break;
        case 3: // March
            monthKey = 4;
            break;
        case 4: // April
            monthKey = 0;
            break;
        case 5: // May
            monthKey = 2;
            break;
        case 6: // June
            monthKey = 5;
            break;
        case 7: // July
            monthKey = 0;
            break;
        case 8: // August
            monthKey = 3;
            break;
        case 9: // September
            monthKey = 6;
            break;
        case 10: // October
            monthKey = 1;
            break;
        case 11: // November
            monthKey = 4;
            break;
        case 12: // December
            monthKey = 6;
            break;
        default:
            monthKey = 0;
            break;
    }

    // This is miserable, but I'm terrible at naming the steps in an equation
    int stepOne = year % 100; // Take last two digits of the year
    int stepTwo = stepOne / 4; // Divide by four, dropping any remainder
    int stepThree = stepTwo + day; // Add the day of the month
    int stepFour = stepThree + monthKey; // Add months key
    int stepFive = stepFour + getCentury(century); // Add Century from Gregorian Calander
    int stepSix = stepFive + stepOne; // Add last two digits of the year
    int stepSeven = stepSix % 7; // Divide by 7, taking the remainder

    return stepSeven;
}


static string numToDay(int num) {
    string days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}; // Beginning on Sunday, as the Gregorian calander has it
    return days[num - 1]; // Arrays start at 0
}

int main() {
    int day, month, year;
    cout << "Please enter the day: ";
    cin >> day;
    cout << "Please enter the month: ";
    cin >> month;
    cout << "Please enter the year: ";
    cin >> year;

    int dayNum = getNumOfWeek(day, month, year); // Get number correlating to Gregorian week day
    cout << numToDay(dayNum); // Print out weekday

    return 0;
}
