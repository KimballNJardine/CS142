#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int PLATE_LENGTH = 10;
const int PRECISION = 3;
const int NUM_WIDTH = 9;
const double STARTING_TEMP = 100;

void PrintHotPlate(double hotPlate[][PLATE_LENGTH]);
bool UpdateElements(double hotPlate[][PLATE_LENGTH]);
void InitializeHotPlateWithFile(double hotPlate[][PLATE_LENGTH], string fileName);

int main()
{

    double hotPlate[PLATE_LENGTH][PLATE_LENGTH];
    for(int i = 0; i < PLATE_LENGTH; i++)
    {
        for(int j = 0; j < PLATE_LENGTH; j++)
        {
            hotPlate[i][j] = 0.0;
        }
    }
    for(int i = 1; i < PLATE_LENGTH-1; i++)
    {
        hotPlate[0][i] = STARTING_TEMP;
        hotPlate[PLATE_LENGTH-1][i] = STARTING_TEMP;
    }

    cout << "Hotplate simulator" << endl << endl;
    cout << "Printing the initial plate values..." << endl;
    PrintHotPlate(hotPlate);
    cout << endl;
    cout << "Printing plate after one iteration..." << endl;
    UpdateElements(hotPlate);
    PrintHotPlate(hotPlate);

    bool isChanging = true;
    while(isChanging){
        isChanging = UpdateElements(hotPlate);
    }
    cout << endl;
    cout << "Printing final plate..." << endl;
    PrintHotPlate(hotPlate);
    cout << endl;
    cout << "Writing final plate to \"Hotplate.csv\"..." << endl;

    ofstream outputFile;
    outputFile.open("Hotplate.csv");
    for(int i = 0; i < PLATE_LENGTH; i++)
    {
        int j = 0;
        for(j = 0; j < PLATE_LENGTH - 1; j++)
        {
            outputFile  << setw(NUM_WIDTH) << fixed << setprecision(PRECISION) << hotPlate[i][j] << ",";
        }
        outputFile << setw(NUM_WIDTH) << hotPlate[i][j];
        outputFile << endl;
   }
    outputFile.close();
    string fileName = "C:/Users/Kimball/CLionProjects/CS142/Project6/cmake-build-debug/Inputplate.txt";
    InitializeHotPlateWithFile(hotPlate, fileName);
    for(int i = 0; i < 3; i++)
    {
        UpdateElements(hotPlate);
    }
    cout << endl << "Printing input plate after 3 updates..." << endl;
    PrintHotPlate(hotPlate);

    return 0;

}
bool UpdateElements(double hotPlate[][PLATE_LENGTH])
{
    bool changed = false;
    double newHotPlate[PLATE_LENGTH][PLATE_LENGTH];
    for (int i = 1; i < PLATE_LENGTH - 1; i++)
    {
        for (int j = 1; j < PLATE_LENGTH - 1; j++)
        {
            double newVal = 0;
            newVal += hotPlate[i-1][j];
            newVal += hotPlate[i][j-1];
            newVal += hotPlate[i][j+1];
            newVal += hotPlate[i+1][j];
            newVal = newVal / 4;
            newHotPlate[i][j] = newVal;
        }
    }
    for(int i = 1; i < PLATE_LENGTH - 1; i++)
    {
        for(int j = 1; j < PLATE_LENGTH - 1; j++)
        {
            if(abs(newHotPlate[i][j] - hotPlate[i][j])>= 0.1)
            {
                changed = true;
            }
            hotPlate[i][j] = newHotPlate[i][j];
        }
    }

    return changed;
}

void InitializeHotPlateWithFile(double hotPlate[][PLATE_LENGTH], string fileName){
    string plate;
    ifstream inputPlate;
    inputPlate.open(fileName);

    if(!inputPlate.is_open())
    {
        cout << "Could not open file, error." << endl;
        return;
    }
    for (int i = 0; i < PLATE_LENGTH; i++)
    {
        getline(inputPlate, plate);
        for (int j = 0; j < PLATE_LENGTH; j++)
        {
            int index = plate.find("\t");
            string thisNum = plate.substr(0, index);
            plate = plate.substr(index + 1);
            double thisVal = stod(thisNum);
            hotPlate[i][j] = thisVal;
        }

    }
}

void PrintHotPlate(double hotPlate[][PLATE_LENGTH])
{
    for(int i = 0; i < PLATE_LENGTH; i++)
    {
        for(int j = 0; j < PLATE_LENGTH - 1; j++)
        {
            cout << setw(NUM_WIDTH) << fixed << setprecision(PRECISION) << hotPlate[i][j] << ",";
        }
        cout << setw(NUM_WIDTH) << hotPlate[i][PLATE_LENGTH - 1];
        cout << endl;

    }
}
