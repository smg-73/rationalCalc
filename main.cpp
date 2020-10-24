#include <iostream>
using namespace std;

//main calculator function
//ask user to input a number for numerator and denominatior for each fraction
void Calculator()
{
    int n1, d1, n2, d2; //initializes variables used for fraction

    //ask user to input number and stores it in respective variable
    cout << "Enter Numerator for first fraction: ";
    cin >> n1;

    cout << "Enter Denominator for first fraction: ";
    cin >> d1;

    cout << "Enter Numerator for second fraction: ";
    cin >> n2;

    cout << "Enter Denominator for second fraction: ";
    cin >> d2;

    //checks if user inputed a 0 for one of the denominators
    //will display error message if true.
    if (d1 == 0 || d2 == 0)
    {
        cout << "\nERROR: Cannot Divide By Zero!\n";
    }

    else
    {
        // displays menu of the operations
        //ask user to make selection from the menu
        cout << "\nType the number for the operation you wish to perform from the menu below:\n\n";

        cout << "1: ADD\n"
             << "2: SUBTRACT\n"
             << "3: MULTIPLY\n"
             << "4: DIVIDE\n\n";

        int MenuSelection;    //initializes variable for users menu selection
        cin >> MenuSelection; //stores users selection in variable
    }

    int main()
    {

        return 0;
    }