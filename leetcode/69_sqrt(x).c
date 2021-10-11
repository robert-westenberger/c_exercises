#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, 
and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, 
such as pow(x, 0.5) or x ** 0.5.

*/
#define EPSILON 0.5

int mySqrtCalc(int x, double currentGuess, int numGuesses) {
    double newGuess = 0.5 * (currentGuess + ( x / currentGuess));
    double testVal = fabs(x - (newGuess * newGuess));
    if (testVal < EPSILON) {
        int answer = newGuess;
        int correctAnswer = sqrt(x);
        char correctly[10] = "correctly";
        char incorrect[12] = "incorrectly";
        printf("sqrt(%d)=%d guessed %s in %d attempts. \n", x, 
        answer,
        answer == correctAnswer ? correctly : incorrect,
        numGuesses
        );
        return answer;
    }
    return mySqrtCalc(x, newGuess, numGuesses + 1);
}
int mySqrt(int x){
    if (x == 0 || x == 1) {
        return x;
    }

    return mySqrtCalc(x, x / 2, 0); 
}
int main()
{   
    int root7 = mySqrt(8);
    return 0;

}