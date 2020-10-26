// Sixto Garcia
// CS151 Project A

#include <iostream>
using namespace std;

//fucntion to find greatest common denominator for the fraction
int GCD(int m, int n)
{
    int r = m % n;
    if (r == 0)
    {
        return n;
    }
    else
    {
        return GCD(n, r);
    }
}

// will add the fractions given by user
void Add(int &n1, int &d1, int &n2, int &d2)
{
    n1 = (n1 * d2) + (n2 * d1); //cross multiplies and adds the numerators
    d1 = d1 * d2;               //multiplies straight across for denominators

    int gcd = GCD(n1, d1); //calls function to get the GCD and stores return value in variable

    n1 = n1 / gcd; //divides by the gcd to get simpliest form.
    d1 = d1 / gcd;

    if (d1 < 0) //checks if denominator is negative
    {
        n1 = n1 * (-1); //switches the signs of numerator and denominator
        d1 = d1 * (-1); //to avoid having a negative int in denominator
    }
}

//will subtract the fractions given by user
void Subtract(int &n1, int &d1, int &n2, int &d2)
{
    n1 = (n1 * d2) - (n2 * d1); //cross multiplies and substracts the numerators
    d1 = d1 * d2;               //multiplies straight across for denominators

    int gcd = GCD(n1, d1); //calls function to get the GCD

    n1 = n1 / gcd; //divides by the gcd to get simpliest form.
    d1 = d1 / gcd;

    if (d1 < 0) //checks if denominator is negative
    {
        n1 = n1 * (-1); //switches the signs of numerator and denominator
        d1 = d1 * (-1); //to avoid having a negative int in denominator
    }
}

//will multiply fractions given by user
void Multiply(int &n1, int &d1, int &n2, int &d2)
{
    n1 = n1 * n2; //multiplies straight across for the numerators
    d1 = d1 * d2; //multiplies straight across for denominators

    if (n1 == 0)
    {
        n1 = 0;
        d1 = 0;
    }

    else
    {
        int gcd = GCD(n1, d1); //calls function to get the GCD

        n1 = n1 / gcd; //divides by the gcd to get simpliest form.
        d1 = d1 / gcd;

        if (d1 < 0) //checks if denominator is negative
        {
            n1 = n1 * (-1); //switches the signs of numerator and denominator
            d1 = d1 * (-1); //to avoid having a negative int in denominator
        }
    }
}

//will divide fractions given by the user
void Divide(int &n1, int &d1, int &n2, int &d2)
{
    n1 = n1 * d2; //multiplies first numerator with second denominator
    d1 = d1 * n2; //multiplies first denominator with second numerator

    if (d1 != 0)
    {
        if (n1 == 0)
        {
            n1 = 0;
            d1 = 0;
        }
        else
        {
            int gcd = GCD(n1, d1); //calls function to get the GCD

            n1 = n1 / gcd; //divides by the gcd to get simpliest form.
            d1 = d1 / gcd;
        }

        if (d1 < 0) //checks if denominator is negative
        {
            n1 = n1 * (-1); //switches the signs of numerator and denominator
            d1 = d1 * (-1); //to avoid having a negative int in denominator
        }
    }
}

//main calculator function
//Recieves input from user for fractions
//displays menu of operations to choose from
//will call corresponding operation fuction based on users input
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
        cout << "\nERROR: Cannot Have Zero in Denominator! \n";
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

        //if user chooses ADD operation
        if (MenuSelection == 1)
        {
            cout << "\nYour equation is: " << '(' << n1 << '/' << d1 << ')' << " + " << '(' << n2 << '/' << d2 << ')';

            Add(n1, d1, n2, d2);

            cout << "\nYour solution is: " << n1 << '/' << d1;
        }

        //if user chooses SUBTRACT operation
        else if (MenuSelection == 2)
        {
            cout << "\nYour equation is: " << '(' << n1 << '/' << d1 << ')' << " - " << '(' << n2 << '/' << d2 << ')';

            Subtract(n1, d1, n2, d2);

            cout << "\nYour solution is: " << n1 << '/' << d1;
        }

        //if user chooses MULTIPLY operation
        else if (MenuSelection == 3)
        {
            cout << "\nYour equation is: " << '(' << n1 << '/' << d1 << ')' << " x " << '(' << n2 << '/' << d2 << ')';

            Multiply(n1, d1, n2, d2);

            cout << "\nYour solution is: " << n1 << '/' << d1;
        }

        //if user chooses DIVIDE operation
        else if (MenuSelection == 4)
        {
            cout << "\nYour equation is: " << '(' << n1 << '/' << d1 << ')' << " / " << '(' << n2 << '/' << d2 << ')';

            Divide(n1, d1, n2, d2);
            if (d1 == 0 && n1 != 0)
            {
                cout << "\nYour solution is: Undefined ::Can't Divide By Zero!::";
            }
            else
            {
                cout << "\nYour solution is: " << n1 << '/' << d1;
            }
        }
        else
        {
            cout << "Invalid Operation"; //will display if  user inputs number other then 1-4 for menu selection
        }
        return;
    }
}

int main()
{
    Calculator();

    return 0;
}