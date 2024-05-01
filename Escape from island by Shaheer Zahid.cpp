#include <iostream>
#include <ctime>
#include <string.h>
#include <cstdlib>

using namespace std;
  
string LastDayWeather = "Calm Day"; 
string weather;
string credential[2] = {"Shaheer Zahid"}; //arrays telling credits           
int daysCount = 10;               
int tripCount = 0;                         
int amount = 0;                       
int boatCount = 1;                
int potCount = 10;               

void dayTasks();
//function for buying boats and pots
void buyPots(int q) 
{
    int bill;
    bill = q * 5; //q ia the quantity and 5 is te amount of one pot
    if (bill <= amount)     
    {
        amount = amount - (bill);//subtraction from amount
        potCount = potCount + q;
    }
    else if (bill > amount) 
    {
        string opt;//for storing answer in yes or no
        int max = amount / 5; //total amount/amount of one pot
        cout << "You can purchase maximum " << max << " pots with your existing amount"<<endl;
        cout << "Do you want to purchase that quantity(y/n): ";
        getchar();
        cin >> opt;
        if (opt == "y")
            buyPots(max); 
    }
    system("cls");
}

void buyBoats(int q) 
{
    int bill;
    bill = q * 100; //boat costs 100$
    if (bill <= amount)      
    {
        amount = amount - bill;
        boatCount = boatCount + q;
    }
    else if (bill > amount) 
    {
        string opt;
        int max = amount / 100; 
        cout << "You can purchase maximum " << max << " boats with your existing amount"<<endl;
        cout << "Do you want to purchase that quantity(y/n): ";
        getchar();
        cin >> opt;
        if (opt == "y")
            buyBoats(max); 
    }
    system("cls");
}
//functions for selling pots and boats
void sellPots(int q) 
{
    int bill;
    if (q <= potCount) 
    {
        bill = q * 4;//one pot is sold for 4$
        amount = amount + bill;
        potCount = potCount - q;//subtraction from total pots
    }
    else if (q > potCount)
    {
        string opt;
        cout << "You can sell maximum " << potCount << " pots"<<endl;
        cout << "Do you want to sell that quantity(y/n): ";
        getchar();
        cin >> opt;
        if (opt == "y")
            sellPots(potCount);//function calling for selling pots
    }
}

void sellBoats(int q) 
{
    if (q <= boatCount) 
    {
        amount = amount + (q * 80);
        boatCount = boatCount - q;
    }
    else if (q > boatCount)
    {
        string opt;
        cout << "You can sell maximum " << boatCount << " boats"<<endl;
        cout << "Do you want to sell that quantity(y/n): ";
        getchar();
        cin >> opt;
        if (opt == "y")
            sellBoats(boatCount);//function calling for selling boats
    }
}
//function for trip option
void tripCountFunc() 
{
    int option;
    cout << "Escape From Island  by  Shaheer Zahid and Muneeb Farooq"<<endl
	     << "Total Cash: $" << amount << "\nTotal Pots: " << potCount << "\nTotal Boats: " << boatCount
         << "\nTotal Days:" << daysCount << " "
         << "\tSeason:Autumn"
         << "\tWeather:" << weather << endl;
    cout << "Select Location: " << endl;
    cout << "\t1) Harbor Water" << endl;
    cout << "\t2) Open Sea Water" << endl;
    
    cin >> option;
    
    if (option == 1) 
    {
        
        if (weather == "Calm Day")
        {
            if (potCount / boatCount <= 20) //bcz one boat can take only 20 pots with it in a trip
            {
                amount = amount + potCount * 2; 
            }
            else if (potCount / boatCount > 20) //total pots we have / total boats we have
            {
                amount = amount + (boatCount * 2 * 20); 
            }
        }
        
        else if (weather == "Storm Day")
        {
            if (potCount / boatCount <= 20) 
            {
                amount = amount + 4 * potCount; 
            }
            else if (potCount / boatCount > 20) 
            {
                amount = amount + 4 * boatCount * 20; 
            }
        }
    }
    else if (option == 2)
    {
        
        if (weather == "Calm Day")
        {
            if (potCount / boatCount <= 20) 
            {
                amount = amount + 8 * potCount; //on calm day in open sea we earn 8$ per lobster
            }
            else if (potCount / boatCount > 20) 
            {
                amount = amount + 8 * boatCount * 20; 
            }
        }
        
        else if (weather == "Storm Day")
        {
            if (potCount / boatCount <= 20) 
            {
                amount = amount + 0 * potCount; 
            }
            else if (potCount / boatCount > 20) 
            {
                amount = amount + 0 * boatCount * 20; 
            }
            potCount--;//one pot is reduced in a stormy day in open sea
        }
    }
    else//if option is other than 1 or 2
    {
        cout << "Select Appropiate Option "<<endl;
        system("pause");
        system("cls");
        tripCountFunc();
    }
}
//buy function prototype
void buyFunc() 
{
    int option;
    
    cout << "Escape From Island  by  Shaheer Zahid"<<endl
	     << "Total Cash: $" << amount << "\nTotal Pots: " << potCount << "\nTotal Boats: " << boatCount
         << "\nTotal Days:" << daysCount << " "
         << "\tSeason:Autumn"
         << "\tWeather:" << weather << endl;
    cout << "What You Want To Buy: " << endl;
    cout << "\t1) Pots" << endl;
    cout << "\t2) Boats" << endl;
    
    cin >> option;
    if (option == 1)
    {
        int q; 
        cout << "How many Pots you want to buy: ";
        cin >> q;//input from user the quantity of pots for buying
        buyPots(q); 
    }
    else if (option == 2)
    {
        int q; 
        cout << "How many Boats you want to buy: ";
        cin >> q;
        buyBoats(q); //function calling
    }
    else
    {
        cout << "Select Appropiate Option "<<endl;
        system("pause");
        system("cls");
        buyFunc();
    }
    dayTasks();//homepage function's calling
}

