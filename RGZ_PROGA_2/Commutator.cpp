#include <iostream>
#include "Commutator.h"

void Commutator::init(std::string _model, double _price, int numberofports, int power) {
	NetworkhardWare::init(_model, _price);
	if (numberofports < 0 || numberofports > 200) throw std::domain_error("Количество портов коммутатора задано неверно");
	if (power < 0 || power > 500) throw std::domain_error("Мощьность коммутатора задана неверно");
	_numberofports = numberofports;
	_power = power;
}

Commutator::Commutator(std::string _model, double _price, int numberofports, double power) : NetworkhardWare{ _model, _price } {
	init(_model, _price, numberofports, power);
}

void Commutator::print() {
	std::cout << std::endl << "Коммутатор" << std::endl;
	NetworkhardWare::print();
	std::cout << "Количество портов у коммутатора: " << _numberofports << std::endl;
	std::cout << "Мощьность коммутатора: " << _power << "Вт" << std::endl;
}

void  Commutator::ChangeNumberOfPorts() {
	std::cout << "Введите новое число портов коммутатора (от 0 до 200)" << std::endl;
	std::cin >> _numberofports; if (_numberofports < 0 || _numberofports > 200) throw std::domain_error("Количество портов коммутатора задано неверно");
}

void Commutator::ChangePower() {
	std::cout << "Введите новую мощьность для коммутатора (от 0 до 500 Вт)" << std::endl;
	std::cin >> _power; if (_power < 0 || _power > 500) throw std::domain_error("Мощьность коммутатора задана неверно");
}

int Commutator::getnumberofports() {
	return _numberofports;
}

double Commutator::getpower() {
	return _power;
}