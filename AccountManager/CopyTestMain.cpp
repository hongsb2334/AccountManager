#include <iostream>
#include <cstring>
#include "Account.h"
#include "Bank.h"

int main()
{
    Account* savedCopy = nullptr;
    
    {
        Account original(1001, "kim", 10000);
        savedCopy = new Account(original);
    }

    //original.ShowInfo();
    savedCopy->ShowInfo();


    //Account copy(original);
    
    //std::cout << (&original != &copy) << "\n";
    //std::cout << (original.GetName() != copy.GetName()) << "\n";
    //std::cout << (strcmp(original.GetName(), copy.GetName()) == 0) << "\n";

    //original.Deposit(3000);
    //original.ChangeName("Lee");
    //original.ShowInfo();
    //copy.ShowInfo();


    //

}




