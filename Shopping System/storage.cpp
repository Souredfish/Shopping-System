
#include"Warhouse.h"
#include"Message.h"
#include"storage.h"
#include"password.h"

Type_Season nowsea;
Type_Season season;
Type_Season seas;
void storage::save() {
	
	std::ofstream out(username + ".txt", std::ios::out);
	mes->msg_gettime(nowmon, nowyear, &nowsea);
	out << nowmon << "\t" << nowyear << "\t";
	switch (nowsea) {
	case Type_Season::Spr:
		out << "Spring";
		break;
	case Type_Season::Sum:
		out << "Summer";
		break;
	case Type_Season::Aut:
		out << "Autumn";
		break;
	case Type_Season::Win:
		out << "Winter";
		break;
	}
	out << std::endl;
	tree->Wh_list(1);
	for (int i = 1; i <= tree->Wh_num(); i++) {
		Wh_Chain* chain = tree->Wh_list();
		INFChain zongxinxi = chain->WhC_ReInf();
		out << zongxinxi.id;
		out << "\t";
		out << zongxinxi.name;
		out << "\t";
		out << zongxinxi.sum;
		out << "\t";
		out << zongxinxi.cost;
		out << "\t";
		out << zongxinxi.profit;
		out << "\t";
		out << zongxinxi.ifseason;
		out << "\t";
		if (zongxinxi.ifseason) {
			switch (zongxinxi.season) {
			case Type_Season::Spr:
				out << "Spring";
				break;
			case Type_Season::Sum:
				out << "Summer";
				break;
			case Type_Season::Aut:
				out << "Autumn";
				break;
			case Type_Season::Win:
				out << "Winter";
				break;
			}
		}
		else {
			out << "none";
		}
		out << "\t";
		out << zongxinxi.lab << "\t";
		if (!chain->WhC_ifempty()) {
			for (int j = 0; j < chain->WhC_len(); j++) {
				INFCom picixinxi = chain->WhC_NodeInf(j);

				out << picixinxi.in_m << "\t";
				out << picixinxi.maufacter << "\t";
				out << picixinxi.in_y << "\t";
				out << picixinxi.out_m << "\t";
				out << picixinxi.out_y << "\t";
				out << picixinxi.sum << "\t";
			}
			out << '0';
		}
		out << std::endl;
	}
	out.close();
}
int storage::load() {
	pass->getUsername(username);
	int temp;
	std::ifstream in(username+".txt", std::ios::in);
	std::string empty;
	in >> empty;
	if(empty==""){
		std::cout << "���ݿ�Ϊ��" << std::endl;
		system("pause");
		system("cls");
		in.close();
		return 0;
	}
	char c[20];
	strcpy(c, empty.c_str());
	nowmon=atoi(c);
	in  >> nowyear >> tempnowseason;
	if (tempnowseason == "Spring") {
		nowsea = Type_Season::Spr;
	}
	else if (tempnowseason == "Summer") {
		nowsea = Type_Season::Sum;
	}
	else if (tempnowseason == "Autumn") {
		nowsea = Type_Season::Aut;
	}
	else if (tempnowseason == "Winter") {
		nowsea = Type_Season::Win;
	}
	mes->msg_settime(nowmon, nowyear);
	while (!in.eof()) {
		in >> id;
		in >> name;
		in >> sum;
		in >> cost;
		in >> profit;
		total = cost + profit;
		in >> ifseason;
		in >> tempseason;
		if (tempseason == "Spring") {
			seas = Type_Season::Spr;
		}
		else if (tempseason == "Summer") {
			seas = Type_Season::Sum;
		}
		else if (tempseason == "Autumn") {
			seas = Type_Season::Aut;
		}
		else if (tempseason == "Winter") {
			seas = Type_Season::Win;
		}
		in >> lab;
		Wh_Chain *chain=new Wh_Chain(id, name, lab, cost, total);
		if (ifseason) {
			chain->WhC_InitSeason(seas);
		}
		while (in >> temp && temp != 0) {
			c_date_m_in=temp;
			in >> c_maufacter;
			in >> c_date_year_in;
			in >> c_date_m;
			in >> c_date_year;
			in >> c_sum;
			Commondity com(c_maufacter, c_date_year, c_date_year_in, c_date_m, c_date_m_in, c_sum);
			chain->WhC_insert(com);
		}
		tree->Wh_BTreeInsert(chain);
	}
	in.close();
	return 1;
}