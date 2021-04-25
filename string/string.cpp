// Daniel Hinz
// String.cpp
// 2/24/2019

#include <cassert>
#include "string.hpp"
#include <iostream>

String::String(){
  stringSize = 1; 
  str = new char[stringSize]; 
  str[0] = 0;
}

String::String(char ch){
  stringSize = 2;
  str = new char[stringSize]; 
  str[0] = ch;
  str[1] = 0;      
}

String::String(const char ch[]){
  stringSize = 0; 
  while (ch[stringSize] != 0){
     ++stringSize;
  }
  str = new char[stringSize];
  for(int i = 0; ch[i] != 0; ++i)
    str[i] = ch[i];
  str[stringSize-1] = 0; 
}
//private function
String::String(int n) {
  if (n <= 0){
    stringSize = 1;
  } else {
    stringSize = n+1;
  } 
  str = new char[stringSize];
  str[stringSize-1] = '\0';
} 			 
//private function
String::String(int n, const char rhs[]) {
  stringSize = n + 1;
  str = new char[stringSize];
  int pos = 0;
  while(pos != n && rhs[pos] != '\0') {
    str[pos] = rhs[pos];
    ++pos;
  }
  str[pos] = 0;
}

String::~String() {
  delete [] str;
} 

String::String(const String& st) {
  stringSize = st.stringSize; 
  str = new char[stringSize];
  for (int i = 0; i < stringSize; ++i) {
    str[i] = st.str[i];
  }
  str[stringSize-1] = 0;
}

void String::swap(String& st) {
  char *tmp = str;
  str = st.str;
  st.str = tmp;
  int temp = stringSize;
  stringSize = st.stringSize;
  st.stringSize = temp;
}

String &String::operator=(String st) {
  swap(st);
  return *this;
}

String String::operator+(const String &rhs) const {
   String rtn(str);
   rtn.resetCapacity(stringSize+rhs.stringSize);
   int j = 0;
   int i = length();
   while (rhs.str[j] != 0){
      rtn.str[j+i] = rhs.str[j];
      ++j;
   }
   rtn.str[j+i] = 0;
   return rtn;
}

bool String::operator==( const String& rhs) const {
  if (length() == rhs.length()) { 
         for (int i = 0; i < length(); ++i) {
         if (str[i] != rhs.str[i]) {
            return false;
         }
      }
      return true;
   }
   return false;
}

bool operator!=(const String &lhs, const String &rhs) {
   return !(lhs.operator==(rhs)); 
}

bool String::operator<(const String &rhs) const {
   int i = 0; 
   while ((str[i] != 0) && (str[i] == rhs.str[i])) {
      ++i;
   }
   return str[i] < rhs.str[i];
}

bool operator>(const String &lhs, const String &rhs){
   return (rhs < lhs);
}

bool operator>= (const String &lhs, const String &rhs) {
   return !(lhs < rhs);
}

bool operator<= (const String &lhs, const String &rhs) {
   return !(rhs < lhs);
}

String &String::operator+=(const String &rhs) {
   *this = operator+(rhs);
   return *this;
}

char &String::operator[](int i) {
   return str[i];
}

char String::operator[](int i) const {
   return str[i];
}

int String::length() const{
   int count = 0; 
      while (str[count] != 0)
         ++count;
   return count;
}

int String::capacity() const {
   return stringSize - 1;
}

String String::substr(int start, int end) const {
   String substring;
   for (int i = start; i <= end; ++i) {
      substring[i] = str[i];
   }
   return substring;
}

int String::findch(int pos, char ch) const {
   for (int i = pos; i < stringSize; ++i) {
      if (str[i] == ch) {
         return i; 
      }
   }
   return -1;
}

int String::findstr(int pos, const String& s) const {
   for (int i = pos; i < length(); ++i) {
      if (substr(i, s.length()) == s) {
         return i;
      }
   }
   return -1;
}

String operator+(const char lhs[], const String& rhs) {
   return String(lhs) + rhs;
}

String operator+(char lhs, const String& rhs) {
   return String(lhs) + rhs;
}

bool operator==(const char lhs[], const String& rhs) {
   return String(lhs) == rhs;
}

bool operator==(char lhs, const String& rhs) {
   return String(lhs) == rhs;
}

bool operator<(const char lhs[], const String& rhs) {
   return String(lhs) < rhs;
}

bool operator<(char lhs, const String& rhs) {
   return String(lhs) < rhs;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
   out << rhs;
   return out;
}

std::istream& operator>>(std::istream& in, String &s) {
   in >> s.str;
   return in;
}

void String::resetCapacity(int n) {
  int smaller = stringSize;
  if (smaller-1 > n){
    smaller = n;
  }
  char *tmp = new char[n];
  for (int i = 0; i < smaller; ++i) {
    tmp[i] = str[i];
  }
  stringSize = n+1; 
  delete [] str;
  str = tmp; 
}

std::vector<String> String::split(char ch) const {
  std::vector<String> tmp;
  int beg = 0; 
  int end = 0;
  
  while (end != -1){
    end = findch(beg, ch);
    if (end == beg) {
      tmp.push_back("");
    } else if (end != -1) {
      tmp.push_back(substr(beg, end-1));
    }
    if (end == -1) {
      tmp.push_back(substr(beg,length()));
      std::cout << str << " " << beg << " " << end << " " << length() << std::endl;
    }
    beg = end+1;
  }
  return tmp;
}


