#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//place function prototypes here...
double CalcRectanglePerimeter(double height, double width);
void PrintRectanglePerimeter(double height, double width);
void DoubleRectanglePerimeter(double& height, double& width);
double CalcCircumferenceOfCircle(double radius);
double CalcAreaOfCircle(double radius);
double CalcVolumeOfSphere(double radius);
void Swap(int& num1, int& num2);
void Swap(double& num1, double& num2);

const double PI = 3.14;

//main function
int main(){
    cout << "Getting this line to print earns you points!\n";
    double height = 0.0;
    double width = 0.0;
    double radius = 0.0;

    cin >> height >> width >> radius;
    PrintRectanglePerimeter(height, width);
    cout << CalcRectanglePerimeter(height, width) << std::endl;
    cout << "... about to double height and width...\n";
    DoubleRectanglePerimeter(height, width);
    PrintRectanglePerimeter(height, width);

    return 0;
}
double CalcRectanglePerimeter(double height, double width){
    return (height * 2.0) + (width * 2.0);
}
void PrintRectanglePerimeter(double height, double width){
    double rectLength = CalcRectanglePerimeter(height, width);
    cout << fixed << setprecision(1) << "A rectangle with height " << height
         << " and width " << width << " has a perimeter of " << rectLength << "." << endl;
}
void DoubleRectanglePerimeter(double& height, double& width){
    height *= 2;
    width *= 2;
}
double CalcCircumferenceOfCircle(double radius){
    return 2.0 * PI * radius; //Circumference = 2 * pi * r
}
double CalcAreaOfCircle(double radius){
    return PI * radius * radius; //Area = pi * r^2
}
double CalcVolumeOfSphere(double radius){
    return 4.0/3.0 * PI * radius * radius * radius; //Volume = 4/3 * pi * r^3
}
void Swap(int& num1, int& num2){
    int numTemp = num1;
    num1 = num2;
    num2 = numTemp;
}
void Swap(double& num1, double& num2){
    double numTemp = num1;
    num1 = num2;
    num2 = numTemp;
}



