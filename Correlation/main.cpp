#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string ReturnTextInLowerCase(string inputText);
double GetANumber();
double FindCovariance(double standardDeviationX, double standardDeviationY, double correlationCoefficient);
double FindBetaOne(double covarianceXY, double standardDeviationX);
double FindBetaZero(double betaOne, double averageX, double averageY);
double FindPredictedYValue(double xValue, double betaZero, double betaOne);
int GetAnIntegerGreaterThanOrEqualToAValue(int minValue);
int TestQuestions(double betaZero, double betaOne, int numQuestions);
bool PromptUserYesNo(string question);
void SetValueRandomly(double& valueToBeRandomized);
void SetValueToInput(double& valueToSet, bool isStandardDeviation, bool isCorrelationCoefficient);
void SetValues(double& averageX, double& averageY, double& standardDeviationX,
               double& standardDeviationY, double& correlationCoefficient);


const string PHRASE_FOR_YES = "yes";
const double MIN_CORRELATION_COEFFICIENT = -1.0;
const double MAX_CORRELATION_COEFFICIENT = 1.0;
const double ERROR_SENSITIVITY = 0.01;
const int MAX_RANDOM_VALUE = 100;
const int MIN_RANDOM_VALUE = 0;
const int DEFAULT_NUM_TEST_QUESTIONS = 5;
const int MIN_TEST_QUESTIONS_ALLOWED = 1;

