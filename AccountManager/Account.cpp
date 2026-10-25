#include "Account.h"
#include <iostream>
#include <cstring>



Account::Account(int newId, const char* newName, int newBalance) 
{
	id = newId;
	
	int size = strlen(newName) + 1;

	name = new char[size];

	//for(int i = 0 ; i < size; ++i)
	//{
	//	name[i] = newName[i];
	//}

	strcpy_s(name, size, newName);

	balance = newBalance;

}

Account::Account(const Account& other)
{
    id = other.id;
    balance = other.balance;

    int length = strlen(other.name) + 1;

    name = new char[length];

    for (int i = 0; i < length; i++)
    {
        name[i] = other.name[i];
    }
}

Account::~Account()
{
	std::cout << name <<" account 소멸 완료\n";
	delete[] name;
	name = nullptr;
	
}

void Account::ShowInfo() const
{
    std::cout << "일반 계좌 - ";
    ShowCommonInfo();
}

void Account::Save(std::ostream& out) const
{
    WriteRecord(out, 1, 0);
    
}

bool Account::WithDraw(int amount)
{
	//잔액이 부족하면 false
	if (balance - amount < 0)
	{
		std::cout << "잔액이 부족합니다. \n";
		return false;
	}

	//잔액이 남아도 true
	balance -= amount;	
	return true;
}

void Account::Deposit(int amount)
{
	balance += amount;
}

void Account::ChangeName(const char* newName)
{   
    
    int length = strlen(newName) + 1;
    //name = new char[length];
    strcpy_s(name, length, newName);
}

void Account::ShowCommonInfo() const
{
    std::cout << "계좌번호: " << id << ", 이름: " << name << ", 잔액: " << balance << "\n";
}

void Account::WriteRecord(std::ostream& out, int type, int donation) const
{
    out << type << " " << id << " " << name << " " << balance << " " << donation << "\n";
}

CreditAccount::CreditAccount(int id, const char* name, int balance) : Account(id, name, balance)
{
}

void CreditAccount::Deposit(int amount)
{
    amount += (amount / 100);

    Account::Deposit(amount);
}

void CreditAccount::ShowInfo() const
{
    std::cout << "일반 계좌 - ";
    ShowCommonInfo();
}

void CreditAccount::Save(std::ostream& out) const 
{
    WriteRecord(out, 2, 0);
}

DonationAccount::DonationAccount(int id, const char* name, int balance, int donationTotal) : Account(id, name, balance), donationTotal(donationTotal)
{
}

void DonationAccount::Deposit(int amount)
{
    //입금액 기부 누적
    donationTotal += (amount / 100);

    //기부금 제외한 입금액 계산
    amount -= (amount / 100);
    
    Account::Deposit(amount);

    std::cout << "기부 총액: " << donationTotal << "\n";
    
}

void DonationAccount::ShowInfo() const
{
    std::cout << "기부 계좌 - ";
    ShowCommonInfo();
    std::cout << "기부 총액: " << donationTotal << "\n";

    std::cout << "다음 입금부터 기부율 1퍼센트 적용\n";

}

void DonationAccount::Save(std::ostream& out) const
{
    WriteRecord(out, 3, donationTotal);
}
