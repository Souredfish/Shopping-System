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
	std::string lab;//标签
	std::string c_maufacter;//厂商
	int c_date_year;//过期年份
	int c_date_year_in;//进货年份
	int c_date_m;//过期月份
	int c_date_m_in;//进货日期
	int c_sum;//该批商品的数量
	std::string username;
	BTree *tree;
	Message *mes;
	int nowmon;
	int nowyear;
	password *pass;
	std::string tempnowseason;
};