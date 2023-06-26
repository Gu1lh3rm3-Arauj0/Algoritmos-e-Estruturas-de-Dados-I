#include <stdio.h>
#include <stdbool.h>

bool isConsistent(char transcription[]) {
    int countX = 0;
    int countO = 0;

    for (int i = 0; i < 3; i++) {
        if (transcription[i] == 'X') {
            countX++;
        } else if (transcription[i] == 'O') {
            countO++;
        }
    }

    if (countX == countO || countX == countO + 1) {
        return true;
    } else {
        return false;
    }
}

bool isWinner(char transcription[], char player) {
    for (int i = 0; i < 2; i++) {
        if (transcription[i] == player && transcription[i + 1] == player) {
            return true;
        }
    }

    return false;
}

int main() {
    char transcription[4];
    scanf("%s", transcription);

    if (!isConsistent(transcription)) {
        printf("?\n");
    } else if (isWinner(transcription, 'X')) {
        printf("Alice\n");
    } else if (isWinner(transcription, 'O')) {
        printf("Bob\n");
    } else {
        printf("*\n");
    }

    return 0;
}
