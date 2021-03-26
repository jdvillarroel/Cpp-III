#include	"machine.h"

SoftDrinkMachine::SoftDrinkMachine()
{
    // Initialize variables
    for (int i = 0; i < DRINKS_TYPE - 1; i++)
    {
        drinks[i].price = 1.0;
        drinks[i].quantity = 20;
    }

    drinks[0].name = "Cola";
    drinks[1].name = "Root beer";
    drinks[2].name = "Orange soda";
    drinks[3].name = "Grape soda";
    drinks[4].name = "Bottled water";

    drinks[4].price = 1.5;
    drinks[4].quantity = 20;
}

// Destructor function calls daily report.
SoftDrinkMachine::~SoftDrinkMachine()
{
    dailyReport();
}

int SoftDrinkMachine::displayChoices(void)
{
    int     selectedDrink = 0;

    // Display drink options.
    cout << "***** Drink Options *****\n";
    cout << setw(8) << left << "Option"
        << setw(15) << left <<  "Drink"
        << setw(7) << left << "Price" << "\n";

    for (int i = 0; i < DRINKS_TYPE; i++)
    {
        cout << setw(8) << left << (i + 1)
            << setw(15) << left << getDrink(i).name
            << fixed << showpoint << setprecision(2) << "$" << getDrink(i).price << "\n";
    }

    cout << endl;

    // Prompt user to select drink and save user's option.
    cout << "Please, select a drink: ";
    cin >> selectedDrink;
    cin.ignore(100, '\n');
    cout << endl;
    
    // Return index of the drink selected.
    // If no valid option is selected, return -1.
    if (selectedDrink > 0 && selectedDrink <= 5)
        return (selectedDrink - 1);
    else
        return -1;
}

/// <summary>
/// Get drink when sale is validated. 
/// </summary>
/// <param name="index">
/// Gets index of the array to retrieve the drink specified.
/// </param>
/// <returns></returns>
Drink SoftDrinkMachine::getDrink(int index)
{

    return drinks[index];
}

/// <summary>
/// Decrease by one when a drink is siold.
/// </summary>
/// <param name="index">
/// Get index of the array which drink has been sold.
/// </param>
void SoftDrinkMachine::setDrinkQuantity(int index)
{
    drinks[index].quantity -= 1;
}

/// <summary>
/// Holds all the logic for  validating the sell. Verifies the amount of money entered
/// is greater than the cost of the drink and the quantity of the specific drink is
/// non zero.
/// </summary>
/// <param name="drinkSelected">
/// Gets the index of the array which drink was selected.
/// </param>
void SoftDrinkMachine::buyDrink(int drinkSelected)
{
    double      moneyEntered = 0;
    char        confirm;
    bool        isValidated = false;
    Drink      drink;

    // Prompot user to insert payment.
    moneyEntered =  inputMoney(drinkSelected);

    // Entered money validation.
    if (moneyEntered >= drinks[drinkSelected].price)
    {
        cout << "Confirm your selection -> \n"
            << drinks[drinkSelected].name << " at a price of: $" << drinks[drinkSelected].price << " (y/n): ";

        cin >> confirm;
        cin.ignore(100, '\n');
        cout << endl;

        // Confirm user selection after amount entered is valid.
        // If answer is other than yes, return money and go back to the beggining.
        if (confirm == 'Y' || confirm == 'y')
            isValidated = true;
        else
        {
            returnMoney(moneyEntered);
            return;
        }
    }
    else
    {
        // If money entered is not enough, return it and start again.
        if (moneyEntered > 0)
        {
            cout << "Amount entered is not enough for the purchase.\n";
            returnMoney(moneyEntered);
        }
        else
        {
            cout << "Invalid amount.\n";
        }
        return;
    }

    // When money and confirmation is received, validates available quantity to complete sell.
    if (isValidated)
    {
        if (drinks[drinkSelected].quantity > 0)
        {
            // Get the drink and update quantity.
            drink = getDrink(drinkSelected);
            setDrinkQuantity(drinkSelected);

            cout << "***********************************************\n";
            cout << "Here is your beverage -> " << drink.name << endl;

            returnMoney(moneyEntered - drink.price);
            cout << "***********************************************\n\n";
        }
        else
        {
            cout << "Drink sold out.\n";
            returnMoney(moneyEntered);
        }
    }
    else
        return;
}

/// <summary>
/// Prompot user to enter money needed for the selected drink.
/// </summary>
/// <param name="drinkSelected">
/// Index of the array of the drink selected.
/// </param>
/// <returns></returns>
double SoftDrinkMachine::inputMoney(int drinkSelected)
{
    double     moneyEntered = 0;

    cout << "Price of your drink $" << drinks[drinkSelected].price << endl;
    cout << "Please, insert your money: ";
    cin >> moneyEntered;
    cin.ignore(100, '\n');
    cout << endl;

    return moneyEntered;
}

/// <summary>
/// Return money to the customer.
/// </summary>
/// <param name="money">
/// Amount of money to return.
/// </param>
void SoftDrinkMachine::returnMoney(double money)
{
    cout << endl << "Please, colect your money -> $" << money << endl;
}

/// <summary>
/// Print summary of sales of the day. This function is called by the destructor.
/// </summary>
/// <param name=""></param>
void SoftDrinkMachine::dailyReport(void)
{
    double  moneyCollected = 0;

    cout << "***** Daily Report *****\n";
    cout << setw(8) << left << "Option"
        << setw(15) << left << "Drink"
        << setw(5) << left << "Qty"
        << setw(7) << left << "Sold" << "\n";

    for (int i = 0; i < DRINKS_TYPE; i++)
    {
        double amountPerDrinkType = (drinks[i].price) * (20.0 - drinks[i].quantity);

        cout << setw(8) << left << (i + 1)
            << setw(15) << left << getDrink(i).name
            << setw(5) << left << drinks[i].quantity
            << fixed << showpoint << setprecision(2) << "$" << amountPerDrinkType << "\n";

        moneyCollected += amountPerDrinkType;
    }

    cout << setw(28) << right << "Total " << fixed << showpoint << setprecision(2) <<  "$" << moneyCollected << endl;

    cout << endl;
}