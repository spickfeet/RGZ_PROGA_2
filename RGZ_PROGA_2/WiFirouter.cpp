#include <iostream>
#include "WiFirouter.h"

void WiFirouter::init(std::string _model, double _price, int lanports, int cores) {
	NetworkhardWare::init(_model, _price);
	if (lanports < 0 || lanports > 8) throw std::domain_error("Количество LAN портов вайфай роутера задано неверно");
	if (cores < 0 || cores > 4) throw std::domain_error("Количество ядер вайфай роутера задано неверно");
	_lanports = lanports;
	_cores = cores;
}

WiFirouter::WiFirouter(std::string _model, double _price, int lanports, int cores) : NetworkhardWare { _model, _price } {
	init(_model, _price, lanports, cores);
}

void WiFirouter::print() {
	std::cout << std::endl << "Вайфай роутер" << std::endl;
	NetworkhardWare::print();
	std::cout << "Количество LAN портов у вайфай роутера: " << _lanports << std::endl;
	std::cout << "Количество ядер вайфай роутера: " << _cores << std::endl << std::endl;
}

void WiFirouter::ChangeLANPorts() {
	std::cout << "Введите новое количество LAN портов для вайфай роутера (от 0 до 8)" << std::endl;
	std::cin >> _lanports; if (_lanports < 0 || _lanports > 8) throw std::domain_error("Количество LAN портов вайфай роутера задано неверно");
}

void WiFirouter::ChangeCores() {
	std::cout << "Введите новое количество ядер для вайфай роутера (от 0 до 4)" << std::endl;
	std::cin >> _cores; if (_cores < 0 || _cores > 4) throw std::domain_error("Количество ядер вайфай роутера задано неверно");
}

int WiFirouter::getlanports() {
	return _lanports;
}
int WiFirouter::getcores() {
	return _cores;
}
