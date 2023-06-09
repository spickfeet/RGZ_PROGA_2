#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <Windows.h>


#include "Commutator.h"
#include "WiFirouter.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::list<NetworkhardWare*> mylist;
	try {
		int num;
		int close = 1;
		do {
			std::cout << "1 - Добавить ещё элемент в список" << std::endl
				<< "2 - Вывести элементы списка" << std::endl
				<< "0 - закончить выполнение программы" << std::endl;
			std::cin >> close;
			if (close == 1) {
				system("cls");
				std::cout << "Объект какого класса вы хотите создать" << std::endl
					<< "1 - Oбъект базового класса NetworkhardWare" << std::endl
					<< "2 - Объект производного класса Commutator" << std::endl
					<< "3 - Объект производного класса WiFirouter" << std::endl;
				std::cin >> num;
				switch (num) {
				case 1: {
					std::string model;
					double price;
					std::cout << "Введите модель" << std::endl;
					std::cin >> model;
					std::cout << "Введите цену (от 0 до 400.000.000 рублей)" << std::endl;
					std::cin >> price;
					NetworkhardWare* q = new NetworkhardWare(model, price);
					mylist.push_back(q);
					break;
				}
				case 2: {
					std::string model;
					double price;
					int numberofports;
					double power;
					std::cout << "Введите модель" << std::endl;
					std::cin >> model;
					std::cout << "Введите цену (от 0 до 400.000.000 рублей)" << std::endl;
					std::cin >> price;
					std::cout << "Введите число портов коммутатора (от 0 до 200)" << std::endl;
					std::cin >> numberofports;
					std::cout << "Введите новую мощьность для коммутатора (от 0 до 500 Вт)" << std::endl;
					std::cin >> power;
					NetworkhardWare* q = new Commutator(model, price, numberofports, power);
					mylist.push_back(q);
					break;
				}
				case 3: {
					std::string model;
					double price;
					int lanports;
					int cores;
					std::cout << "Введите модель" << std::endl;
					std::cin >> model;
					std::cout << "Введите цену (от 0 до 400.000.000 рублей)" << std::endl;
					std::cin >> price;
					std::cout << "Введите количество LAN портов для вайфай роутера (от 0 до 8)" << std::endl;
					std::cin >> lanports;
					std::cout << "Введите количество ядер для вайфай роутера (от 0 до 4)" << std::endl;
					std::cin >> cores;
					NetworkhardWare* q = new WiFirouter(model, price, lanports, cores);
					mylist.push_back(q);
					break;
				}
				}
			}
			if (close == 2) {
				system("cls");
				for (NetworkhardWare* s : mylist) {
					s->print();
				}
			}
		} while (close);

	}
	catch (std::invalid_argument& error) {
		std::cout << error.what();
	}
	catch (std::domain_error& error) {
		std::cout << error.what();
	}
	for (NetworkhardWare* s : mylist) {
		delete s;
	}
	mylist.clear();
	_CrtDumpMemoryLeaks();
	return 0;
}


//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	try {
//		Commutator c1{ "MikroTik_CRS518-16XS-2XQ-RM", 239999, 51, 95 }, c2{ "TP-Link_TL-SF1005D", 799, 5, 1.87 }, c3{"IP-COM G1110P-8-150W", 7499, 28, 150};
//		WiFirouter w1{ "ASUS_RT-AX55", 6000, 4, 2}, w2{"TP - Link_Archer AX1800", 5000, 2, 2}, w3{"Huawei_AX3 Pro", 4000, 3, 2};
//		NetworkhardWare n1{ "Tenda_TX3", 4299 }, n2{ "TP-Link_TL-SG108E", 3199 };
//		NetworkhardWare* networkhardwareptr;
//		
//		std::cout << "------Взаимодействие с указателем на базовый класс------" << std::endl << std::endl;
//
//		std::cout << "Указатель связан с объектом базового класса";
//		networkhardwareptr = &n1;
//		networkhardwareptr->print();
//
//		std::cout << std::endl << "Указатель связан с объектом производного класса";
//		networkhardwareptr = &w1;
//		networkhardwareptr->print();
//
//		std::cout << std::endl << "------Экземпляры------" << std::endl;
//
//		c1.print();
//		c2.print();
//		c3.print();
//
//		w1.print();
//		w2.print();
//		w3.print();
//
//		n1.print();
//		n2.print();
//
//		std::cout << std::endl << "------Изменение значений полей------" << std::endl;
//		
//		c1.ChangeModel();
//		c1.ChangePrice();
//		c2.ChangePower();
//		c2.ChangeNumberOfPorts();
//
//		w1.ChangeModel();
//		w1.ChangePrice();
//		w2.ChangeLANPorts();
//		w2.ChangeCores();
//
//		n1.ChangeModel();
//		n2.ChangePrice();
//
//		std::cout << std::endl << "------Экземпляры с измененными полями------" << std::endl;
//
//		c1.print();
//		c2.print();
//
//		w1.print();
//		w2.print();
//
//		n1.print();
//		n2.print();
//
//	}
//	catch (std::invalid_argument& error) {
//		std::cout << error.what();
//	}
//	catch (std::domain_error& error) {
//		std::cout << error.what();
//	}
//
//	return 0;
//}