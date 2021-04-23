#ifndef DIVSALES_H
#define DIVSALES_H

#pragma once
class DivSales
{
private:
	double			quarterSales[4];
	double			totalDivSales;
	static double	totalCorpSales;

public:
	// Constructor
	DivSales();

	// Member functions
	void setQuaterSales(double, double, double, double);
	double getQuaterSales(int);
	double getDivSales(void);
	double getCorpSales(void);
};



#endif // !DIVSALES_H


