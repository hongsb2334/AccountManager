#pragma once
#include "Account.h"

class Bank
{
public:
	Bank();

	~Bank();

	void CreateAccount();

	void Inquire() const;

	void Sum() const;

	void Deposit();

	void Run();

    bool Save(const char* path) const;

    bool Load(const char* path);

	//출금 성공 여부 함수
	void WithDraw();

    

    //저장 테스트 함수
    void SaveTest();

    //로드 테스트 함수
    void LoadTest();

private:
	//계좌 탐색
	Account* FindAccount(int targetId) const;


	int count;

	Account* accounts[100];

	
};

