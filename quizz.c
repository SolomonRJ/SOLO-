#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a question
struct Question {
    char question[256];
    char answers[4][64];
    int correctAnswerIndex;
};

// Function to display a question and its options
void displayQuestion(struct Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.answers[i]);
    }
}

// Function to get user input and validate it
int getUserAnswer() {
    int answer;
    do {
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
    } while (answer < 1 || answer > 4);

    return answer - 1;  // Adjust to 0-based index
}

// Function to check if the user's answer is correct
int isCorrectAnswer(struct Question q, int userAnswer) {
    return userAnswer == q.correctAnswerIndex;
}

int main() {
    // Array of questions
    struct Question questions[] = {
        {"What is the capital of France?", {"Paris", "Berlin", "London", "Madrid"}, 0},
        {"Who is the Prime Minister of India?", {"Rahul Gandhi", "Narendra Modi", "Cristiano Ronaldo", "Solomon"}, 1},
        // Add more questions as needed
    };

    // Number of questions
    int numQuestions = sizeof(questions) / sizeof(questions[0]);

    // Score counter
    int score = 0;

    // Game loop
    for (int i = 0; i < numQuestions; i++) {
        // Display the current question
        displayQuestion(questions[i]);

        // Get user input
        int userAnswer = getUserAnswer();

        // Check if the answer is correct
        if (isCorrectAnswer(questions[i], userAnswer)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is: %s\n", questions[i].answers[questions[i].correctAnswerIndex]);
        }

        printf("Current Score: %d\n\n", score);
    }

    // Display final score
    printf("Quiz completed! Your final score: %d/%d\n", score, numQuestions);

    return 0;
}
