#include <iostream>

#include"NetworkhardWare.h"

void NetworkhardWare::init(std::string model, int price) {
	if (model == "") throw std::invalid_argument("Модель коммутатора не указана");
	if (price < 0 || price > 400000000) throw std::domain_error("Цена коммутатора задана неверно");
	_model = model;
	_price = price;
}

NetworkhardWare::NetworkhardWare(std::string model, double price) {
	init(model, price);
}

void NetworkhardWare::print() {
	std::cout << "Модель: " << _model << std::endl;
	std::cout << "Цена: " << _price << " рублей" << std::endl;
}

void NetworkhardWare::ChangeModel() {
	std::cout << "Введите новую модель" << std::endl;
	std::cin >> _model; if (_model == "") throw std::invalid_argument("Модель коммутатора не указана");
}

void NetworkhardWare::ChangePrice() {
	std::cout << "Введите новую цену (от 0 до 400.000.000 рублей)" << std::endl;
	std::cin >> _price; if (_price < 0 || _price > 400000000) throw std::domain_error("Цена коммутатора задана неверно");
}

std::string NetworkhardWare::getmodel() {
	return _model;
}

double NetworkhardWare::getprice() {
	return _price;
}