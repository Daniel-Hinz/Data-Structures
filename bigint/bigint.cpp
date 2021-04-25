// Daniel Hinz
// CS2 Project 1
// 1/23/2019

#include <iostream>
#include <fstream>
#include "bigint.hpp"

bigint::bigint(){
     for (int i = 0; i < CAPACITY; ++i){
           numArray[i] = 0;
     }
}

bigint::bigint(int num) :bigint(){
      int i = 0; 
      while (num != 0) {
           numArray[i] = num % 10;
           num /= 10;
	   ++i;
      }	
}

bigint::bigint(const char num[]) :bigint(){
  int counter = 0;
  while (num[counter] != '\0'){
    ++counter;
  }
  for(int i = 0; i < counter; ++i) {   
      numArray[i] = num[counter - 1 - i] - '0';
  }
}

void bigint::debugPrint(std::ostream& os) const{
      for (int i = CAPACITY - 1; i != -1; --i){
          os << numArray[i] << "|";
      }
}

std::ostream& operator<<(std::ostream& out, bigint& rhs){
      bool zeroCheck = true;
      int lineCount = 0;

      if (rhs == 0){
         out << 0; 
         return out;
      }

      for (int i = CAPACITY-1; i != -1; --i) {
          if (zeroCheck &&  rhs.numArray[i] != 0){
             zeroCheck = false;
          }
          if (!zeroCheck) {
             out << rhs.numArray[i];
             ++lineCount;
          }
          if (lineCount == 80) {
             out << "\n";
             lineCount = 0;
          }
      }
      return out;
}

bool bigint::operator==(const bigint& rhs) {
     for (int i = 0; i < CAPACITY; ++i) {
         if (numArray[i] != rhs.numArray[i]){
         return false;
         }
     }
     return true;
}

std::istream& operator>>(std::istream& in, bigint& rhs) {
     char digits, tmp[CAPACITY];
     for (int j = 0; j < CAPACITY; ++j){
          tmp[j]=0;
     }
     in >> digits;
     if (!in.eof()){
          for (int i = 0; i < CAPACITY && digits != ';'; ++i) {
               tmp[i] = digits;
               in >> digits;
          }
          rhs = bigint(tmp);
     }
     return in;
}

bigint bigint::operator+(const bigint& rhs) const{
     bigint result;
     int carry = 0;
     for (int i = 0; i < CAPACITY; ++i) {
          if (numArray[i] + rhs.numArray[i] + carry > 9){
               int number = numArray[i] + rhs.numArray[i] + carry;
	       carry = 1;
	       number = number % 10;
	       result.numArray[i] = number;
          }
          else {
	       result.numArray[i] = numArray[i] + rhs.numArray[i] + carry;
	       carry = 0;  
	  }  
     }
     return result;
}

int bigint::operator[](int i) const{
     if (i >= CAPACITY) {
          return 0;
     }
     else {
          return numArray[i];
     }
}

bigint bigint::timesDigit(int i) const {
     bigint num;
     int right = 0; int result = 0;
     for (int j = 0; j < CAPACITY; ++j) {
         right = numArray[j]*i+right;
         result = right%10;
         right /= 10;
         num.numArray[j] = result;
     }
     return num;
}

bigint bigint::times10(int i) const {
     bigint num;
     for (int j = CAPACITY-1-i; j >= 0; --j) {
          num.numArray[j+i] = numArray[j];
     }
     for (int k = 0; k < i; ++k) {
          num.numArray[k] = 0;
     }
     return num;
}

bigint bigint::operator* (const bigint& rhs) const {
     bigint product = 0; 
     for (int i = 0; i < CAPACITY-1; ++i) {
         product = product + (timesDigit(rhs.numArray[i])).times10(i);
     }
     return product;
}
