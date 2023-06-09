#pragma once
#include <iostream>

//Базовый класс
class NetworkhardWare {
private:
	std::string _model;
	double _price;

public:
	void init(std::string model, int price);
	NetworkhardWare(std::string model = "0", double price = 0);
	virtual void print();
	std::string getmodel();
	double getprice();
	void ChangeModel();
	void ChangePrice();
};