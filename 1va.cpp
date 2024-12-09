#include <iostream>

using namespace std;

bool isLeapYear(int year) {

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }

    return false;
}

void getNextDay(int day, int month, int year) {

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    day++;

    if (day > daysInMonth[month - 1]) {
        day = 1;
        month++;

        if (month > 12) {
            month = 1;
            year++;
        }
    }

    const char* months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    const char* daysOfWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    //(Zeller's congruence)
    int adjustedMonth = month;
    int adjustedYear = year;
    if (adjustedMonth < 3) {
        adjustedMonth += 12;
        adjustedYear--;
    }

    int q = day;
    int m = adjustedMonth;
    int K = adjustedYear % 100;
    int J = adjustedYear / 100;

    int weekday = (q + ((13 * (m + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;

    if (weekday < 0) {
        weekday += 7;
    }

    weekday = (weekday + 5) % 7;

    cout << daysOfWeek[weekday] << ", " << day << ", " << months[month - 1] << ", " << year << endl;

}

int main() {

    int day, month, year;

    cout << "Enter day, month, and year (e.g., 31 12 1989): ";
    cin >> day >> month >> year;

    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
        cout << "Invalid date!" << endl;
        return 1;
    }

    getNextDay(day, month, year);

    return 0;
}