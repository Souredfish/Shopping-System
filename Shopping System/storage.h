#pragma once
#include<iostream>
#include<fstream>
class BTree;
class Message;
class password;
class storage {
public:
	void save();
	int load();
	void getbtree(BTree* p)
	{
		tree = p;
	}
	void getMessage(Message* m) {
		mes = m;
	}
	void getPassword(password* p)
	{
		pass = p;
	}
private:
	int id;
	std::string name;
	int sum;
	float cost;
	float profit;
	float total;
	bool ifseason;

	std::string tempseason;
	std::string lab;//��ǩ
	std::string c_maufacter;//����
	int c_date_year;//�������
	int c_date_year_in;//�������
	int c_date_m;//�����·�
	int c_date_m_in;//��������
	int c_sum;//������Ʒ������
	std::string username;
	BTree *tree;
	Message *mes;
	int nowmon;
	int nowyear;
	password *pass;
	std::string tempnowseason;
};