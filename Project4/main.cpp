#include <iostream>
#include <string>
using namespace std;

class NashSquare{
    private:
        const int SQUARE_X_SIZE = 2;
        const int SQUARE_Y_SIZE = 2;
        const int NUM_TEAMS = 2;
        const int ARRAY_SIZE = SQUARE_X_SIZE * SQUARE_Y_SIZE * NUM_TEAMS;

        int square[];
        int ConvertInputToIndex(bool team1ChooseA, bool team2ChooseA, bool getTeam1);
        string GetOneBox(bool team1ChooseA, bool team2ChooseA);
    public:
        NashSquare();
        void PrintNashSquare();
        int GetValueFromSquare(bool team1ChooseA, bool team2ChooseA, bool getTeam1);
};
NashSquare::NashSquare(){
    square[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++){ //for debug.
        square[i] = i;
    }

}
int NashSquare::ConvertInputToIndex(bool team1ChooseA, bool team2ChooseA, bool getTeam1){
    int output = 0;
    if(team1ChooseA){
        output += ARRAY_SIZE / NUM_TEAMS / SQUARE_Y_SIZE / SQUARE_X_SIZE;
    }
    if(team2ChooseA){
        output += ARRAY_SIZE / NUM_TEAMS / SQUARE_Y_SIZE;
    }
    if(getTeam1){
        output += ARRAY_SIZE / NUM_TEAMS;
    }
    return output;
}
int NashSquare::GetValueFromSquare(bool team1ChooseA, bool team2ChooseA, bool getTeam1){
    return square[ConvertInputToIndex(team1ChooseA, team2ChooseA, getTeam1)];
}
string NashSquare::GetOneBox(bool team1ChooseA, bool team2ChooseA){
     string output =  (square[GetValueFromSquare(team1ChooseA, team2ChooseA, true)] + "");
     return "\\"; //DEBUG
     /*output += "/";
     output += (square[GetValueFromSquare(team1ChooseA, team2ChooseA, false)] + "");
     return output;*/
}
 void NashSquare::PrintNashSquare(){
    cout << " Team 1 (Upper)/Team 2 (Left)" << endl;
    cout << "  A     B" << endl;
    cout << " 123456789"<< endl;
    cout << "9876543";
    /*cout << "A|" << GetOneBox(true, true)
        << "   " << GetOneBox(false, true) << endl;
    cout << "B|" << GetOneBox(true, false) <<
        "   " << GetOneBox(false, false) << endl;
        */
    /*
    cout << "  Team 1  " << endl;
    cout << "T    A   B" << endl;
    cout << "e  A      " << endl;
    cout << "a         " << endl;
    cout << "m  B      " << endl;
    cout << "2         " << endl;
     */
}



int penaltyAmount = 0;
int playerOneScore = 0;
int playerTwoScore = 0;

int MaximizeScoreStrategy();
int MinimizeOpponentScoreStrategy();
int TitForTatStrategy();

int main() {
    cout << "Hello, World!" << endl;
    NashSquare* n = new NashSquare();
    n->PrintNashSquare();
    return 0;
}


