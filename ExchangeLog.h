#pragma once
#include <string>

struct Exchange {
	float compra;
	float venta;
	std::string divisa_compra;
	std::string divisa_venta;
	bool type; //0: compra 1: venta

	Exchange undo() {
		return {venta, compra, divisa_venta, divisa_compra, !type};
	}
}; 
