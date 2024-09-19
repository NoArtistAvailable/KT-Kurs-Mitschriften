#include <iostream>
#include <string>

using namespace std;

int main() {
    int score = 0;  // Track user's score
    string userAnswer;

    // This is where we'll simulate getting a question from ChatGPT API
    string question = "What is the capital of France?";
    string a = "a) Berlin";
    string b = "b) Madrid";
    string c = "c) Paris";
    string d = "d) Rome";
    char correctAnswer = 'c';  // This will be hidden in actual API response

    // Game loop (one question for now)
    cout << question << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;

    // Ask user for their answer
    cout << "Your answer (a, b, c, d): ";
    cin >> userAnswer;

    // Check if the answer is correct
    if (userAnswer == string(1, correctAnswer)) {
        cout << "Correct!" << endl;
        score++;
    }
    else {
        cout << "Incorrect. The correct answer was " << correctAnswer << "." << endl;
    }

    // Show the user's score
    cout << "Your score: " << score << endl;

    return 0;
}