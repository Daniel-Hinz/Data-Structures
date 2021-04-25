// Daniel Hinz
// CS2 Project 1
// 1/22/2019

#include <iostream>

#ifndef BIGINT_H
#define BIGINT_H

const int CAPACITY = 256;

class bigint{
public:
 	      bigint();
 	      bigint(int);
 	      bigint(const char[]);
       void   debugPrint(std::ostream&) const;
       int    operator[](int) const;
       bool   operator==(const bigint&);
       bigint operator+(const bigint&) const;
       bigint operator*(const bigint&) const;
       bigint timesDigit(int) const;
       bigint times10(int) const;
friend std::ostream& operator<<(std::ostream&, bigint&);
friend std::istream& operator>>(std::istream&,bigint&);        
private:
	int numArray[CAPACITY];	
};

#endif 
