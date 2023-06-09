#pragma once
#include <iostream>
#include"NetworkhardWare.h"

class Commutator : public NetworkhardWare {
private:
	int _numberofports; //количество портов
	double _power;
	void init(std::string _model, double _price, int numberofports, int power);
public:
	Commutator(std::string _model = "0", double _price = 0, int numberofports = 0, double power = 0);
	void print();
	void ChangePower();
	void ChangeNumberOfPorts();
	int getnumberofports();
	double getpower();
};