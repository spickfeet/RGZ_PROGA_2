#include <iostream>

#include"NetworkhardWare.h"

void NetworkhardWare::init(std::string model, int price) {
	if (model == "") throw std::invalid_argument("������ ����������� �� �������");
	if (price < 0 || price > 400000000) throw std::domain_error("���� ����������� ������ �������");
	_model = model;
	_price = price;
}

NetworkhardWare::NetworkhardWare(std::string model, double price) {
	init(model, price);
}

void NetworkhardWare::print() {
	std::cout << "������: " << _model << std::endl;
	std::cout << "����: " << _price << " ������" << std::endl;
}

void NetworkhardWare::ChangeModel() {
	std::cout << "������� ����� ������" << std::endl;
	std::cin >> _model; if (_model == "") throw std::invalid_argument("������ ����������� �� �������");
}

void NetworkhardWare::ChangePrice() {
	std::cout << "������� ����� ���� (�� 0 �� 400.000.000 ������)" << std::endl;
	std::cin >> _price; if (_price < 0 || _price > 400000000) throw std::domain_error("���� ����������� ������ �������");
}

std::string NetworkhardWare::getmodel() {
	return _model;
}

double NetworkhardWare::getprice() {
	return _price;
}