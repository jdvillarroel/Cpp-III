#pragma once
#ifndef COUNTLETTERS_H_
#define COUNTLETTERS_H_

#include "main.h"

class CountLetters
{
private:
	int		lettersCount[128];
	int		totalLetters;

public:
	// Constructors
	CountLetters();

	// Destructor
	~CountLetters();

	// Public variables.
	int		fileNameLength;

	// Member Functions.
	void getLetters(ifstream&, char*);
	int getLetterCount(int);
	void incrementCount(int);
	void updateTotal(void);
	void printReport(ofstream&);
};




#endif // !COUNTLETTERS_H_


