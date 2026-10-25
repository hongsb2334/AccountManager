#pragma once
#include <fstream>

class Account
{
public:
	Account(int newId, const char* newName, int newBalance);

    Account(const Account& other);
	
	virtual ~Account();
	
	virtual void ShowInfo() const;
    


	//출금 성공 여부 함수
	bool WithDraw(int amount);

	//입금 함수
	virtual void Deposit(int amount);

	//Getter
	int GetBalance() const { return balance; }
	int GetId() const { return id; }

    const char* GetName() const
    {
        return name;
    }

    void ChangeName(const char* newName);

    virtual void Save(std::ostream& out) const;
protected:
    void ShowCommonInfo() const;

    void WriteRecord(std::ostream& out, int type, int donation) const;

private:
	//계좌 식별 번호
	int id = 0;
	//이름
	char* name = nullptr;
	//잔액
	int balance = 0;
};


class CreditAccount : public Account
{
public:

    CreditAccount(int id, const char* name, int balance);
    
    
    void Deposit(int amount) override;
    void ShowInfo() const override;

    virtual void Save(std::ostream& out) const override;

};

class DonationAccount : public Account
{
public:
    DonationAccount(int id, const char* name, int balance, int donationTotal = 0);

    void Deposit(int amount) override;
    void ShowInfo() const override;

    virtual void Save(std::ostream& out) const override;

private:
    //기부 총액
    int donationTotal;
};

