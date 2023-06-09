#include <iostream>
#include "Commutator.h"

void Commutator::init(std::string _model, double _price, int numberofports, int power) {
	NetworkhardWare::init(_model, _price);
	if (numberofports < 0 || numberofports > 200) throw std::domain_error("���������� ������ ����������� ������ �������");
	if (power < 0 || power > 500) throw std::domain_error("��������� ����������� ������ �������");
	_numberofports = numberofports;
	_power = power;
}

Commutator::Commutator(std::string _model, double _price, int numberofports, double power) : NetworkhardWare{ _model, _price } {
	init(_model, _price, numberofports, power);
}

void Commutator::print() {
	std::cout << std::endl << "����������" << std::endl;
	NetworkhardWare::print();
	std::cout << "���������� ������ � �����������: " << _numberofports << std::endl;
	std::cout << "��������� �����������: " << _power << "��" << std::endl;
}

void  Commutator::ChangeNumberOfPorts() {
	std::cout << "������� ����� ����� ������ ����������� (�� 0 �� 200)" << std::endl;
	std::cin >> _numberofports; if (_numberofports < 0 || _numberofports > 200) throw std::domain_error("���������� ������ ����������� ������ �������");
}

void Commutator::ChangePower() {
	std::cout << "������� ����� ��������� ��� ����������� (�� 0 �� 500 ��)" << std::endl;
	std::cin >> _power; if (_power < 0 || _power > 500) throw std::domain_error("��������� ����������� ������ �������");
}

int Commutator::getnumberofports() {
	return _numberofports;
}

double Commutator::getpower() {
	return _power;
}