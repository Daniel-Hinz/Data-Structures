// Daniel Hinz
// utilities.cpp

#include "utilities.hpp"

std::string toPostfix(std::string infix){
  std::vector<std::string> exp = infix.split(' ');
  stack<std::string> s;

  for (int i = 0; i < exp.size() - 1; ++i) {
    if (exp[i] == ")") {
      std::string rhs = s.pop();
      std::string op = s.pop();
      std::string lhs = s.pop();

      s.push(lhs + " " + rhs + " " + op);
    }
    else
      if (exp[i] != "(")
        s.push(exp[i]);
  }
  return s.pop();
}

std::string toAssembler(std::string postfix, std::ofstream& out) {
  std::vector<std::string> exp = postfix.split(' ');
  stack<std::string> s;

  int n = 1;
  
  for (int i = 0; i < exp.size(); ++i) {
    std::string t = exp[i];
    if (t!- "+" && t != "-" && t != "*" && t != "/")
      s.push(t);
    else {
      std::string right = s.pop();
      std::string left = s.pop();
      std::string remp = evaluate(left,t,right,n,out);
      s.push(temp);
      ++n;
    }
  }
  return s.pop()
}

std::string evaluate(std::string left,std::string t, std::string right, int num, std::ofstream& out){
  std::string n = toString(num);
  
  if (out){
    out << "LD\t" << left << '\n';

    if (t == '+')
      out << "AD\t";
    if (t == '-')
      out << "SB\t";
    if (t == '*')
      out << "MU\t";
    if (t == '/')
      out << "DV\t";

    out << right + '\n';
    out << "ST\tTMP" << num << '\n';
  }
  else {
    std::cout << "LD\t" << left << '\n';
    
    if (t == '+')
      std::cout << "AD\t";
    if (t == '-')
      std::cout << "SB\t";
    if (t == '*')
      std::cout << "MU\t";
    if (t == '/')
      std::cout << "DV\t";

    std::cout << right + '\n';
    std::cout << "ST\tTMP" << num << '\n';
  }
  return "TMP" + n;
}

std::string toString(int n){
  std::string dig[10] = {"0","1","2","3","4","5","6","7","8","9"};
  std::string ret;

  while (n>0){
    ret = dig[n%10] + ret;
    n /= 10;
  }
  return ret;
}