void sellFunc() 
{
    
    int option;
    
    cout << "Escape From Island  by  Shaheer Zahid"<<endl
	     << "Total Cash: $" << amount << "\nTotal Pots: " << potCount << "\nTotal Boats: " << boatCount
         << "\nTotal Days:" << daysCount << " "
         << "\tSeason:Autumn"
         << "\tWeather:" << weather << endl;
    cout << "Select Item to Sell: " << endl;
    cout << "\t1) Sell Pots" << endl;
    cout << "\t2) Sell Boats" << endl;
    cout << "\t3) Sell Every Thing" << endl;
    
    cin >> option;
    if (option == 1) 
    {
        int q;
        cout << "How many Pots you want to sell: ";
        cin >> q;
        sellPots(q);
    }
    else if (option == 2) 
    {
        int q;
        cout << "How many Boats you want to sell: ";
        cin >> q;
        sellBoats(q);
    }
    else if (option == 3)
    {
        //sell everything
        sellBoats(boatCount);
        sellPots(potCount);
    }
    else
    {
        cout << "Select Appropiate Option "<<endl;
        system("pause");
        system("cls");
        sellFunc();
    }
    dayTasks();
}
//function of a homepage of game
void dayTasks() 
{
    int option1;
    
    cout << "Escape From Island  by  Shaheer Zahid"<<endl
	     << "Total Cash: $" << amount << "\nTotal Pots: " << potCount << "\nTotal Boats: " << boatCount
         << "\nTotal Days:" << daysCount << " "
         << "\tSeason:Autumn"
         << "\tWeather:" << weather << endl;
    cout << "\nSelect A Task: " << endl;
    cout << "\t1) Trip Option" << endl;
    cout << "\t2) Buy Option" << endl;
    cout << "\t3) Sell Option" << endl;
    cout << "\t4) Go For Next Day" << endl;
    
    cin >> option1;
    if (option1 == 1) 
    {
        if (tripCount == 0 && boatCount >= 1)
        {
            system("cls");
            tripCountFunc();
            tripCount++;//increment in trip
            system("cls");
            dayTasks();
        }
        else//if 2nd trip is entered
        {
            cout << "You Cant Do Second Trip"<<endl;
            system("pause");
            system("cls");
            dayTasks();
        }
    }
    else if (option1 == 2) 
    {
        if (amount > 0)
        {   buyFunc();//function calling
        }
        else
        {
            cout << "Not Enough Money"<<endl;
            system("pause");
            system("cls");
            dayTasks();
        }
    }
    else if (option1 == 3) 
    {
        if ((potCount > 0 || boatCount > 0) && daysCount == 1)//we can sell anything we want only on last day
        {
            system("cls");
            sellFunc();
        }
        else if (daysCount != 1)
        {
            cout << "Sell Only on Last Day!!"<<endl;
            system("pause");
            system("cls");
            dayTasks();
        }
        else
        {
            cout << "You have nothing to sell!!"<<endl;
            system("pause");
            system("cls");
            dayTasks();
        }
    }
    else if (option1 == 4) 
    {
        cout << "\nDay Finish"<<endl;
        system("pause");
    }
    else
    {
        cout << "Select Appropiate Option "<<endl;
        system("pause");
        system("cls");
        dayTasks();
    }
}
void DiceOpt() //function for rolling dice
{
    int i;
    srand((unsigned)time(NULL)); 
    i = (rand() % 6) + 1;//number will be btw 1 to 6
    switch (i) 
    {
    case 1:
    case 2:
    case 3:
        weather = "Calm Day";       
        LastDayWeather = weather; 
        break;
    case 4:
        weather = LastDayWeather; 
        LastDayWeather = weather; 
        break;
    case 5:
    case 6:
        weather = "Storm Day";      
        LastDayWeather = weather; 
        break;
    }
}	
int main()//main function starts here
{
    
    int optionGame;
    system("cls");
    cout << "Escape From Island  by  Shaheer Zahid"<<endl;
    cout << "Choose Option:" << endl;
    cout << "\t1) Play." << endl;
    cout << "\t2) Credits " << endl;
    cin >> optionGame;
    switch(optionGame){
        case 2:
        system("cls");
        cout << "Game is Developed By"<<endl;
        cout << credential[0]<<endl;//Shaheer Zahid
        cout << credential[1]<<endl;//Muneeb Farooq
        system("pause");
        system("cls");
        case 1:{
            while (daysCount != 0)
            {
                system("cls");
                DiceOpt();//function calling of rolling dice
                tripCount = 0;
				dayTasks();
                daysCount--;//decrement in days remaining
            }
            
            string opt;
            system("cls");
            cout << "Escape From Island  by  Shaheer Zahid"<<endl
	     << "Total Cash: $" << amount << "\nTotal Pots: " << potCount << "\nTotal Boats: " << boatCount
         << "\nTotal Days:" << daysCount << " "
         << "\tSeason:Autumn"
         << "\tWeather:" << weather << endl;
            cout << "Its Final Day. You have $" << amount << " total amount."<<endl;
            cout << "Buy a ticket(y/n)? ";
            cin >> opt;
            system("cls");
            if ((opt == "y" || opt == "Y") && amount >= 1000)
            {
                amount = amount - 1000;
                cout << "\n\nCongratulations Mission Completed\n"<<endl;
            }
            else
                cout << "\n\nMission Failed Try Again\n"<<endl;
            system("pause");
        }
        break;
    }
    return 0;

}//main function ends here



