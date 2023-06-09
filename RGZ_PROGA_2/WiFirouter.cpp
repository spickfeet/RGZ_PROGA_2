#include <iostream>
#include "WiFirouter.h"

void WiFirouter::init(std::string _model, double _price, int lanports, int cores) {
	NetworkhardWare::init(_model, _price);
	if (lanports < 0 || lanports > 8) throw std::domain_error("���������� LAN ������ ������ ������� ������ �������");
	if (cores < 0 || cores > 4) throw std::domain_error("���������� ���� ������ ������� ������ �������");
	_lanports = lanports;
	_cores = cores;
}

WiFirouter::WiFirouter(std::string _model, double _price, int lanports, int cores) : NetworkhardWare { _model, _price } {
	init(_model, _price, lanports, cores);
}

void WiFirouter::print() {
	std::cout << std::endl << "������ ������" << std::endl;
	NetworkhardWare::print();
	std::cout << "���������� LAN ������ � ������ �������: " << _lanports << std::endl;
	std::cout << "���������� ���� ������ �������: " << _cores << std::endl << std::endl;
}

void WiFirouter::ChangeLANPorts() {
	std::cout << "������� ����� ���������� LAN ������ ��� ������ ������� (�� 0 �� 8)" << std::endl;
	std::cin >> _lanports; if (_lanports < 0 || _lanports > 8) throw std::domain_error("���������� LAN ������ ������ ������� ������ �������");
}

void WiFirouter::ChangeCores() {
	std::cout << "������� ����� ���������� ���� ��� ������ ������� (�� 0 �� 4)" << std::endl;
	std::cin >> _cores; if (_cores < 0 || _cores > 4) throw std::domain_error("���������� ���� ������ ������� ������ �������");
}

int WiFirouter::getlanports() {
	return _lanports;
}
int WiFirouter::getcores() {
	return _cores;
}
