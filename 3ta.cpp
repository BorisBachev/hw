#include <iostream>

using namespace std;

const int MAX_TEXT_LENGTH = 1000;
const int MAX_TWEET_LENGTH = 280;

int getLen(const char* text) {

    int length = 0;

    while (text[length] != '\0') {
        length++;
    }

    return length;
}

void splitAndPrintTweets(const char* text, int maxLength) {

    int start = 0;
    int length = getLen(text);

    while (start < length) {

        int end = start + maxLength;

        if (end < length && text[end] != ' ') {
            while (end > start && text[end] != ' ') {
                --end;
            }
        }

        char tweet[MAX_TWEET_LENGTH + 1] = {0};

        for (int i = 0; i < end - start; ++i) {
            tweet[i] = text[start + i];
        }

        tweet[end - start] = '\0';

        if (start == 0) {
            cout << "\nTraicho tweeted: " << tweet << endl;
        } else {
            cout << "\n--------------------Traicho tweeted: " << tweet << endl;
        }

        start = end;

        while (start < length && text[start] == ' ') {
            start++;
        }

    }

}

int main() {

    char inputText[MAX_TEXT_LENGTH + 1];

    cout << "Enter text (up to 1000 characters):\n";
    cin.getline(inputText, MAX_TEXT_LENGTH + 1);

    if (getLen(inputText) > MAX_TEXT_LENGTH) {
        cout << "Input text exceeds 1000 characters. Please try again." << endl;
        return 1;
    }

    splitAndPrintTweets(inputText, MAX_TWEET_LENGTH);

    return 0;
}
