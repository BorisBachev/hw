#include <iostream>

using namespace std;

int power(int num, int x) {

    int result = 1;

    for (int i = 0; i < x; i++) {
        result *= num;
    }

    return result;
}

int getLen(long long num) {

    int count = 0;

    while (num != 0) {
        count++;
        num /= 10;
    }

    return count;

}

void convertNumberToLetters(long long number) {
    char wordResult[100];
    int resultIndex = 0;

    cout << "Number: " << number << endl;

    while (number > 0) {
        int len = getLen(number);
        cout << "Length: " << len << endl;

        int firstTwoDigits = number / power(10, len - 2);

        if (len >= 2) {
            cout << "First Two Digits: " << firstTwoDigits << endl;

            if (firstTwoDigits <= 26 && firstTwoDigits >= 10) {
                wordResult[resultIndex++] = char('a' + firstTwoDigits - 1);
                number %= power(10, len - 2);
                cout << "Edit After First Two Digits: " << number << endl;
                cout << "--------------------------------------------" <<endl;
                continue;
            }

        }

        int firstDigit = number / power(10, len - 1);
        cout << "Single Digit: " << firstDigit << endl;

        if (firstDigit > 0) {
            cout << "Is adding single digit" << endl;
            wordResult[resultIndex++] = char('a' + firstDigit - 1);
        }

        if (firstTwoDigits % 10 == 0) {
            cout << "Is adding \".\" for two digits: " << firstTwoDigits << endl;
            wordResult[resultIndex++] = char('.');
        }

        number %= power(10, len - 1);
        cout << "Edit after single digit: " << number << endl;
        cout << "--------------------------------------------" <<endl;
    }

    wordResult[resultIndex] = '\0';
    cout << "Converted result: " << wordResult << endl;
}


int main() {

    long long number;

    cout << "Enter a number: ";
    cin >> number;
    cout << endl;

    convertNumberToLetters(number);

    return 0;
}
