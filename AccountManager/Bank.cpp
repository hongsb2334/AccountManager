#include "Bank.h"
#include "Account.h"
#include <iostream>
#include <iomanip>
#include <fstream>

Bank::Bank() : count(0), accounts{}
{
}

Bank::~Bank()
{
	for (int i = 0; i <= count - 1; i++)
	{
		delete accounts[i];
	}
	
}

void Bank::CreateAccount()
{
    while (true)
    {
        std::cout << "========== 계좌 생성 ==========\n";
        if (count >= 100)
        {
            std::cout << "용량 초과입니다\n";
            return;
        }

        char index = {};
        int newId = 0;
        char name[50];
        int newBalance = 0;


        std::cout << "생성할 계좌를 입력해주세요 : 1. 일반 계좌   2. 신용 계좌   3. 기부 계좌 \n";
        std::cin >> index;

        if ((index != '1') && (index != '2') && (index != '3'))
        {
            std::cout << "잘못된 입력입니다. 다시 입력해주세요.\n";
            continue;
        }

        std::cout << "id 입력: ";
        std::cin >> newId;

        std::cout << " 이름 입력: ";
        std::cin >> std::setw(50) >> name;

        std::cout << " 잔액 입력: ";
        std::cin >> newBalance;


        switch (index)
        {
        case '1':
            accounts[count++] = new Account(newId, name, newBalance);
            Save("accounts.txt");
            return;
        case '2':
            accounts[count++] = new CreditAccount(newId, name, newBalance);
            Save("accounts.txt");
            return;
        case '3':
            accounts[count++] = new DonationAccount(newId, name, newBalance);
            Save("accounts.txt");
            return;
        default:
            return;
        }
    }
	
}

void Bank::Inquire() const
{
    //Load("accounts.txt");

	std::cout << "========== 계좌 정보 ==========\n";


	if (count == 0)
	{
		std::cout << "등록된 계좌가 없습니다 \n";
	}

	for (int i = 0; i <= count - 1; ++i)
	{
		accounts[i]->ShowInfo();
	}



	//FindAccount 확인 코드
	//Account* account = FindAccount(9999);
	//
	//std::cout << "567 잔액" << account->GetBalance();

	//Account* account = new Account(100, "seongbum", 10000);

	//account->WithDraw(8000);

	//std::cout << "출금 후 계좌 잔액 : " << account->GetBalance();


}

void Bank::Sum() const
{
	std::cout << "========== 계좌 잔액 합계 ==========\n";

	//계좌 없으면 함수 종료
	if (count == 0)
	{
		return;
	}

	long long sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += accounts[i]->GetBalance();
	}

	std::cout << "계좌 잔액 합계 : " << sum << "\n";

}

void Bank::Deposit()
{
	std::cout << "========== 입금 ==========\n";

	int findingId = 0;
	int amount = 0;

	std::cout << "입금할 계좌번호 입력: ";
	std::cin >> findingId;

	std::cout << "입금액 입력: ";
	std::cin >> amount;

	Account* account = FindAccount(findingId);

	if (!account)
	{
		std::cout << "계좌를 찾지 못했거나 은행에 계좌가 없습니다.\n";
		return;
	}

	account->Deposit(amount);

	std::cout << account->GetId() <<  " 변경된 계좌 잔액: " << account->GetBalance() << "\n";


	
}

void Bank::Run()
{

	while (true)
	{
		std::cout << "============" << "은행" << "============\n";

		std::cout << "1. 계좌 정보 출력\n";
		std::cout << "2. 계좌 생성\n";
		std::cout << "3. 계좌 잔액 합계\n";
		std::cout << "4. 입금\n";
		std::cout << "5. 출금\n";
		

		char input;

		std::cout << "메뉴 입력(숫자) : ";
		std::cin >> input;

        if (input == 'q' || input == 'Q')
        {
            Save("accounts.txt");
            return;
        }

        

		switch (input)
		{
		case '1':
			Inquire();
			break;
		case '2':
			CreateAccount();
			break;
		case '3':
			Sum();
			break;
		case '4':
			Deposit();
			break;
		case '5':
			WithDraw();
			break;
		default:
            std::cout << "잘못된 입력입니다. 다시 입력해주세요 .\n";
			break;
		}

	}
	
}

bool Bank::Save(const char* path) const
{
    std::ofstream file(path);
    
    //file.open(path);

    if (!file.is_open())
    {
        return false;
    }

    file << count << "\n";
    
    for (int i = 0; i < count; i++)
    {
        accounts[i]->Save(file);
    }

    //file.close();

}

bool Bank::Load(const char* path)
{
    std::ifstream file(path);
    file.open(path);

    if (file.is_open())
    {
        return false;
    }

    /* int id, const char* name, int balance, int donationTotal = 0 */
    int type = 0, totalAccount = 0, id = 0, balance = 0, donationtotal = 0;
    char name[50] = {};

    while (file)
    {
        file >> totalAccount >> type >> id >> name >> balance >> donationtotal;

        switch (type)
        {
        case 1:
            accounts[count++] = new Account(id, name, balance);
            return true;
        case 2:
            accounts[count++] = new CreditAccount(id, name, balance);
            return true;
        case 3:
            accounts[count++] = new DonationAccount(id, name, balance, donationtotal);
            return true;
        default:
            return false;
        }
    }

    return false;
}

void Bank::WithDraw()
{
	std::cout << "========== 출금 ==========\n";

	int input;
	std::cout << "출금할 계좌번호 입력: ";
	std::cin >> input;

	int amount;
	std::cout << "출금할 금액 입력: ";
	std::cin >> amount;

	if (Account* account = FindAccount(input))
	{
		account->WithDraw(amount);
	}

}

void Bank::SaveTest()
{
    accounts[count++] = new Account(102, "seongbum", 20000);
    accounts[count++] = new Account(200, "hyeongsin", 10000);
    accounts[count++] = new Account(300, "inzik", 100000);
    Save("accounts.txt");

}

void Bank::LoadTest()
{
    Load("accounts.txt");
}


Account* Bank::FindAccount(int targetId) const
{
	//계좌가 하나도 없으면 nullptr 리턴
	if (count == 0)
	{
		return nullptr;
	}

	for (int i = 0; i < count; i++)
	{
		//계좌번호 조회해서 맞으면 계좌 주소 반환
		if (accounts[i]->GetId() == targetId)
		{
			return accounts[i];
		}
	}
	return nullptr;
}
