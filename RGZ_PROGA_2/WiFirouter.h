#pragma once
#include <iostream>
#include"NetworkhardWare.h"

class WiFirouter : public NetworkhardWare {
private:
	int _lanports;
	int _cores;
	void init(std::string _model, double _price, int lanports, int cores);
public:
	WiFirouter(std::string _model = "0", double _price = 0, int lanports = 0, int cores = 0);
	void print();
	int getlanports();
	int getcores();
	void ChangeLANPorts();
	void ChangeCores();
};