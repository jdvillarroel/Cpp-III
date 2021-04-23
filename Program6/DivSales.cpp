#include "DivSales.h"

/// <summary>
/// Initialize variables with default values.
/// </summary>
DivSales::DivSales()
{
	quarterSales[0] = 0.0;
	quarterSales[1] = 0.0;
	quarterSales[2] = 0.0;
	quarterSales[3] = 0.0;

	totalDivSales = 0.0;
}

/// <summary>
/// Set the sales of each quater.
/// </summary>
/// <param name="q1">Sales for the respective quater</param>
/// <param name="q2">Sales for the respective quater</param>
/// <param name="q3">Sales for the respective quater</param>
/// <param name="q4">Sales for the respective quater</param>
void DivSales::setQuaterSales(double q1, double q2, double q3, double q4)
{
	quarterSales[0] = q1;
	quarterSales[1] = q2;
	quarterSales[2] = q3;
	quarterSales[3] = q4;

	for (int i = 0; i < 4; i++)
	{
		totalDivSales += getQuaterSales(i);
	}

	totalCorpSales += totalDivSales;
}


/// <summary>
/// Get the sales of the respective quater
/// </summary>
/// <param name="quaterIndex">Index representing the quater</param>
/// <returns></returns>
double DivSales::getQuaterSales(int quaterIndex)
{
	return quarterSales[quaterIndex];
}


double DivSales::getDivSales(void)
{
	return totalDivSales;
}


double DivSales::getCorpSales(void)
{
	return totalCorpSales;
}