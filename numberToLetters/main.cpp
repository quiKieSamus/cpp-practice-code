#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

string charToString(char character)
{
    switch (character)
    {
    case '0':
        return "0";
    case '1':
        return "1";
    case '2':
        return "2";
    case '3':
        return "3";
    case '4':
        return "4";
    case '5':
        return "5";
    case '6':
        return "6";
    case '7':
        return "7";
    case '8':
        return "8";
    case '9':
        return "9";

    default:
        break;
    }
}

string convertToUnits(string singleNumber, int position, string wholeNumber)
{

    string unit = singleNumber;
    int length = wholeNumber.length();

    for (int i = position; i < length - 1; i++)
    {
        unit += "0";
    }
    return unit;
}

string convertUnitsToText(string unit)
{
    string mostSignificantNumberTextual;
    switch (unit[0])
    {
    case '0':
        mostSignificantNumberTextual = "cero";
        break;
    case '1':
        mostSignificantNumberTextual = "uno";
        break;
    case '2':
        mostSignificantNumberTextual = "dos";
        break;
    case '3':
        mostSignificantNumberTextual = "tres";
        break;
    case '4':
        mostSignificantNumberTextual = "cuatro";
        break;
    case '5':
        mostSignificantNumberTextual = "cinco";
        break;
    case '6':
        mostSignificantNumberTextual = "seis";
        break;
    case '7':
        mostSignificantNumberTextual = "siete";
        break;
    case '8':
        mostSignificantNumberTextual = "ocho";
        break;
    case '9':
        mostSignificantNumberTextual = "nueve";
        break;

    default:
        break;
    }

    int amountOfNumbersAfterSignificant = unit.length() - 1;
    string textualUnit = mostSignificantNumberTextual;

    switch (amountOfNumbersAfterSignificant)
    {
    case 0:
        return textualUnit;
    case 1:
        textualUnit += " decenas con ";
        break;
    case 2:
        textualUnit += "cientos ";
        break;
    case 3: 
        textualUnit += " miles ";
        break;
    case 4:
        textualUnit += " decenas de miles con ";
        break;

    case 5:
        textualUnit += " centenas de miles con ";
        break;
    case 6:
        textualUnit += " millones ";
    default:
        break;
    }
    return textualUnit;
}

string convertNumberToText(string numericNumber)
{

    string number = numericNumber;
    for (int i = 0; i < number.length(); i++)
    {

        string singleNumber = charToString(number[i]);
        cout << convertUnitsToText(convertToUnits(singleNumber, i, number));
    }

    return "";
}
int main()
{
    int input;
    cout << "Introduzca numero a convertir (0-9999999): " << endl;
    cin >> input;
    cout << endl;
    cout << convertNumberToText(to_string(input));
}