int main() {
    srand(time(0));

    double averageX;
    double averageY;
    double standardDeviationX;
    double standardDeviationY;
    double correlationCoefficient;
    double covarianceXY;
    double betaOne;
    double betaZero;

    cout << "Welcome to the economics regression quizzer!" << endl
    <<"This application tests your ability to calculate regressions!" << endl;
    SetValues(averageX, averageY, standardDeviationX, standardDeviationY, correlationCoefficient);

    covarianceXY = FindCovariance(standardDeviationX, standardDeviationY, correlationCoefficient);
    betaOne = FindBetaOne(covarianceXY, standardDeviationX);
    betaZero = FindBetaZero(betaOne, averageX, averageY);

    cout << "List of constants:" << endl;
    cout << "Average of x (mu x): " << averageX << endl;
    cout << "Average of y (mu y): " << averageY << endl;
    cout << "Standard Deviation of x (sigma x): " << standardDeviationX << endl;
    cout << "Standard Deviation of y (sigma y): " << standardDeviationY << endl;
    cout << "Correlation coefficient r (rho): " << correlationCoefficient << endl << endl;

    bool userNeededEquations = PromptUserYesNo("Do you want a list of economics equations before taking the quiz?");
    if(userNeededEquations){
        cout << "Linear regression: Y = beta 0 + (beta 1 * X)" << endl;
        cout << "Slope: beta 1 = sigma xy / (sigma x)^2" << endl;
        cout << "Intercept: beta 0 = mu y - (beta 1 * mu x)" << endl;
        cout << "Covariance: sigma xy = rho(sigma x * sigma y)" << endl << endl;
    }

    int numTestQuestions = DEFAULT_NUM_TEST_QUESTIONS;
    string questionQuery = "There are " + to_string(numTestQuestions)
            + " questions on the quiz. would you like to change this?";
    bool userDecidesNumQuestions = PromptUserYesNo(questionQuery);
    if(userDecidesNumQuestions){
        cout << "How many questions would you like?: " << endl;
        numTestQuestions = GetAnIntegerGreaterThanOrEqualToAValue(MIN_TEST_QUESTIONS_ALLOWED);
    }
    cout << "There are " << numTestQuestions << " questions on this quiz." << endl << endl;
    int numQuestionsRight = TestQuestions(betaZero, betaOne, numTestQuestions);
    double percentageQuestionsRight = numQuestionsRight / static_cast<double>(numTestQuestions) * 100;

    if(numQuestionsRight == numTestQuestions){
        if(!userNeededEquations) {
            cout << "Congratulations! You got all the problems correct! You are probably ready for the midterm!"
                 << endl;
        }
        else{
            cout << "Good work. Try again without the equations!" << endl;
        }
    }
    else if(numQuestionsRight > 0){
        cout << "You got " << numQuestionsRight << " out of " << numTestQuestions << " questions right,"
        << " or " << percentageQuestionsRight << "%. Keep studying and you will make it." << endl;
        if(userNeededEquations){
            cout << "You will also need to study the equations more." << endl;
        }
    }
    else{
        cout << "Oh no. You got every question wrong. Study economics now or you will fail the midterm..." << endl;
    }
    return 0;
}
void SetValues(double& averageX, double& averageY, double& standardDeviationX,
               double& standardDeviationY, double& correlationCoefficient){
    if(PromptUserYesNo("Do you want values set randomly?")) { //If user wants values set randomly
        SetValueRandomly(averageX);
        SetValueRandomly(averageY);
        SetValueRandomly(standardDeviationX);
        SetValueRandomly(standardDeviationY);
        correlationCoefficient = MIN_CORRELATION_COEFFICIENT + rand() *
                (MAX_CORRELATION_COEFFICIENT - MIN_CORRELATION_COEFFICIENT) / static_cast<double>(RAND_MAX);
    }
    else{ //User wants to manually set values
        cout << "What do you want the average of X to be?: " << endl;
        SetValueToInput(averageX, false, false);
        cout << "What do you want the average of Y to be?: " << endl;
        SetValueToInput(averageY, false, false);
        cout << "What do you want the standard deviation of X to be?: " << endl;
        SetValueToInput(standardDeviationX, true, false);
        cout << "What do you want the standard deviation of Y to be?: " << endl;
        SetValueToInput(standardDeviationY, true, false);
        cout << "What do you want the correlation coefficient r to be?: " << endl;
        SetValueToInput(correlationCoefficient, false, true);
    }

}
int GetAnIntegerGreaterThanOrEqualToAValue(int minValue){
    int output;
    bool isValid = false;
    while(!isValid){
        output = static_cast<int>(GetANumber());
        if(output >= minValue){
            isValid = true;
        }
        else{
            cout << "The number floored to the nearest integer must be greater than or equal to " << minValue <<". Try again." << endl;
        }
    }
    return output;
}
double GetANumber(){
    double input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please input only a number, not a string." << endl;
        cin >> input;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return input;
}
bool PromptUserYesNo(string question){
    cout << question << endl;
    cout << "If so, type \"" << PHRASE_FOR_YES
    << "\" (Case insensitive). Else, type something and press enter: " << endl;
    string input;
    cin >> input;
    input = ReturnTextInLowerCase(input);
    if(PHRASE_FOR_YES.compare(input) == 0){
        return true;
    }
    return false;
}
int TestQuestions(double betaZero, double betaOne, int numQuestions){
    int numCorrect = 0;
    double randomX;
    double randomY;
    double input;
    for(int i = 1; i <= numQuestions; ++i){
        SetValueRandomly(randomX);
        randomY = FindPredictedYValue(randomX, betaZero, betaOne);
        cout << "Question " << i << endl;
        cout << "Suppose you have the following x value: " << randomX << endl;
        cout << "What would you expect the y value to be?: " << endl;
        SetValueToInput(input, false, false);
        if((input - randomY) < ERROR_SENSITIVITY && (randomY - input) < ERROR_SENSITIVITY){
            numCorrect++;
            cout << "That is correct." << endl;
        }
        else{
            cout << "That is incorrect. The correct answer is " << randomY << endl;
        }
    }
    cout << endl;
    return numCorrect;
}
void SetValueToInput(double& valueToSet, bool isStandardDeviation, bool isCorrelationCoefficient){
    bool isValidInput = false;
    double input;
    while(!isValidInput) {
        input = GetANumber();
        isValidInput = true;
        if (isStandardDeviation) {
            if (input <= 0.0) {
                cout << "Standard deviations must be greater than 0. Please give a valid number." << endl;
                isValidInput = false;
            }

        }
        if(isCorrelationCoefficient){
            if(input < -1.0 || input > 1.0){
                cout << "Correlation coefficients must be between the values -1.0 and 1.0, inclusive. Please give a valid number." << endl;
                isValidInput = false;
            }
        }
    }
    valueToSet = input;
}
string ReturnTextInLowerCase(string inputText){
    string output;
    int stringLength = inputText.length();
    for(int i = 0; i < stringLength; i++){
        output += tolower(inputText.at(i));
    }
    return output;
}
void SetValueRandomly(double& valueToBeRandomized){
    valueToBeRandomized = 0;
    while(valueToBeRandomized == 0) {
        valueToBeRandomized = rand() % MAX_RANDOM_VALUE + MIN_RANDOM_VALUE;
    }
}
double FindCovariance(double standardDeviationX, double standardDeviationY, double correlationCoefficient){
    // ρ = σxy / (σx * σy), Therefore --> σxy = ρ(σx * σy)
    return correlationCoefficient * standardDeviationX * standardDeviationY;
}
double FindBetaOne(double covarianceXY, double standardDeviationX) {
    return covarianceXY / (standardDeviationX * standardDeviationX);
    // β1 = σxy / (σx)^2
}
double FindBetaZero(double betaOne, double averageX, double averageY){
    // β0 = μy - (β1 * μx);
    return averageY - (betaOne * averageX);
}
double FindPredictedYValue(double xValue, double betaZero, double betaOne){
    return betaZero + (betaOne * xValue);
    // Y = β + (β1 * X);
}



