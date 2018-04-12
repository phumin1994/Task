#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int lowestAmountOfProfit;
    char filename[]="scratcher.txt";
    string gameName;
    int CostOfTicket, NumberOfPrizes;
    int PrizeValue, NumberOfTickets, TicketsNotClaimed;
    double RemainingTickets;
    double RemainingTicketsForProfit;
    double odds;

cout << "Enter the lowest dollar amount that you would like to profit: "
cin >> lowestAmountOfProfit;
cout << "Enter the output file name: "
cout << "Generating report..."

ifstream fin;
fin.open(filename);

if (!fin)
{
    cout << "Input file does not exist." << endl;
    return 0;
}

cout << left << setw(25) << "Game" << setw(10) << "Cost" << setw (10) << "Odds" << endl;
cout << "-----------------------------------------------" << endl;

while (getline(fin, gameName))
{
    fin >> CostOfTicket; 
    fin >> NumberOfPrizes;  
    RemainingTickets = 0;
    RemainingTicketsForProfit = 0;
    for (int i = 0; i < NumberOfPrizes; i++)
    {
        fin >> PrizeValue; 
        fin >> NumberOfTickets; 
        fin >> TicketsNotClaimed;   

        RemainingTicketsForProfit = RemainingTicketsForProfit + TicketsNotClaimed;

        if (PrizeValue > lowestAmountOfProfit)
        {
            RemainingTickets = RemainingTickets + TicketsNotClaimed;
        }

    }

    if (RemainingTickets==0)
    {
        cout << left << setw(25) << gameName << setw (2) << "$" << CostOfTicket << right << setw(15) << "Not possible"  << endl;
    }
    else
    {
        odds = RemainingTicketsForProfit / RemainingTickets;
        cout << left << setw(25) << gameName << setw (2) << "$" << CostOfTicket << right << setw(15) << "1 in " << setprecision(2) << fixed << odds << endl;
    }

    string blankLine;
    fin >> blankLine;
}

fin.close();
return 0;
}