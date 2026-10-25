#include <iostream>
#include <cstring>
#include "Account.h"
#include "Bank.h"



int main()
{
	Bank bank;
    //bank.SaveTest();
    if (!bank.Load("accounts.txt"))
    {
        std::cout << "은행에 계좌가 없거나 불러오기에 실패했습니다.\n";
    }
    bank.Run();
    


    //bank.SaveTest();
   
    

	//Account account(1000, "seongbum", 8000);
	//account.WithDraw(8000);
	//std::cout << "출금 후 잔액: " << account.GetBalance() << "\n";
	//


	////bank.Inquire();
	//bank.CreateAccount();
	//bank.CreateAccount();
	////bank.Deposit();

	//bank.Inquire();
	////bank.Sum();

    //Account original(1001, "kim", 10000);
    //Account copy(original);
    //original.ShowInfo();
    //copy.ShowInfo();


    //std::cout << (&original != &copy) << "\n";
    //std::cout << (original.GetName() != copy.GetName()) << "\n";
    //std::cout << (strcmp(original.GetName(), copy.GetName()) == 0) << "\n";

    //CreditAccount credit(1001, "Kim", 10000);
    //Account* account = &credit;
    //account->Deposit(10000);
    //account->ShowInfo();

    //DonationAccount donation(2000, "hong", 10000);
    //Account* account2 = &donation;

    //account2->Deposit(10000);
    //account2->ShowInfo();

    //account2->Deposit(5000);
    //account2->ShowInfo();

    //account2->WithDraw(1000);
    //account2->ShowInfo();

    


}