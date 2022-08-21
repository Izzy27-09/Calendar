//simulates a basic calendar
#include <iostream>
#include "Dates.h"

int main()
{
    Date cal;
    int choice;
    std::cout << "1.Set Date\n";
    std::cout << "2.Display Date(mm/dd/yyyy)\n";
    std::cout<<"3 Display Date(Weekday,Month, day,Year\n";
    std::cin >> choice;
    std::cout << "\n";
    switch (choice) {
    case 1:
        cal.SetYear();
        cal.SetMonth();
        cal.SetDay();
        break;
    case 2:
        std::cout << cal.GetMonth(); std::cout << "/"; std::cout << cal.GetDay(); std::cout << "/"; std::cout << cal.GetYear();
        break;
    case 3:
        cal.ExactDate();
        break;
        
    }
}


